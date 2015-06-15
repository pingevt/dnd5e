<?php

class Character extends Entity {

  static function spell_data_default() {
    return array(
      'prepared' => array(),
      'cast' => array(),
    );
  }

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

  function getLvl() {
    if (isset($this->field_char_level[LANGUAGE_NONE][0]['value'])) {
      return (int) $this->field_char_level[LANGUAGE_NONE][0]['value'];
    }

    return FALSE;
  }

  function getCharClass() {
    if (isset($this->field_char_class[LANGUAGE_NONE][0]['target_id'])) {
      $char_class = current(entity_load('class', array($this->field_char_class[LANGUAGE_NONE][0]['target_id'])));

      return $char_class;
    }

    return FALSE;
  }

  function prepareSpell($spell_id) {

    $current_spells = array($spell_id);
    foreach ($this->field_spells_prepared[LANGUAGE_NONE] as $item) {
      $current_spells[] = $item['value'];
    }
    unset($this->field_spells_prepared[LANGUAGE_NONE]);

    $current_spells = array_unique($current_spells, SORT_NUMERIC);
    sort($current_spells, SORT_NUMERIC);

    foreach($current_spells as $spell_id) {
      $this->field_spells_prepared[LANGUAGE_NONE][] = array('value' => $spell_id);
    }

    // Update field
    $field_name = 'field_spells_prepared';
    $info = field_info_field($field_name);
    $fields = array($info['id']);

    field_sql_storage_field_storage_write('character', $this, 'update', $fields);
  }

  function unprepareSpell($spell_id) {

    foreach ($this->field_spells_prepared[LANGUAGE_NONE] as $item) {
      $current_spells[] = $item['value'];
    }
    unset($this->field_spells_prepared[LANGUAGE_NONE]);

    $current_spells = array_unique($current_spells, SORT_NUMERIC);
    sort($current_spells, SORT_NUMERIC);

    // remove item
    $current_spells = array_diff($current_spells, array($spell_id));

    foreach($current_spells as $spell_id) {
      $this->field_spells_prepared[LANGUAGE_NONE][] = array('value' => $spell_id);
    }

    // Update field
    $field_name = 'field_spells_prepared';
    $info = field_info_field($field_name);
    $fields = array($info['id']);

    field_sql_storage_field_storage_write('character', $this, 'update', $fields);
  }

  function getSpells($options = array()) {
    $options += array(
      'filter' => FALSE,
      'order' => FALSE,
    );

    $spells = array();

    $q = db_select('field_data_field_spell_groups', 'sg');
    $q->join('field_data_field_sg_always_prepared', 'prep', 'prep.entity_id = sg.field_spell_groups_target_id');
    $q->rightJoin('field_data_field_spells', 's', 'sg.field_spell_groups_target_id = s.entity_id');
    $q->join('dd5_spell', 'sp', 's.field_spells_target_id = sp.spell_id');
    $q->leftJoin('field_data_field_spells_prepared', 'sprep', 'sprep.field_spells_prepared_value = sp.spell_id');

    $q->fields('sprep', array('field_spells_prepared_value'));
    $q->fields('sp', array('spell_id'));
    $q->fields('sg', array('field_spell_groups_target_id'));
    $q->fields('prep', array('field_sg_always_prepared_value'));

    $q->condition('sg.entity_id', $this->char_id);
    $q->condition('sp.status', 1);

    if ($options['filter']) {
      switch($options['filter']) {
      case 'prepared':
        $q->condition('sprep.field_spells_prepared_value', 0, '!=');
        break;
      }
    }

    if ($options['order']) {
      switch($options['order']) {
      case 'spell_lvl':
        $q->leftJoin('field_data_field_spell_level', 'splvl', 'sp.spell_id = splvl.entity_id');
        $alias = $q->addField('splvl', 'field_spell_level_value', 'spell_level');
        $q->orderBy('splvl.field_spell_level_value', 'ASC');
        $q->orderBy('sp.name', 'ASC');
        break;
      case 'alpha_asc':
        $q->orderBy('sp.name', 'ASC');
        break;
      case 'alpha_desc':
        $q->orderBy('sp.name', 'DESC');
        break;
      }
    }

    $spell_return = $q->execute()->fetchAll();

    foreach($spell_return as $s) {
      $loaded_spell = current(entity_load('spell', array($s->spell_id)));
      $spell_group = current(entity_load('spell_group', array($s->field_spell_groups_target_id)));

      if (isset($spells[$s->spell_id])) {
        $spells[$s->spell_id]->spell_group_title[] = $spell_group->name;

        if ($spell_group->field_sg_always_prepared[LANGUAGE_NONE][0]['value'] == TRUE) {
          $spells[$s->spell_id]->always_prepared = TRUE;
        }
      }
      else {
        $loaded_spell->spell_group_title[] = $spell_group->name;
        if ($spell_group->field_sg_always_prepared[LANGUAGE_NONE][0]['value'] == TRUE) {
          $loaded_spell->always_prepared = TRUE;
        }
        else {
          $loaded_spell->always_prepared = FALSE;
        }

        if ($s->field_spells_prepared_value != 0 && !empty($s->field_spells_prepared_value)) {
          $loaded_spell->prepared = TRUE;
        }
        else {
          $loaded_spell->prepared = FALSE;
        }

        $spells[$s->spell_id] = $loaded_spell;
      }
    }

    return $spells;
  }

  function getSpellData() {
    if (isset($this->field_spell_data[LANGUAGE_NONE][0]['value'])) {
      return unserialize($this->field_spell_data[LANGUAGE_NONE][0]['value']);
    }
    else {
      return Character::spell_data_default();
    }
  }

  function saveSpellData($spell_data) {
    $this->field_spell_data[LANGUAGE_NONE][0]['value'] = serialize($spell_data);
    $this->save();
  }

