<?php
/**
 * @file
 * ucsf_imported_calendar_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ucsf_imported_calendar_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ucsf_imported_calendar_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Imported Calendar Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_imported_cal_event_date']['id'] = 'field_imported_cal_event_date';
  $handler->display->display_options['fields']['field_imported_cal_event_date']['table'] = 'field_data_field_imported_cal_event_date';
  $handler->display->display_options['fields']['field_imported_cal_event_date']['field'] = 'field_imported_cal_event_date';
  $handler->display->display_options['fields']['field_imported_cal_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_imported_cal_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imported_cal_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_imported_cal_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_imported_cal_event_date']['delta_offset'] = '0';
  /* Sort criterion: Content: Date -  start date (field_imported_cal_event_date) */
  $handler->display->display_options['sorts']['field_imported_cal_event_date_value']['id'] = 'field_imported_cal_event_date_value';
  $handler->display->display_options['sorts']['field_imported_cal_event_date_value']['table'] = 'field_data_field_imported_cal_event_date';
  $handler->display->display_options['sorts']['field_imported_cal_event_date_value']['field'] = 'field_imported_cal_event_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'imported_calendar_event' => 'imported_calendar_event',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '4',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'imported_calendar_event_source_feed';
  /* Filter criterion: Start Date */
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['id'] = 'field_imported_cal_event_date_value';
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['table'] = 'field_data_field_imported_cal_event_date';
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['field'] = 'field_imported_cal_event_date_value';
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['ui_name'] = 'Start Date';
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imported_cal_event_date_value']['default_date'] = 'now';

  /* Display: Featured Events Block */
  $handler = $view->new_display('block', 'Featured Events Block', 'ucsf_featured_events_block');
  $translatables['ucsf_imported_calendar_events'] = array(
    t('Master'),
    t('Featured Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Featured Events Block'),
  );
  $export['ucsf_imported_calendar_events'] = $view;

  return $export;
}
