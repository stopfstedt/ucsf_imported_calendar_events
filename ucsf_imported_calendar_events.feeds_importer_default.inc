<?php
/**
 * @file
 * ucsf_imported_calendar_events.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ucsf_imported_calendar_events_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ucsf_academic_events';
  $feeds_importer->config = array(
    'name' => 'UCSF Academic Events',
    'description' => 'Academic events from calendar.ucsf.edu',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
        'indefinite_message_display' => 0,
        'until_not_utc' => 0,
        'skip_days' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '604800',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'DTEND',
            'target' => 'field_imported_cal_event_date:end',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'DTSTART',
            'target' => 'field_imported_cal_event_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'URL',
            'target' => 'field_imported_cal_event_src_url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'LOCATION',
            'target' => 'field_imported_cal_event_locatn',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Blank source 1',
            'target' => 'field_imported_cal_event_srcfeed',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'imported_calendar_event',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ucsf_academic_events'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ucsf_featured_events';
  $feeds_importer->config = array(
    'name' => 'UCSF Featured Events',
    'description' => 'Featured events from calendar.ucsf.edu',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
        'indefinite_message_display' => 0,
        'until_not_utc' => 0,
        'skip_days' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '604800',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'DTEND',
            'target' => 'field_imported_cal_event_date:end',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'DTSTART',
            'target' => 'field_imported_cal_event_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'URL',
            'target' => 'field_imported_cal_event_src_url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'LOCATION',
            'target' => 'field_imported_cal_event_locatn',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Blank source 1',
            'target' => 'field_imported_cal_event_srcfeed',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'imported_calendar_event',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['ucsf_featured_events'] = $feeds_importer;

  return $export;
}
