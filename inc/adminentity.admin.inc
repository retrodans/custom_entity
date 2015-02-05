<?php

/**
* Form definition for adding / editing a project.
*/
function admin_entity_form($form, &$form_state, $project = NULL) {

  $form['name'] = array(
    '#title' => t('Project name'),
    '#type' => 'textfield',
    '#default_value' => isset($project->name) ? $project->name : '',
    '#required' => TRUE,
  );

  $form['description'] = array(
    '#title' => t('Project description'),
    '#type' => 'textarea',
    '#default_value' => isset($project->description) ? $project->description : '',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => isset($project->id) ? t('Update project') : t('Save project'),
    '#weight' => 50,
  );

  return $form;
}


/**
* Validation for admin entity form.
*/
function admin_entity_form_validate($form, &$form_state) {

}


/**
* Submit handler for the project add/edit form.
*/
function admin_entity_form_submit($form, &$form_state) {
  $project = entity_ui_form_submit_build_entity($form, $form_state);
  $project->save();
  drupal_set_message(t('The project: @name has been saved.', array('@name' => $project->name)));
  $form_state['redirect'] = 'admin/content/admin-entity';
}
