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
  }


  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = parent::hook_menu();

    return $items;
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
