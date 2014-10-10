<?php
/**
 * @file
 * ucsf_imported_calendar_events.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ucsf_imported_calendar_events_taxonomy_default_vocabularies() {
  return array(
    'imported_calendar_event_source_feed' => array(
      'name' => 'Source Feed',
      'machine_name' => 'imported_calendar_event_source_feed',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
