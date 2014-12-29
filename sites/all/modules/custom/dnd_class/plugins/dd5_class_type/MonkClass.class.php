<?php

class MonkClass extends CharClass {
  public $description = "A master of martial arts, harnessing the power of the body in pursuit of physical and spiritual perfection";

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

  public function getMartialArts($lvl = NULL) {
    $martial_arts = array(
      0 => '1d4',
      1 => '1d4',
      2 => '1d4',
      3 => '1d4',
      4 => '1d6',
      5 => '1d6',
      6 => '1d6',
      7 => '1d6',
      8 => '1d6',
      9 => '1d6',
      10 => '1d8',
      11 => '1d8',
      12 => '1d8',
      13 => '1d8',
      14 => '1d8',
      15 => '1d8',
      16 => '1d10',
      17 => '1d10',
      18 => '1d10',
      19 => '1d10',
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $martial_arts[($lvl -1)];
    }

    return $martial_arts;
  }

  public function getKiPoints($lvl = NULL) {
    $ki_points = array(
      0 => 0,
      1 => 2,
      2 => 3,
      3 => 4,
      4 => 5,
      5 => 6,
      6 => 7,
      7 => 8,
      8 => 9,
      9 => 10,
      10 => 11,
      11 => 12,
      12 => 13,
      13 => 14,
      14 => 15,
      15 => 16,
      16 => 17,
      17 => 18,
      18 => 19,
      19 => 20,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $ki_points[($lvl -1)];
    }

    return $ki_points;
  }

  public function getUnarmoredMovement($lvl = NULL) {
    $unarmored_movement = array(
      0 => 0,
      1 => 10,
      2 => 10,
      3 => 10,
      4 => 10,
      5 => 15,
      6 => 15,
      7 => 15,
      8 => 15,
      9 => 20,
      10 => 20,
      11 => 20,
      12 => 20,
      13 => 25,
      14 => 25,
      15 => 25,
      16 => 25,
      17 => 30,
      18 => 30,
      19 => 30,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $unarmored_movement[($lvl -1)];
    }

    return $unarmored_movement;
  }
}
