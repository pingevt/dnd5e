<?php

function spell_add_page() {
  $controller = entity_ui_controller('spell');
  return $controller->addPage();
}

function spell_type_page($form, &$form_state) {
  $controller = entity_ui_controller('spell');
  return $controller->typeOverviewForm($form, $form_state);
}