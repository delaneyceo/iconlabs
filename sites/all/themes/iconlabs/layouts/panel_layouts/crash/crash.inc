<?php

/**
 * @file
 */

// Plugin definition.
$plugin = array(
  'title' => t('Crash'),
  'icon' => 'preview.png',
  'category' => t('Iconlabs'),
  'theme' => 'crash',
  'css' => '../../../css/layouts/crash/crash.layout.css',
  'regions' => array(
    'first' => t('Content'),
    'second' => t('Sidebar'),
  ),
);

/**
 * Implements hook_preprocess_golden().
 */
function template_preprocess_crash(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-crash';
  $variables['attributes_array']['class'][] = 'panel-display--crash';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'crash-region';
    $variables['region_attributes_array'][$name]['class'][] = 'crash-region--' . drupal_clean_css_identifier($name);
  }
}
