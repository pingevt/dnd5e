<?php

class WarlockClass extends CharClass {
  public $description = "A weilder of magic that is derived from a bargain with an extraplanar entity.";

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

  public function getSpellsKnown($lvl = NULL) {
    $spells_known = array(
      0 => 2,
      1 => 3,
      2 => 4,
      3 => 5,
      4 => 6,
      5 => 7,
      6 => 8,
      7 => 9,
      8 => 10,
      9 => 10,
      10 => 11,
      11 => 11,
      12 => 12,
      13 => 12,
      14 => 13,
      15 => 13,
      16 => 14,
      17 => 14,
      18 => 15,
      19 => 15,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $spells_known[($lvl -1)];
    }

    return $spells_known;
  }

  public function getSpellSlots($lvl = NULL) {
    $spell_slots = array(
      0 => array(
        '1' => 1,
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
        '1' => 0,
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
        '1' => 0,
        '2' => 2,
        '3' => 0,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      4 => array(
        '1' => 0,
        '2' => 0,
        '3' => 2,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      5 => array(
        '1' => 0,
        '2' => 0,
        '3' => 2,
        '4' => 0,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      6 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 2,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      7 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 2,
        '5' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      8 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 2,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      9 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 2,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      10 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      11 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      12 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      13 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      14 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      15 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 3,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      16 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 4,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      17 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 4,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      18 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 4,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
      19 => array(
        '1' => 0,
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '5' => 4,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
      ),
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $spell_slots[($lvl -1)];
    }

    return $spell_slots;
  }

  public function getInvocationsKnown($lvl = NULL) {
    $invocations_known = array(
      0 => 0,
      1 => 2,
      2 => 2,
      3 => 2,
      4 => 3,
      5 => 3,
      6 => 4,
      7 => 4,
      8 => 5,
      9 => 5,
      10 => 5,
      11 => 6,
      12 => 6,
      13 => 6,
      14 => 7,
      15 => 7,
      16 => 7,
      17 => 8,
      18 => 8,
      19 => 8,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $invocations_known[($lvl -1)];
    }

    return $invocations_known;
  }
}
