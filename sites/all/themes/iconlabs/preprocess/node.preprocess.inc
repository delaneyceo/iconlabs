<?php

/**
 * Implements hook_preprocess_node().
 */
function iconlabs_preprocess_node(&$variables) {

  if ($variables['view_mode'] ==  'featured_slideshow') {
    // Get the image path and pass it to the view mode temlate file.
    $img_path = file_create_url($variables['field_image'][LANGUAGE_NONE][0]['uri']);
    $variables['img_path'] = $img_path;

    // Get the url and pass it to the view mode template file
    if (!empty($variables['field_link_single'][LANGUAGE_NONE][0]['url'])) {
      $link_path = $variables['field_link_single'][LANGUAGE_NONE][0]['url'];
    } else {
      $link_path = NULL;
    }
    $variables['link_path'] = $link_path;
  }
}
