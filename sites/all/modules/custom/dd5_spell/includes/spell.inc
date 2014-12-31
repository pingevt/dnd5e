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

  public function returnLvl() {
    if (isset($this->field_spell_level[LANGUAGE_NONE][0]['value']) && is_numeric($this->field_spell_level[LANGUAGE_NONE][0]['value'])) {
      return (int) $this->field_spell_level[LANGUAGE_NONE][0]['value'];
    }

    return 0;
  }

  public function getSpellType() {
    if (isset($this->field_spell_type[LANGUAGE_NONE][0]['value'])) {
      return $this->field_spell_type[LANGUAGE_NONE][0]['value'];
    }
    return NULL;
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

class SpellUIController extends BundleUIController {

  public function __construct($entity_type, $entity_info) {
    parent::__construct($entity_type, $entity_info);

    $this->overviewPagerLimit = 50;
  }

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = parent::hook_menu();

    $items['spell/%spell'] = array(
      'page callback'  => 'spell_page_view',
      'page arguments'  => array(1, 'full'),
      'access callback'  => 'dd5_entity_access',
      'access arguments' => array('view', 1, NULL, 'spell', 'spells'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 10,
    );

    return $items;
  }


  /**
   * Generates the render array for a overview table for arbitrary entities
   * matching the given conditions.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().

   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    // Add in sorting.
    if (isset($_GET['sort']) && isset($_GET['order'])) {
      switch ($_GET['order']) {
      case 'Name':
        $query->propertyOrderBy('name', strtoupper($_GET['sort']));
        break;
      case 'Level':
        $query->fieldOrderBy('field_spell_level', 'value', strtoupper($_GET['sort']));
        break;
      case 'Type':
        $query->fieldOrderBy('field_spell_type', 'value', strtoupper($_GET['sort']));
        break;
      }
    }
    // Default to name, ASC
    else {
      $query->propertyOrderBy('name', 'ASC');
    }


    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();
    //ksort($entities);

    $rows = array();
    foreach ($entities as $entity) {
      $lvl = $entity->returnLvl();

      $additional_cols = array(
        ($lvl == 0)? 'Cantrip' : $lvl,
        $entity->getSpellType(),
      );
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity, $additional_cols);
    }

    // Additional headers.
    $order = array(
      'desc' => 'asc',
      'asc' => 'desc',
    );
    $additional_headers = array(
      array(
        'data' => 'Level',
        'field' => 'level',
        'sort' => (isset($_GET['order']) && $_GET['order'] == 'Level')? strtoupper($order[$_GET['sort']]) : 'ASC',
      ),
      array(
        'data' => 'Type',
        'field' => 'type',
        'sort' => (isset($_GET['order']) && $_GET['order'] == 'Type')? strtoupper($order[$_GET['sort']]) : 'ASC',
      )
    );

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows, $additional_headers),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }

  /**
   * Generates the table headers for the overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $order = array(
      'desc' => 'asc',
      'asc' => 'desc',
    );

    $header = $additional_header;
    array_unshift($header, array(
      'data' => 'Name',
      'field' => 'name',
      'sort' => (isset($_GET['order']) && $_GET['order'] == 'Name')? strtoupper($order[$_GET['sort']]) : 'DESC',
    ));
    if (!empty($this->entityInfo['exportable'])) {
      $header[] = t('Status');
    }
    // Add operations with the right colspan.
    $header[] = array('data' => t('Operations'), 'colspan' => $this->operationCount());
    return $header;
  }
}

function spell_page_view($spell, $view_mode) {
  $controller = entity_get_controller('spell');
  $content = $controller->view(array($spell->spell_id => $spell));
  drupal_set_title($spell->name);
  return $content;
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

  $form_state['redirect'] = 'admin/dnd5/spells/manage';
}
