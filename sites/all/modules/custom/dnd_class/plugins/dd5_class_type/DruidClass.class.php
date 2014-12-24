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

  public function getSpellSlotsArray() {

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

    return $spell_slots;
  }
}