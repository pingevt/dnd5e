<?php

class CharClass extends Entity implements EntityBundlePluginProvideFieldsInterface, EntityBundlePluginValidableInterface {

  public $description = '';
  public $casts_spells = TRUE;

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);
  }

  protected function defaultLabel() {
    return $this->name;
  }

  // EntityBundlePluginProvideFieldsInterface
  static function fields() {
    $fields = array();

    return $fields;
  }

  // EntityBundlePluginValidableInterface
  public static function isValid() {
    return TRUE;
  }

  public function getProficiencyBonus($lvl = NULL) {
    $bonus = array(
      0 => 0,
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $bonus[($lvl -1)];
    }

    return $bonus;
  }

  public function getCantripsKnown($lvl = NULL) {
    $cantrips_known = array(
      0 => 0,
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $cantrips_known[($lvl -1)];
    }

    return $cantrips_known;
  }

  public function getSpellsKnown($lvl = NULL) {
    $spells_known = array(
      0 => 0,
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $spells_known[($lvl -1)];
    }

    return $spells_known;
  }

  public function getSpellSlots($lvl = NULL) {
    $spell_slots = array(
      0 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      1 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      2 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      3 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      4 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      5 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      6 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      7 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      8 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      9 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      10 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      11 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      12 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      13 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      14 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      15 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      16 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      17 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      18 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      19 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $spell_slots[($lvl -1)];
    }

    return $spell_slots;
  }

  // Fighter
  public function getRages($lvl = NULL) {
    $rages = array(
      0 => 0,
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      16 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $rages[($lvl -1)];
    }

    return $rages;
  }

  // Monk
  public function getMartialArts($lvl = NULL) {
    $martial_arts = array(
      0 => '1d4',
      1 => '1d4',
      2 => '1d4',
      3 => '1d4',
      4 => '1d6',
      5 => '1d6',
      6 => '1d6',
      7 => '1d6',
      8 => '1d6',
      9 => '1d6',
      10 => '1d8',
      11 => '1d8',
      12 => '1d8',
      13 => '1d8',
      14 => '1d8',
      15 => '1d8',
      16 => '1d10',
      17 => '1d10',
      18 => '1d10',
      19 => '1d10',
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $martial_arts[($lvl -1)];
    }

    return $martial_arts;
  }

  // Monk
  public function getKiPoints($lvl = NULL) {
    $ki_points = array(
      0 => 0,
      1 => 2,
      2 => 3,
      3 => 4,
      4 => 5,
      5 => 6,
      6 => 7,
      7 => 8,
      8 => 9,
      9 => 10,
      10 => 11,
      11 => 12,
      12 => 13,
      13 => 14,
      14 => 15,
      15 => 16,
      16 => 17,
      17 => 18,
      18 => 19,
      19 => 20,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $ki_points[($lvl -1)];
    }

    return $ki_points;
  }

  // Monk
  public function getUnarmoredMovement($lvl = NULL) {
    $unarmored_movement = array(
      0 => 0,
      1 => 10,
      2 => 10,
      3 => 10,
      4 => 10,
      5 => 15,
      6 => 15,
      7 => 15,
      8 => 15,
      9 => 20,
      10 => 20,
      11 => 20,
      12 => 20,
      13 => 25,
      14 => 25,
      15 => 25,
      16 => 25,
      17 => 30,
      18 => 30,
      19 => 30,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $unarmored_movement[($lvl -1)];
    }

    return $unarmored_movement;
  }

  // Rogue
  public function getSneakAttack($lvl = NULL) {
    $sneak_attack = array(
      0 => '0',
      1 => '0',
      2 => '0',
      3 => '0',
      4 => '0',
      5 => '0',
      6 => '0',
      7 => '0',
      8 => '0',
      9 => '0',
      10 => '0',
      11 => '0',
      12 => '0',
      13 => '0',
      14 => '0',
      15 => '0',
      16 => '0',
      17 => '0',
      18 => '0',
      19 => '0',
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $sneak_attack[($lvl -1)];
    }

    return $sneak_attack;
  }

  // Sorcerer
  public function getSorceryPoints($lvl = NULL) {
    $sorcery_points = array(
      0 => 0,
      1 => 2,
      2 => 3,
      3 => 4,
      4 => 5,
      5 => 6,
      6 => 7,
      7 => 8,
      8 => 9,
      9 => 10,
      10 => 11,
      11 => 12,
      12 => 13,
      13 => 14,
      14 => 15,
      15 => 16,
      16 => 17,
      17 => 18,
      18 => 19,
      19 => 20,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $sorcery_points[($lvl -1)];
    }

    return $sorcery_points;
  }

}

class CharClassController extends EntityBundlePluginEntityController {
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    return $build;
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new) && $entity->is_new) {
      global $user;
      $entity->uid = $user->uid;
      $entity->created = time();
      $entity->updated = $entity->created;
    }
    else {
      $entity->updated = time();
    }

    parent::save($entity, $transaction);

  }
}

class CharClassUIController extends BundleUIController {

  public function __construct($entity_type, $entity_info) {
    parent::__construct($entity_type, $entity_info);
  }


  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = parent::hook_menu();

    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;
    $plural_label = isset($this->entityInfo['plural label']) ? $this->entityInfo['plural label'] : $this->entityInfo['label'] . 's';

    $items['class/%class'] = array(
      'page callback'  => 'class_page_view',
      'page arguments'  => array(1, 'full'),
      'access callback'  => 'dd5_entity_access',
      'access arguments' => array('view', 1, NULL, $this->entityType, strtolower($plural_label)),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 10,
    );

    return $items;
  }
}

function class_page_view($character, $view_mode) {
  $controller = entity_get_controller('character');
  $content = $controller->view(array($character->char_id => $character));
  drupal_set_title($character->name);
  return $content;
}

function class_form($form, &$form_state, $entity, $op = 'edit', $entity_type = NULL) {
  $entity_info = entity_get_info($entity->entityType());
  $property_info = entity_get_property_info($entity->entityType());

  list(, , $bundle) = entity_extract_ids('spell', $entity);

  if (isset($entity_info['entity keys']['label'])) {
    $label_key = $entity_info['entity keys']['label'];
    if (isset($property_info['bundles'][$bundle]['properties'][$label_key])) {
      $property = $property_info['bundles'][$bundle]['properties'][$label_key];
    }
    elseif (isset($property_info['properties'][$label_key])) {
      $property = $property_info['properties'][$label_key];
    }

    $label_key_title = isset($property['label']) ? $property['label'] : t('Name');

    $form[$label_key] = array(
      '#type' => 'textfield',
      '#title' => check_plain($label_key_title),
      '#required' => isset($property['required']) ? $property['required'] : TRUE,
      '#default_value' => isset($entity->$label_key) ? $entity->$label_key : NULL,
      '#weight' => -10,
    );
  }

  // Add fields
  field_attach_form('class', $entity, $form, $form_state);

  $form['#entity'] = $entity;

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['#validate'] = array('class_form_validate');
  $form['#submit'] = array('class_form_submit');
  return $form;

}

function class_form_validate($form, &$form_state) {
  $entity = $form['#entity'];
  field_attach_form_validate($entity->entityType(), $entity, $form, $form_state);

}

function class_form_submit($form, &$form_state) {
  $entity = $form['#entity'];
  entity_form_submit_build_entity($entity->entityType(), $entity, $form, $form_state);
  $entity->is_revision = TRUE;
  entity_save($entity->entityType(), $entity);

  $form_state['redirect'] = 'admin/dnd5/class/manage';
}
