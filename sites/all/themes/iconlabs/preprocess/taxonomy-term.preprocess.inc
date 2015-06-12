<?php

/**
 * Implements hook_preprocess_page().
 */
function iconlabs_preprocess_taxonomy_term(&$variables) {

  switch ($variables['vocabulary_machine_name']) {
    case 'product_family':
      if ($variables['elements']['#view_mode'] == 'product_family_listing') {

        // Execute an EFQ for the products with the product_family tid.
        $query = new EntityFieldQuery();
        $result = $query
          ->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'product')
          ->propertyCondition('status', NODE_PUBLISHED)
          ->fieldCondition('field_product_family', 'tid', $variables['tid'], '=')
          ->execute();
        $result = array_keys($result['node']);

        // Load the product nodes.
        $product_nodes = node_load_multiple($result);

        // Loop through the product nodes.
        foreach ($product_nodes as $nid => $node) {
          // Generate item markup for the product_glyphs_markup render array.
          $product_glyphs[] = array(
            'data' => '<i class="fa ' . $node->field_icon[LANGUAGE_NONE][0]['safe_value'] . '"></i>',
            'id' => 'product-glyph-nid-' . $node->nid,
            'class' => array('product_glyph')
          );
          // Generate item markup for the product_listing_markup render array.
          $product_link_listing[] = array(
            'data' => '<a href="/node/' . $node->nid . '" title="' . $node->title . '"><i class="fa ' . $node->field_icon[LANGUAGE_NONE][0]['safe_value'] . '"></i>' . $node->title . '</a>',
            'id' => 'product_listing-nid' . $node->nid,
            'class' => array('product_listing')
          );
        }

        // Set render attributes for the product ul.
        $render_ul = 'ul';
        $product_glyph_render_attributes = array(
          'id' => 'product_family_product_glyphs',
          'class' => 'product_family_product_glyphs',
        );
        $product_listing_render_attributes = array(
          'id' => 'product_family_product_listing',
          'class' => 'product_family_product_listing',
        );

        // Render an UL of the glyphs using font-awesome markup.
        $product_glyph_markup = theme_item_list(array(
          'items' => $product_glyphs,
          'type' => $render_ul,
          'attributes' => $product_glyph_render_attributes
        ));
        // Render an UL of the product listing using font-awesome markup.
        $product_listing_markup = theme_item_list(array(
          'items' => $product_link_listing,
          'type' => $render_ul,
          'attributes' => $product_listing_render_attributes
        ));

        // Add to the variables array.
        $variables['product_glyph_markup'] = $product_glyph_markup;
        $variables['product_listing_markup'] = $product_listing_markup;
      }
      break;

  }
}
