<?php

class BarbarianClass extends CharClass {
  public $description = "A fierce warrior of primitive background who can enter a battle rage.";
  public $casts_spells = FALSE;

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
      0 => 2,
      1 => 2,
      2 => 2,
      3 => 2,
      4 => 3,
      5 => 3,
      6 => 3,
      7 => 3,
      8 => 4,
      9 => 4,
      10 => 4,
      11 => 4,
      12 => 5,
      13 => 5,
      14 => 5,
      15 => 5,
      16 => 6,
      17 => 6,
      18 => 6,
      19 => 6,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $bonus[($lvl -1)];
    }

    return $bonus;
  }

  public function getRageInfo($lvl = NULL) {
    $rages = array(
      0 => array(
        'rage' => 2,
        'dmg' => 2,
      ),
      1 => array(
        'rage' => 2,
        'dmg' => 2,
      ),
      2 => array(
        'rage' => 3,
        'dmg' => 2,
      ),
      3 => array(
        'rage' => 3,
        'dmg' => 2,
      ),
      4 => array(
        'rage' => 3,
        'dmg' => 2,
      ),
      5 => array(
        'rage' => 4,
        'dmg' => 2,
      ),
      6 => array(
        'rage' => 4,
        'dmg' => 2,
      ),
      7 => array(
        'rage' => 4,
        'dmg' => 2,
      ),
      8 => array(
        'rage' => 4,
        'dmg' => 3,
      ),
      9 => array(
        'rage' => 4,
        'dmg' => 3,
      ),
      10 => array(
        'rage' => 4,
        'dmg' => 3,
      ),
      11 => array(
        'rage' => 5,
        'dmg' => 3,
      ),
      12 => array(
        'rage' => 5,
        'dmg' => 3,
      ),
      13 => array(
        'rage' => 5,
        'dmg' => 3,
      ),
      14 => array(
        'rage' => 5,
        'dmg' => 3,
      ),
      15 => array(
        'rage' => 5,
        'dmg' => 4,
      ),
      16 => array(
        'rage' => 6,
        'dmg' => 4,
      ),
      17 => array(
        'rage' => 6,
        'dmg' => 4,
      ),
      18 => array(
        'rage' => 6,
        'dmg' => 4,
      ),
      19 => array(
        'rage' => -1,
        'dmg' => 4,
      ),
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $rages[($lvl -1)];
    }

    return $rages;
  }
}