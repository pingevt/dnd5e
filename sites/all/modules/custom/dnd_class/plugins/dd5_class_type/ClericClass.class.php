<?php

class ClericClass extends CharClass {
  public $description = "A priestly champion who weilds devine magic in service of a higher power.";

  // EntityBundlePluginProvideFieldsInterface
  static function fields() {
    $fields = array();

    return $fields;
  }

  // EntityBundlePluginValidableInterface
  public static function isValid() {
    return TRUE;
  }

  public function classTraits() {
    $traits = parent::classTraits();

    $traits['hit_dice'] = array(
      'name' => t('Hit Dice'),
      'descr' => t('1d8 per cleric level'),
      'hooks' => array(
        'hit_dice' => TRUE,
      ),
    );

    $traits['hit_points_first'] = array(
      'name' => t('Hit Points at 1st Level'),
      'descr' => t('8 + your Constitution modifier.'),
      'hooks' => array(
        'hit_point' => TRUE,
      ),
    );

    $traits['hit_points_higher'] = array(
      'name' => t('Hit Points at Higher Levels'),
      'descr' => t('1d8 (or 5) + your Constitution modifier per cleric level after 1st.'),
      'hooks' => array(
        'hit_point' => TRUE,
      ),
    );

    $traits['armor'] = array(
      'name' => t('Armor'),
      'descr' => t('Light Armore, medium armor, shields'),
      'hooks' => array(
        'proficiency' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'proficiency_language',
    );

    $traits['weapons'] = array(
      'name' => t('Weapons'),
      'descr' => t('All simple weapons'),
      'hooks' => array(
        'proficiency' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'proficiency_language',
    );

    $traits['tools'] = array(
      'name' => t('Tools'),
      'descr' => t('None'),
      'hooks' => array(
        'proficiency' => FALSE,
      ),
      'show on char sheet' => FALSE,
    );

    $traits['saving_throws'] = array(
      'name' => t('Saving Throws'),
      'descr' => t('Wisdom, Charisma'),
      'hooks' => array(
        'saving_throws' => TRUE,
      ),
      'show on char sheet' => FALSE,
    );

    $traits['skills'] = array(
      'name' => t('Skills'),
      'descr' => t('Choose two from History, Insight, Medicine, Persuasion, and Religion.'),
      'hooks' => array(
        'form' => TRUE,
        'skills' => TRUE,
      ),
      'show on char sheet' => FALSE,
    );

    $traits['equipment'] = array(
      'name' => t('Equipment'),
      'descr' => t('You start with the following equipment, in addition to the equipment granted by your background: '),
      'hooks' => array(
        'form' => TRUE,
        'equipment' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'equipment',
    );

    $traits['ritual_casting'] = array(
      'name' => t('Ritual Casting'),
      'descr' => t('You can cast a cleric spell as a ritual if that spell has the ritual tag and you have that spell prepared.'),
      'hooks' => array(
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'attacks_spellcasting',
    );

    $traits['spellcasting_focus'] = array(
      'name' => t('Spellcasting Focus'),
      'descr' => t('You can use a holy symbol (found in Chapter 5) as a spellcasting focus for your cleric spells.'),
      'hooks' => array(
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'attacks_spellcasting',
    );

    $traits['devine_domain'] = array(
      'name' => t('Devine Domain'),
      'descr' => t(''),
      'hooks' => array(
        'form' => TRUE,
        'class_traits' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'attacks_spellcasting',
    );

    $traits['cd_turn_undead'] = array(
      'name' => t('Channel Divinity: Turn Undead'),
      'descr' => t(''),
      'hooks' => array(
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'attacks_spellcasting',
    );

    $traits['destroy_undead'] = array(
      'name' => t('Destroy Undead'),
      'descr' => t(''),
      'hooks' => array(
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['devine_intervention'] = array(
      'name' => t('Devine Intervention'),
      'descr' => t(''),
      'hooks' => array(
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['ability_score_improvement'] = array(
      'name' => t('Ability Score Improvment'),
      'descr' => t('When you reach 4th level, and again at 8th, 12th, 16th, and 19th level, you can increase one ability score of your choice by 2, or you can increase two ability scores of your choice by 1. As normal, you can\'t increase an ability score above 20 using this feature.'),
      'hooks' => array(
        'form' => TRUE,
        'ability_score' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits = parent::classTraitDefaults($traits);

    return $traits;
  }

  public function getSpellSlots($lvl = NULL) {

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

  public function getCantripsKnown($lvl = NULL) {
    $cantrips_known = array(
      0 => 3,
      1 => 3,
      2 => 3,
      3 => 4,
      4 => 4,
      5 => 4,
      6 => 4,
      7 => 4,
      8 => 4,
      9 => 5,
      10 => 5,
      11 => 5,
      12 => 5,
      13 => 5,
      14 => 5,
      15 => 5,
      16 => 5,
      17 => 5,
      18 => 5,
      19 => 5,
    );

    if ($lvl != NULL && $lvl >= 1 && $lvl <= 20) {
      return $cantrips_known[($lvl -1)];
    }

    return $cantrips_known;
  }



  /*******************
   * Trait hooks
   ******************/
  protected function skills_form($form, &$form_state, &$character) {

  }

  public static function skills_form_validate($element, &$form_state, &$form) {
    if ($form_state['values']['skills'] == NULL || empty($form_state['values']['skills'])) {
      form_set_error(implode('][', $element['#array_parents']), 'You must choose your skills.');
    }
  }

  public static function sills_form_submit($form, &$form_state) {
    $char = $form_state['#entity'];

    $race_data = $char->getRaceData();

    $race_data['tool_proficiency'] = $form_state['values']['tool_proficiency'];

    $form_state['#entity']->field_char_race_data[LANGUAGE_NONE][0]['value'] = serialize($race_data);
  }
}