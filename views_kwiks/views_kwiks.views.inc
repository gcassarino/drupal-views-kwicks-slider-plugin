<?php

/**
 * Implements hook_views_plugins().
 */
function views_kwiks_views_plugins() {
  return array(
    'style' => array(
      'kwiks' => array(
        'title' => t('Kwiks'),
        'help' => t('Display the results using Mottie Kwiks.'),
        'handler' => 'views_kwiks_plugin_style_kwiks',
        'theme' => 'views_kwiks',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}


