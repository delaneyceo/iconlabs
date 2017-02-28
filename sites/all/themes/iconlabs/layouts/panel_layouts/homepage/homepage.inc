<?php

/**
 * @file
 */

// Plugin definition.
$plugin = array(
  'title' => t('Homepage'),
  'icon' => 'preview.png',
  'category' => t('Iconlabs'),
  'theme' => 'homepage',
  'css' => '../../../css/layouts/homepage/homepage.layout.css',
  'regions' => array(
    'first' => t('Header Sidebar'),
    'second' => t('Header Content'),
    'third' => t('Content'),
  ),
);

/**
 * Implements hook_preprocess_golden().
 */
function template_preprocess_homepage(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-homepage';
  $variables['attributes_array']['class'][] = 'panel-display--homepage';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'homepage-region';
    $variables['region_attributes_array'][$name]['class'][] = 'homepage-region--' . drupal_clean_css_identifier($name);
  }
}
