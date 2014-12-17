<?php
/**
 * @file
 * character.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function character_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_characters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dd5_character';
  $view->human_name = 'My characters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Characters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Character: Character ID */
  $handler->display->display_options['fields']['char_id']['id'] = 'char_id';
  $handler->display->display_options['fields']['char_id']['table'] = 'dd5_character';
  $handler->display->display_options['fields']['char_id']['field'] = 'char_id';
  /* Field: Character: Image */
  $handler->display->display_options['fields']['field_char_image']['id'] = 'field_char_image';
  $handler->display->display_options['fields']['field_char_image']['table'] = 'field_data_field_char_image';
  $handler->display->display_options['fields']['field_char_image']['field'] = 'field_char_image';
  $handler->display->display_options['fields']['field_char_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_char_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_char_image']['settings'] = array(
    'image_style' => 'dd5_character_thumbnail',
    'image_link' => '',
  );
  /* Field: Character: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dd5_character';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'character/[char_id]';
  /* Field: Character: Level */
  $handler->display->display_options['fields']['field_char_level']['id'] = 'field_char_level';
  $handler->display->display_options['fields']['field_char_level']['table'] = 'field_data_field_char_level';
  $handler->display->display_options['fields']['field_char_level']['field'] = 'field_char_level';
  /* Contextual filter: Character: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'dd5_character';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'my-characters';
  $export['my_characters'] = $view;

  return $export;
}
