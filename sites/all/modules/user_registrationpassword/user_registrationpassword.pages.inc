<?php

/**
 * @file
 * User page callback file for the user_registrationpassword module.
 */

/**
 * Menu callback; process one time login link and redirects to the user page on success.
 */
function user_registrationpassword_confirm_account($form, &$form_state, $uid, $timestamp, $hashed_pass) {
  global $user;

  // When processing the one-time login link, we have to make sure that a user
  // isn't already logged in.
  if ($user->uid) {
    // The existing user is already logged in.
    if ($user->uid == $uid) {
      drupal_set_message(t('You are logged in as %user. <a href="!user_edit">Change your password.</a>', array('%user' => $user->name, '!user_edit' => url("user/$user->uid/edit"))));
    }
    // A different user is already logged in on the computer.
    else {
      $reset_link_account = user_load($uid);
      if (!empty($reset_link_account)) {
        drupal_set_message(t('Another user (%other_user) is already logged into the site on this computer, but you tried to use a one-time link for user %resetting_user. Please <a href="!logout">logout</a> and try using the link again.',
          array('%other_user' => $user->name, '%resetting_user' => $reset_link_account->name, '!logout' => url('user/logout'))));
      }
      else {
        // Invalid one-time link specifies an unknown user.
        drupal_set_message(t('The one-time login link you clicked is invalid.'));
      }
    }
    drupal_goto();
  }
  else {
    // Time out, in seconds, until login URL expires. 24 hours = 86400 seconds.
    $timeout = 86400;
    $current = REQUEST_TIME;
    // Some redundant checks for extra security ?
    $users = user_load_multiple(array($uid), array('status' => '0'));
    if ($timestamp <= $current && $account = reset($users)) {
      // No time out for first time login.
      if ($account->login && $current - $timestamp > $timeout) {
        drupal_set_message(t('You have tried to use a one-time login link that has expired. Please request a new one using the form below.'));
        drupal_goto('user/password');
      }
      elseif ($account->uid && $timestamp >= $account->login && $timestamp <= $current && $hashed_pass == user_pass_rehash($account->pass, $timestamp, $account->login)) {
        watchdog('user', 'User %name used one-time login link at time %timestamp.', array('%name' => $account->name, '%timestamp' => $timestamp));
        // Activate the user.
        $account = user_save($account, array('status' => 1));
        // Set the new user.
        $user = $account;
        // user_login_finalize() also updates the login timestamp of the
        // user, which invalidates further use of the one-time login link.
        user_login_finalize();

        // SEND Email to user validator aka PIA @DIPEN
        sendUserRegisterMailAfterValidation();
        // End of Email sending @DIPEN
        drupal_set_message(t('You have just used your one-time login link. Your account is now active.'));
        drupal_goto('user');
      }
      else {
        drupal_set_message(t('You have tried to use a one-time login link that has either been used or is no longer valid. Please request a new one using the form below.'));
        drupal_goto('user/password');
      }
    }
    else {
      // Deny access, no more clues.
      // Everything will be in the watchdog's URL for the administrator to check.
      drupal_access_denied();
    }
  }
}


function sendUserRegisterMailAfterValidation(){

    $user = $GLOBALS['user'];
    $to = "Pia.Oellinger@fh-hagenberg.at";    
    $subject = "A new user has registered at T[H]INKER";

    $message = "
    <html>
    <head>
    <title>User Registration</title>
    </head>
    <body>
    <p>A new user, <b>". $user->name. "</b> has registered at T[H]INKER.</p>
    Please follow the link given below to check the ". $user->name."'s profile.<br/>
    <a href = 'http://t-h-inker.net/user/".$user->uid."'>Check user's Profile</a>
    <h2>T[H]INKER</h2>
    </body>
    </html>
    ";

    // Always set content-type when sending HTML email
    $headers = "MIME-Version: 1.0" . "\r\n";
    $headers .= "Content-type:text/html;charset=iso-8859-1" . "\r\n";

    // More headers
    $headers .= 'From: <info@thinker.net' . "\r\n";
    $headers .= 'Bcc: dipen.hamal@metropolia.fi' . "\r\n";

    mail($to,$subject,$message,$headers);
}