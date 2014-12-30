<?php

class DNDRace {

  public $size;

  public function racialTraits() {
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
}