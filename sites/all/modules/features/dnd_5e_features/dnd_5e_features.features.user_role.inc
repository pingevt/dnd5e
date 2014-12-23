<?php
/**
 * @file
 * dnd_5e_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dnd_5e_features_user_default_roles() {
  $roles = array();

  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => 5,
  );

  // Exported role: D&D Admin.
  $roles['D&D Admin'] = array(
    'name' => 'D&D Admin',
    'weight' => 4,
  );

  // Exported role: D&D Editor.
  $roles['D&D Editor'] = array(
    'name' => 'D&D Editor',
    'weight' => 3,
  );

  // Exported role: D&D Player.
  $roles['D&D Player'] = array(
    'name' => 'D&D Player',
    'weight' => 2,
  );

  return $roles;
}
