<?php

class Spell extends Entity {
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
}

class SpellController extends EntityAPIController {
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    return $build;

  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new) && $entity->is_new) {
      $entity->created = time();
      $entity->updated = $entity->created;
    }
    else {
      $entity->updated = time();
    }

    parent::save($entity, $transaction);

  }
}

class SpellUIController extends EntityDefaultUIController {

  public function __construct($entity_type, $entity_info) {
    parent::__construct($entity_type, $entity_info);

    $this->type_path = $this->entityInfo['admin ui']['type path'];
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

    $items[$this->type_path] = array(
      'title' => 'Spell bundles',
      'description' => 'Bundles for Spells',
      'page callback'  => 'drupal_get_form',
      'page arguments'  => array('spell_type_page'),
      'access callback'  => 'spell_entity_access',
      'access arguments' => array('view'),
      'file' => 'dd5_spell.pages.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 10,
    );

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'description' => 'Add a new ' . $this->entityType,
      'page callback'  => 'spell_add_page',
      'access callback'  => 'spell_entity_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'dd5_spell.pages.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_LOCAL_ACTION,
    );

    // Add menu items to add each different type of entity.
    foreach ($this->entityInfo['bundles'] as $type => $bundle_info) {
      $items[$this->type_path . '/' . $type] = array(
        'title' => $type,
        'type' => MENU_NORMAL_ITEM,
        'access callback' => TRUE,
      );

      $items[$this->path . '/add/' . $type] = array(
        'title callback' => 'entity_ui_get_action_title',
        'title arguments' => array('add', $this->entityType, $type),
        'page callback' => 'entity_ui_get_form',
        'page arguments' => array($this->entityType, entity_create('spell', array('type' => $type)), 'add'),
        'access callback' => 'entity_access',
        'access arguments' => array('create', $this->entityType),
        'type' => MENU_LOCAL_ACTION,
      );
    }

    return $items;
  }


  /**
   * Create the markup for the add Model Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('spell_add_list', array('content' => $content));
  }

  /**
   * Builds the entity overview form.
   */
  public function typeOverviewForm($form, &$form_state) {
    // By default just show a simple overview for all entities.
    $form['table'] = $this->typeOverviewTable();
    $form['pager'] = array('#theme' => 'pager');
    return $form;
  }

  /**
   * Overview form validation callback.
   *
   * @param $form
   *   The form array of the overview form.
   * @param $form_state
   *   The overview form state which will be used for validating.
   */
  public function typeOverviewFormValidate($form, &$form_state) {}

  /**
   * Overview form submit callback.
   *
   * @param $form
   *   The form array of the overview form.
   * @param $form_state
   *   The overview form state which will be used for submitting.
   */
  public function typeOverviewFormSubmit($form, &$form_state) {}


  /**
   * Generates the render array for a overview table for arbitrary entities
   * matching the given conditions.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().

   * @return Array
   *   A renderable array.
   */
  public function typeOverviewTable($conditions = array()) {

    $rows = array();
    foreach ($this->entityInfo['bundles'] as $type => $bundle_info) {
      $rows[] = $this->typeOverviewTableRow($type, $bundle_info);
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->typeOverviewTableHeaders($conditions, $rows),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }

  /**
   * Generates the table headers for the overview table.
   */
  protected function typeOverviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $header = $additional_header;

    array_unshift($header, t('Label'));

    // Add operations with the right colspan.
    $header[] = array('data' => t('Operations'), 'colspan' => $this->typeOperationCount());
    return $header;
  }

  /**
   * Returns the operation count for calculating colspans.
   */
  protected function typeOperationCount() {
    $count = 3;
    return $count;
  }

  /**
   * Generates the row for the passed entity and may be overridden in order to
   * customize the rows.
   *
   * @param $additional_cols
   *   Additional columns to be added after the entity label column.
   */
  protected function typeOverviewTableRow($type, $bundle_info) {

    $row[] = $bundle_info['label'];
    $row[] = l(t('manage fields'), $this->type_path . '/' . $type . '/fields');
    $row[] = l(t('manage fields'), $this->type_path . '/' . $type . '/dependencies');
    $row[] = l(t('manage display'), $this->type_path . '/' . $type . '/display');

    return $row;
  }
}

function spell_form($form, &$form_state, $entity, $op = 'edit', $entity_type = NULL) {
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

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published?'),
    '#weight' => -9
  );

  if (isset($entity->status) && $entity->status == TRUE) {
    $form['status']['#attributes']['checked'] = 'checked';
  }

  // Add fields
  field_attach_form('spell', $entity, $form, $form_state);

  $form['#entity'] = $entity;

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['#validate'] = array('spell_form_validate');
  $form['#submit'] = array('spell_form_submit');
  return $form;

}

function spell_form_validate($form, &$form_state) {
  $entity = $form['#entity'];
  field_attach_form_validate($entity->entityType(), $entity, $form, $form_state);

}

function spell_form_submit($form, &$form_state) {
  $entity = $form['#entity'];
  entity_form_submit_build_entity($entity->entityType(), $entity, $form, $form_state);
  $entity->is_revision = TRUE;
  entity_save($entity->entityType(), $entity);

}
