<?php

/**
 * @file
 * Implements admin page for ding Redia services module.
 */

/**
 * Implements hook_form().
 */
function ding_redia_messages_admin_form($form, &$form_state) {
  $form = [];

  $form['ding_redia_messages_auth_service'] = [
    '#type' => 'textfield',
    '#title' => t('Google authentication service'),
    '#description' => t('The url for the authentication service. E.g https://oauth2.googleapis.com/tokeninfo?id_token='),
    '#default_value' => variable_get('ding_redia_messages_auth_service', 'https://oauth2.googleapis.com/tokeninfo?id_token='),
  ];

  $form['ding_redia_messages_environment'] = [
    '#title' => t('Environment'),
    '#description' => t('Default is production. Set to dev or staging in order to receive test messages from the Redia Message Service'),
    '#type' => 'select',
    '#options' => [
      'production' => t('production'),
      'staging' => t('staging'),
      'dev' => t('dev'),
    ],
    '#default_value' => variable_get('ding_redia_messages_environment', 'production'),
  ];

  $messages = ding_redia_messages_get_all_messages();
  $form['ding_redia_message_messages'] = [
    '#type' => 'fieldset',
    '#title' => t('Messages'),
  ];

  $form['ding_redia_message_messages']['content'] = [
    '#markup' =>  $messages,
  ];

  return system_settings_form($form);
}
