<?php

class DNDRace {

  public $size;

  public function racialTraits($char = NULL) {
    return array();
  }

  public function racialTraitDefaults($traits = array()) {

    // Add in defaults.
    foreach ($traits as &$trait) {
      $trait = array_replace_recursive(array(
        'name' => t(''),
        'descr' => t(''),
        'hooks' => array(
          'form' => FALSE,
          'ability_score' => FALSE,
          'hit_point' => FALSE,
          'speed' => FALSE,
          'proficiency' => FALSE,
          'language' => FALSE,
          'racial_traits' => FALSE,
        ),
        'show on char sheet' => FALSE,
        'char cheet section' => '',
      ), $trait);
    }

    return $traits;
  }

  public function checkTraitDependencies($char) {
    $traits = $this->racialTraits($char);
    $race_data = $char->getRaceData();

    foreach ($traits as $trait_id => $trait) {
      if ($trait['hooks']['form'] == TRUE && !isset($race_data[$trait_id])) {
        return FALSE;
      }
    }

    return TRUE;
  }

  public function racialAbilityScoreIncrease() {
    return array(
      'strength' => 0,
      'dexterity' => 0,
      'constitution' => 0,
      'intelligence' => 0,
      'wisdom' => 0,
      'charisma' => 0,
    );
  }

  public function characterForm($form, &$form_state, &$char) {
    $traits = $this->racialTraits($char);

    foreach ($traits as $trait_id => $trait) {
      if ($trait['hooks']['form'] == TRUE) {
        $func = $trait_id . '_form';
        if (method_exists($this, $func)) {
          $form = $this->$func($form, $form_state, $char);
        }
        else {
          drupal_set_message('Method does not exist: ' . $func, 'warning', TRUE);
        }
      }
    }

    return $form;
  }
}