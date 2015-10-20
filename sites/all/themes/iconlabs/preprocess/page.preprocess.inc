<?php

/**
 * Implements hook_preprocess_page().
 */
function iconlabs_preprocess_page(&$variables) {
  // Format a current timestamp with the year.
  $year = format_date(time(), 'custom', 'Y');
  $variables['year'] = $year;
}
