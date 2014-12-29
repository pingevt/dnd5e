<?php

class FighterClass extends CharClass {
  public $description = "A master of martial combat, skilled with a variety of weapons and armor.";

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
}
