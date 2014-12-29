<?php

class RogueClass extends CharClass {
  public $description = "A schoundrel who uses stealth and trickery to overcome obstacles and enemies.";

  // EntityBundlePluginProvideFieldsInterface
  static function fields() {
    $fields = array();

    return $fields;
  }

  // EntityBundlePluginValidableInterface
  public static function isValid() {
    return TRUE;
  }

  public function getSpellSlots($lvl = NULL) {

    $spell_slots = array(
      0 => array(
        'proficiency_bonus' => 2,
        'cantrips known' => 3,
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
        'proficiency_bonus' => 2,
        'cantrips known' => 3,
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
        'proficiency_bonus' => 2,
        'cantrips known' => 3,
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
        'proficiency_bonus' => 2,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 3,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 3,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 3,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 3,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 4,
        'cantrips known' => 4,
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
        'proficiency_bonus' => 4,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 4,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 4,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 5,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 5,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 5,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 5,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 6,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 6,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 6,
        'cantrips known' => 5,
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
        'proficiency_bonus' => 6,
        'cantrips known' => 5,
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

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $spell_slots[($lvl -1)];
    }

    return $spell_slots;
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

  public function getSneakAttack($lvl = NULL) {
    $sneak_attack = array(
      0 => '1d6',
      1 => '1d6',
      2 => '2d6',
      3 => '2d6',
      4 => '3d6',
      5 => '3d6',
      6 => '4d6',
      7 => '4d6',
      8 => '5d6',
      9 => '5d6',
      10 => '6d6',
      11 => '6d6',
      12 => '7d6',
      13 => '7d6',
      14 => '8d6',
      15 => '8d6',
      16 => '9d6',
      17 => '9d6',
      18 => '10d6',
      19 => '10d6',
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $sneak_attack[($lvl -1)];
    }

    return $sneak_attack;
  }
}
