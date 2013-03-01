<?php

// Plugin definition
$plugin = array(
  'title' => t('Two columns with 3:1 ratio, stacked'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_3to1.png',
  'theme' => 'twocol_3to1',
  'css' => 'twocol_3to1.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
