<?php
/**
 * @file
 * ucsf_imported_calendar_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ucsf_imported_calendar_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ucsf_imported_calendar_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ucsf_imported_calendar_events_node_info() {
  $items = array(
    'imported_calendar_event' => array(
      'name' => t('Imported Calendar Event'),
      'base' => 'node_content',
      'description' => t('Calendar event added from feed.'),
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
  );
  return $items;
}
