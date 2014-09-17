<?php

/**
 * Implements hook_preprocess_node().
 */
function iconlabs_preprocess_node(&$variables) {

  if ($variables['view_mode'] ==  'featured_slideshow') {
    $img_path = file_create_url($variables['field_image'][LANGUAGE_NONE][0]['uri']);
    $variables['img_path'] = $img_path;
  }
}
