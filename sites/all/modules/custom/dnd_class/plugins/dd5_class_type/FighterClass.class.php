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
}