  function getSpellSlots() {

    if ($char_class = $this->getCharClass()) {
      return $char_class->getSpellSlotsArray();
    }

    return FALSE;

  }

}

class CharacterController extends EntityAPIController {
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

class CharacterUIController extends BundleUIController {

  public function __construct($entity_type, $entity_info) {
    parent::__construct($entity_type, $entity_info);
  }


  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = parent::hook_menu();

    $items['character/%character'] = array(
      'page callback'  => 'character_page_view',
      'page arguments'  => array(1, 'full'),
      'access callback'  => 'dd5_entity_access',
      'access arguments' => array('view', 1, NULL, 'character', 'characters'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 10,
    );

    return $items;
  }

  /**
   * Generates the table headers for the overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $header = $additional_header;
    array_unshift($header, t(''), t('Label'), t('level'));
    if (!empty($this->entityInfo['exportable'])) {
      $header[] = t('Status');
    }
    // Add operations with the right colspan.
    $header[] = array('data' => t('Operations'), 'colspan' => $this->operationCount());
    return $header;
  }

  /**
   * Generates the row for the passed entity and may be overridden in order to
   * customize the rows.
   *
   * @param $additional_cols
   *   Additional columns to be added after the entity label column.
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    $entity_uri = entity_uri($this->entityType, $entity);

    if (isset($entity->field_char_image[LANGUAGE_NONE][0])) {
      $img = field_view_value($this->entityType, $entity, 'field_char_image', $entity->field_char_image[LANGUAGE_NONE][0], array('label' => 'hidden', 'settings' => array('image_style' => 'dd5_character_thumbnail')));
      $row[] = render($img);
    }
    else {
      $row[] = array();
    }

    $row[] = array('data' => array(
      '#theme' => 'entity_ui_overview_item',
      '#label' => entity_label($this->entityType, $entity),
      '#name' => !empty($this->entityInfo['exportable']) ? entity_id($this->entityType, $entity) : FALSE,
      '#url' => $entity_uri ? $entity_uri : FALSE,
      '#entity_type' => $this->entityType),
    );

    if (isset($entity->field_char_level[LANGUAGE_NONE][0])) {
      $img = field_view_value($this->entityType, $entity, 'field_char_level', $entity->field_char_level[LANGUAGE_NONE][0], array('label' => 'hidden'));
      $row[] = render($img);
    }
    else {
      $row[] = array();
    }


    // Add in any passed additional cols.
    foreach ($additional_cols as $col) {
      $row[] = $col;
    }

    // Add a row for the exportable status.
    if (!empty($this->entityInfo['exportable'])) {
      $row[] = array('data' => array(
        '#theme' => 'entity_status',
        '#status' => $entity->{$this->statusKey},
      ));
    }
    // In case this is a bundle, we add links to the field ui tabs.
    $field_ui = !empty($this->entityInfo['bundle of']) && entity_type_is_fieldable($this->entityInfo['bundle of']) && module_exists('field_ui');
    // For exportable entities we add an export link.
    $exportable = !empty($this->entityInfo['exportable']);
    // If i18n integration is enabled, add a link to the translate tab.
    $i18n = !empty($this->entityInfo['i18n controller class']);

    // Add operations depending on the status.
    if (entity_has_status($this->entityType, $entity, ENTITY_FIXED)) {
      $row[] = array('data' => l(t('clone'), $this->path . '/manage/' . $id . '/clone'), 'colspan' => $this->operationCount());
    }
    else {
      $row[] = l(t('edit'), $this->path . '/manage/' . $id);

      if ($field_ui) {
        $row[] = l(t('manage fields'), $this->path . '/manage/' . $id . '/fields');
        $row[] = l(t('manage display'), $this->path . '/manage/' . $id . '/display');
      }
      if ($i18n) {
        $row[] = l(t('translate'), $this->path . '/manage/' . $id . '/translate');
      }
      if ($exportable) {
        $row[] = l(t('clone'), $this->path . '/manage/' . $id . '/clone');
      }

      if (empty($this->entityInfo['exportable']) || !entity_has_status($this->entityType, $entity, ENTITY_IN_CODE)) {
        $row[] = l(t('delete'), $this->path . '/manage/' . $id . '/delete', array('query' => drupal_get_destination()));
      }
      elseif (entity_has_status($this->entityType, $entity, ENTITY_OVERRIDDEN)) {
        $row[] = l(t('revert'), $this->path . '/manage/' . $id . '/revert', array('query' => drupal_get_destination()));
      }
      else {
        $row[] = '';
      }
    }
    if ($exportable) {
      $row[] = l(t('export'), $this->path . '/manage/' . $id . '/export');
    }
    return $row;
  }

}

function character_page_view($character, $view_mode) {
  $controller = entity_get_controller('character');
  $content = $controller->view(array($character->char_id => $character));
  drupal_set_title($character->name);
  return $content;
}

function character_form($form, &$form_state, $entity, $op = 'edit', $entity_type = NULL) {
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
  field_attach_form('character', $entity, $form, $form_state);

  $form['#entity'] = $entity;

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['#validate'] = array('character_form_validate');
  $form['#submit'] = array('character_form_submit');
  return $form;

}

function character_form_validate($form, &$form_state) {
  $entity = $form['#entity'];
  field_attach_form_validate($entity->entityType(), $entity, $form, $form_state);

}

function character_form_submit($form, &$form_state) {
  $entity = $form['#entity'];
  entity_form_submit_build_entity($entity->entityType(), $entity, $form, $form_state);
  $entity->is_revision = TRUE;
  entity_save($entity->entityType(), $entity);

  $form_state['redirect'] = 'admin/dnd5/character/manage';
}
