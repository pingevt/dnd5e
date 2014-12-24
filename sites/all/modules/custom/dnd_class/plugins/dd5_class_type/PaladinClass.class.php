<?php

class PaladinClass extends CharClass {
  public $description = "A holy warrior bound to a sacred oath";

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
