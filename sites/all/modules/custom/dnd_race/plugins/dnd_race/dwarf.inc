<?php

$plugin = array(
  'title' => t('Dwarf'),
  'class' => 'Dwarf',
  'weight' => 1,
);

class Dwarf extends DNDRace {

  public $size = 'medium';

  public function racialTraits() {
    $traits = parent::racialTraits();

    $traits['ability_score_increase'] = array(
      'name' => t('Ability Score Increase'),
      'descr' => t('Your Constitution score increases by 2'),
      'hooks' => array(
        'ability_score' => TRUE,
      ),
    );

    $traits['age'] = array(
      'name' => t('Age'),
      'descr' => t('Dwarves mature at the same rate as humans, but they\'re considered young until they reach the age of 50. On average, they live about 350 years.'),
    );

    $traits['alignment'] = array(
      'name' => t('Alignment'),
      'descr' => t('Most dwarves are lawful, beleiving firmly in the benefits of a well ordered society. They tend toward good as well, with a strong sense of fair play and a belief that everyone deserves to share in the benefits of a just order.'),
    );

    $traits['size'] = array(
      'name' => t('Size'),
      'descr' => t('Dwarves stand between 4 and 5 feet talland average about 150 pounds. Your size is Medium.'),
    );

    $traits['speed'] = array(
      'name' => t('Speed'),
      'descr' => t('Your base walking speed is 25 feet. Your speed is not reduced by wearing heavy armor.'),
      'hooks' => array(
        'speed' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['darkvision'] = array(
      'name' => t('Darkvision'),
      'descr' => t('Accustomed to life underground, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can\'t discern color in darkness, only shades of gray.'),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['dwarven_resilience'] = array(
      'name' => t('Dwarven Resilience'),
      'descr' => t('You have advantage on saving throws against pison, and you have resistance against poison damage (explained in chapter 9).'),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['dwarven_combat_training'] = array(
      'name' => t('Dwarven Combat Training'),
      'descr' => t('You have proficiency with the battleaxe, handaxe, throwing hammer, and warhammer.'),
      'hooks' => array(
        'proficiency' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['tool_proficiency'] = array(
      'name' => t('Tool Proficiency'),
      'descr' => t('You gain proficiency with the artisan\'s tools of your choice: smith\'s tools, brewer\'s supplies, or mason\'s tools.'),
      'hooks' => array(
        'form' => TRUE,
        'proficiency' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['stonecutting'] = array(
      'name' => t('Stonecutting'),
      'descr' => t('Whenever you make an Intelligence (History) check related to the origin of stonework, you double your proficiency bonus to the check, instead of your normal proficiency bonus.'),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    $traits['languages'] = array(
      'name' => t('Languages'),
      'descr' => t('You can speak, read, and write Common and Dwarvish. Dwarvish is full of hard consonants and gutteral sounds, and those characteristics spill over into whatever other language a dwarf might speak.'),
      'hooks' => array(
        'language' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'proficiency_language',
    );

    $traits['subrace'] = array(
      'name' => t('Subrace'),
      'descr' => t('Two main subraces of dwarves populate the worlds of D&D: hill dwarves and mountain dwarves.'),
      'hooks' => array(
        'form' => TRUE,
        'ability_score' => TRUE,
        'hit_point' => TRUE,
        'proficiency' => TRUE,
        'racial_traits' => TRUE,
      ),
      'show on char sheet' => TRUE,
      'char cheet section' => 'features_traits',
    );

    // Add in defaults
    $traits = parent::racialTraitDefaults($traits);

    return $traits;
  }

  public function racialAbilityScoreIncrease() {
    $array = parent::racialAbilityScoreIncrease();

    //$array['constitution'] += 2;

    return $array;
  }








  /**
   * Tool Proficiency Form
   */
  protected function tool_proficiency_form($form, &$form_state, &$character) {
    $char = $form_state['#entity'];
    $race_data = $char->getRaceData();

    $form['tool_proficiency'] = array(
      '#type' => 'select',
      '#title' => 'Tool Proficiency',
      '#description' => t('You gain proficiency with the artisan\'s tools of your choice'),
      '#options' => array(
        '' => '-- Pick tools --',
        'smith' => 'Smith\'s tools',
        'brewer' => 'Brewer\'s supplies',
        'mason' => 'Mason\'s tools',
      ),
      '#element_validate' => array(array('Dwarf', 'tool_proficiency_form_validate')),
      '#default_value' => isset($race_data['subrace'])? $race_data['subrace'] : NULL,
    );

    $form['#submit'][] = array('Dwarf', 'tool_proficiency_form_submit');

    return $form;
  }

  public static function tool_proficiency_form_validate($element, &$form_state, &$form) {
    if ($form_state['values']['tool_proficiency'] == NULL || empty($form_state['values']['tool_proficiency'])) {
      form_set_error(implode('][', $element['#array_parents']), 'You must pick a tool proficiency.');
    }
  }

  public static function tool_proficiency_form_submit($form, &$form_state) {
    $char = $form_state['#entity'];

    $race_data = $char->getRaceData();

    $race_data['tool_proficiency'] = $form_state['values']['tool_proficiency'];

    $form_state['#entity']->field_char_race_data[LANGUAGE_NONE][0]['value'] = serialize($race_data);
  }

  /**
   * Subrace Form
   */
  protected function subrace_form($form, &$form_state, &$character) {
    $char = $form_state['#entity'];
    $race_data = $char->getRaceData();

    $form['subrace'] = array(
      '#type' => 'select',
      '#title' => 'Dwarf subrace',
      '#description' => t('Two main subraces of dwarves populate the worlds of D&D: hill dwarves and mountain dwarves.'),
      '#options' => array(
        '' => '-- Pick Subrace --',
        'hill' => 'Hill Dwarves',
        'mountain' => 'Mountain Dwarves',
      ),
      '#element_validate' => array(array('Dwarf', 'subrace_form_validate')),
      '#default_value' => isset($race_data['subrace'])? $race_data['subrace'] : NULL,
    );

    $form['#submit'][] = array('Dwarf', 'subrace_form_submit');

    return $form;
  }

  public static function subrace_form_validate($element, &$form_state, &$form) {
    if ($form_state['values']['subrace'] == NULL || empty($form_state['values']['subrace'])) {
      form_set_error(implode('][', $element['#array_parents']), 'You must pick a subrace.');
    }
  }

  public static function subrace_form_submit($form, &$form_state) {
    $char = $form_state['#entity'];

    $race_data = $char->getRaceData();

    $race_data['subrace'] = $form_state['values']['subrace'];

    $form_state['#entity']->field_char_race_data[LANGUAGE_NONE][0]['value'] = serialize($race_data);
  }
}