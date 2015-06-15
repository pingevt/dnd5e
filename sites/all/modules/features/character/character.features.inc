<?php
/**
 * @file
 * character.features.inc
 */

/**
 * Implements hook_views_api().
 */
function character_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function character_image_default_styles() {
  $styles = array();

  // Exported image style: dd5_character_thumbnail.
  $styles['dd5_character_thumbnail'] = array(
    'label' => 'Character thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
