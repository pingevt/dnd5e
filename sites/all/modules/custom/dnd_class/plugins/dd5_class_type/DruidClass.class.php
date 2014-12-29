<?php

class DruidClass extends CharClass {
  public $description = "A priest of the Olf Faith, weilding the powers of nature - moonlight and plant growth, fire and lightening - and adopting animal forms.";

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

  public function getSpellSlots() {

    $spell_slots = array(
      0 => array(
        '1' => 2,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      1 => array(
        '1' => 2,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      2 => array(
        '1' => 4,
        '2' => 2,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      3 => array(
        '1' => 4,
        '2' => 3,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      4 => array(
        '1' => 3,
        '2' => 3,
        '3' => 2,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      5 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      6 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 1,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      7 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 2,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      8 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 1,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      9 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      10 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      11 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      12 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 1,
        '8' => 0,
        '9' => 0,
      ),
      13 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 1,
        '8' => 0,
        '9' => 0,
      ),
      14 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 1,
        '8' => 1,
        '9' => 0,
      ),
      15 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 1,
        '8' => 1,
        '9' => 0,
      ),
      16 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 2,
        '6' => 1,
        '7' => 1,
        '8' => 1,
        '9' => 1,
      ),
      17 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 3,
        '6' => 1,
        '7' => 1,
        '8' => 1,
        '9' => 1,
      ),
      18 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 3,
        '6' => 2,
        '7' => 1,
        '8' => 1,
        '9' => 1,
      ),
      19 => array(
        '1' => 4,
        '2' => 3,
        '3' => 3,
        '4' => 3,
        '5' => 3,
        '6' => 2,
        '7' => 2,
        '8' => 1,
        '9' => 1,
      ),
    );

    return $spell_slots;
  }

  public function getCantripsKnown($lvl = NULL) {
    $cantrips_known = array(
      0 => 2,
      1 => 2,
      2 => 2,
      3 => 3,
      4 => 3,
      5 => 3,
      6 => 3,
      7 => 3,
      8 => 3,
      9 => 4,
      10 => 4,
      11 => 4,
      12 => 4,
      13 => 4,
      14 => 4,
      15 => 4,
      16 => 4,
      17 => 4,
      18 => 4,
      19 => 4,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $cantrips_known[($lvl -1)];
    }

    return $cantrips_known;
  }
}