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
}
