<?php
/**
 * @file
 * ucsf_imported_calendar_events.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ucsf_imported_calendar_events_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'ucsf_featured_events-blank_source_1-ucsf_featured_events_taxonomy';
  $feeds_tamper->importer = 'ucsf_featured_events';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Featured Events',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['ucsf_featured_events-blank_source_1-ucsf_featured_events_taxonomy'] = $feeds_tamper;

  return $export;
}
