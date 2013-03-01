
(function ($) {
 
  Drupal.behaviors.sky = {
    attach: function(context, settings) {
 
$('#block-save-settings-save-settings-form-block', context).hoverIntent({
        over: function () {
          $(this).find('.block-content').slideDown('fast', 'easeInCubic');
          $(this).find('.block-content').css('max-height','100%');
          $(this).find('.block-content').css('background-color','white');
        },
        out: function () {
          $(this).find('.block-content').slideUp('fast', 'easeInCubic');
          $(this).find('.block-content').css('max-height','0%');
        },
        timeout: 500
      });


     $('#block-save-settings-save-settings-content-block', context).hoverIntent({
        over: function () {
          $(this).find('.block-content').slideDown('fast', 'easeInCubic');
        },
        out: function () {
          $(this).find('.block-content').slideUp('fast', 'easeInCubic');
        },
        timeout: 500
      });

          $('.pane-save-settings-save-settings-content-block', context).hoverIntent({
        over: function () {
          $(this).find('.pane-content').slideDown('fast', 'easeInCubic');
        },
        out: function () {
          $(this).find('.pane-content').slideUp('fast', 'easeInCubic');
        },
        timeout: 500
      });


      $('#block-system-main-menu .expanded .expanded', context).hoverIntent({
        over: function () {
          $(this).find('.menu').slideDown('fast', 'easeInCubic');
        },
        out: function () {
          $(this).find('.menu').slideUp('fast', 'easeInCubic');
        },
        timeout: 500
      });

       $('.pane-system-main-menu .expanded .expanded', context).hoverIntent({
        over: function () {
          $(this).find('.menu').slideDown('fast', 'easeInCubic');
        },
        out: function () {
          $(this).find('.menu').slideUp('fast', 'easeInCubic');
        },
        timeout: 500
      });



     //  $("#block-save-settings-save-settings-content-block", context).click(function() {
      //  $(this).find('.block-content').toggle(2000, 'easeInOutElastic');
      //  $(this).find('.block-content').animate({"left": -($(id).position().left)},200, 'easeInOutElastic');
      //  $(this).find('.block-content').slideDown('fast', 'easeInCubic');    
     // });

  }
  }
})(jQuery);
