<?php

class RangerClass extends CharClass {
  public $description = "A warrior who uses martial prowess and nature magic to combat threats on the edges of civilization.";

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
