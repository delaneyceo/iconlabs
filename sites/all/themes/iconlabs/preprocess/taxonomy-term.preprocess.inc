<?php

/**
 * Implements hook_preprocess_page().
 */
function iconlabs_preprocess_taxonomy_term(&$variables) {
  if ($variables['vocabulary_machine_name'] == 'product_type') {
    $nodes = taxonomy_select_nodes($variables['tid']);
    foreach ($nodes as $nid) {
      $node = node_load($nid);
      $variables['icons'][] = $node->field_icon[LANGUAGE_NONE][0]['safe_value'];
    }
  }
}
