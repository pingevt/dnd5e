<?php

function dd5_spell_admin_content($form, &$form_state) {
  $form = array();

  $form['markup'] = array(
    '#markup' => 'HI',
  );

  return $form;
}

function dd5_spell_group_admin_content($form, &$form_state) {
  $form = array();

  $form['markup'] = array(
    '#markup' => 'HI2',
  );

  return $form;
}