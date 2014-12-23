<?php
/**
 * @file
 * dnd_5e_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dnd_5e_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access dd5 administration pages'.
  $permissions['access dd5 administration pages'] = array(
    'name' => 'access dd5 administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Admin' => 'D&D Admin',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5',
  );

  // Exported permission: 'administer dd5'.
  $permissions['administer dd5'] = array(
    'name' => 'administer dd5',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Admin' => 'D&D Admin',
    ),
    'module' => 'dd5',
  );

  // Exported permission: 'administer dnd characters'.
  $permissions['administer dnd characters'] = array(
    'name' => 'administer dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Admin' => 'D&D Admin',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'administer dnd classes'.
  $permissions['administer dnd classes'] = array(
    'name' => 'administer dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Admin' => 'D&D Admin',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'administer dnd spells'.
  $permissions['administer dnd spells'] = array(
    'name' => 'administer dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Admin' => 'D&D Admin',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'create dnd characters'.
  $permissions['create dnd characters'] = array(
    'name' => 'create dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'create dnd classes'.
  $permissions['create dnd classes'] = array(
    'name' => 'create dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'create dnd spells'.
  $permissions['create dnd spells'] = array(
    'name' => 'create dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'delete all dnd characters'.
  $permissions['delete all dnd characters'] = array(
    'name' => 'delete all dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'delete all dnd classes'.
  $permissions['delete all dnd classes'] = array(
    'name' => 'delete all dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'delete all dnd spells'.
  $permissions['delete all dnd spells'] = array(
    'name' => 'delete all dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'delete own dnd characters'.
  $permissions['delete own dnd characters'] = array(
    'name' => 'delete own dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'delete own dnd classes'.
  $permissions['delete own dnd classes'] = array(
    'name' => 'delete own dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'delete own dnd spells'.
  $permissions['delete own dnd spells'] = array(
    'name' => 'delete own dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'edit all dnd characters'.
  $permissions['edit all dnd characters'] = array(
    'name' => 'edit all dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'edit all dnd classes'.
  $permissions['edit all dnd classes'] = array(
    'name' => 'edit all dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'edit all dnd spells'.
  $permissions['edit all dnd spells'] = array(
    'name' => 'edit all dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'edit own dnd characters'.
  $permissions['edit own dnd characters'] = array(
    'name' => 'edit own dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'edit own dnd classes'.
  $permissions['edit own dnd classes'] = array(
    'name' => 'edit own dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'edit own dnd spells'.
  $permissions['edit own dnd spells'] = array(
    'name' => 'edit own dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'use dnd spell manager'.
  $permissions['use dnd spell manager'] = array(
    'name' => 'use dnd spell manager',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_spell_manager',
  );

  // Exported permission: 'view all dnd characters'.
  $permissions['view all dnd characters'] = array(
    'name' => 'view all dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Editor' => 'D&D Editor',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'view all dnd classes'.
  $permissions['view all dnd classes'] = array(
    'name' => 'view all dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'view all dnd spells'.
  $permissions['view all dnd spells'] = array(
    'name' => 'view all dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'view own dnd characters'.
  $permissions['view own dnd characters'] = array(
    'name' => 'view own dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'view own dnd classes'.
  $permissions['view own dnd classes'] = array(
    'name' => 'view own dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'view own dnd spells'.
  $permissions['view own dnd spells'] = array(
    'name' => 'view own dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_spell',
  );

  // Exported permission: 'view own unpublished dnd characters'.
  $permissions['view own unpublished dnd characters'] = array(
    'name' => 'view own unpublished dnd characters',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_character',
  );

  // Exported permission: 'view own unpublished dnd classes'.
  $permissions['view own unpublished dnd classes'] = array(
    'name' => 'view own unpublished dnd classes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_class',
  );

  // Exported permission: 'view own unpublished dnd spells'.
  $permissions['view own unpublished dnd spells'] = array(
    'name' => 'view own unpublished dnd spells',
    'roles' => array(
      'Administrator' => 'Administrator',
      'D&D Player' => 'D&D Player',
    ),
    'module' => 'dd5_spell',
  );

  return $permissions;
}
