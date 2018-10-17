<?php
/**
* Implementation of views_plugin_style
*
*/
class views_kwiks_plugin_style_kwiks extends views_plugin_style {

  // just set default options on this object 
  function options(&$options) {
    $options['isVertical'] = FALSE;	// Kwicks will align vertically if true
    $options['sticky'] = FALSE;	// One kwick will always be expanded if true
    $options['defaultKwick'] = 0;	// The initially expanded kwick (if and only if sticky is true). zero based
    $options['activeClass'] = 'active';	// 
    $options['event'] = 'mouseenter';	// The event that triggers the expand effect
    $options['eventClose'] = 'mouseleave'; // The event that triggers the collapse effect
    $options['spacing'] = 0;	// The width (in pixels) separating each kwick element
    $options['duration'] = 500; // The number of milliseconds required for each animation to complete
    $options['easing'] = 'swing'; // Custom animation easing (requires easing plugin if anything other than 'swing' or 'linear')
    $options['max'] = 200; // The width or height of a fully expanded kwick element
    $options['min'] = null; // The width or height of a fully collapsed kwick element
    $options['init'] = null;// event called when the event occurs (click or mouseover)
    $options['expanding'] = null; // event called before kwicks expanding animation begins
    $options['collapsing'] = null;// event called before kwicks collapsing animation begins
    $options['completed'] = null; // event called when animation completes
    $options['customcss'] = FALSE;	// use custom CSS
    $options['customcsspath'] = '';	// CSS path (if customcss is true)
  }
  
  // Provide a form to edit options for this plugin. 
  function options_form(&$form, &$form_state) {
    $options = $this->display->handler->get_field_labels();
    $form['isVertical'] = array(
      '#type' => 'checkbox',
      '#title' => t('Kwicks will align vertically'),
      '#default_value' => $this->options['isVertical'],
    );
    $form['sticky'] = array(
      '#type' => 'checkbox',
      '#title' => t('One kwick will always be expanded if true'),
      '#default_value' => $this->options['sticky'],
    );
    $form['defaultKwick'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Default Kwick'),
      '#description' => t('The initially expanded kwick (if and only if sticky is true). zero based'),
      '#default_value' => $this->options['defaultKwick'],
    );
    $form['activeClass'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Active class'),
      '#description' => t('The name of active CSS class'),
      '#default_value' => $this->options['activeClass'],
    );
    $form['event'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Expand Event'),
      '#description' => t('The event that triggers the expand effect (JQuery mouse events, see: http://api.jquery.com/category/events/mouse-events/)'),
      '#default_value' => $this->options['event'],
    );
    $form['eventClose'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Collapse Event'),
      '#description' => t('The event that triggers the collapse effect (JQuery mouse events, see: http://api.jquery.com/category/events/mouse-events/)'),
      '#default_value' => $this->options['eventClose'],
    );
    $form['spacing'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Spacing'),
      '#description' => t('The width (in pixels) separating each kwick element'),
      '#default_value' => $this->options['spacing'],
    );
    $form['duration'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Duration'),
      '#description' => t('The number of milliseconds required for each animation to complete'),
      '#default_value' => $this->options['duration'],
    );
    $form['easing'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Easing'),
      '#description' => t('Custom animation easing (requires easing plugin if anything other than "swing" or "linear").'),
      '#default_value' => $this->options['easing'],
    );
    $form['max'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Max'),
      '#description' => t('The width or height of a fully expanded kwick element, leave blank for auto/CSS. <b>Please note that you must use one or the other, but not both.</b>'),
      '#default_value' => $this->options['max'],
    );
    $form['min'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Min'),
      '#description' => t('The width or height of a fully collapsed kwick element, leave blank for auto/CSS. <b>Please note that you must use one or the other, but not both.</b>'),
      '#default_value' => $this->options['min'],
    );
    $form['init'] = array(
      '#type' => 'checkbox',
      '#title' => t('Init'),
      '#description' => t('Use file event_init.js with function called when the event occurs (click or mouseover)'),
      '#default_value' => $this->options['init'],
    );
    $form['expanding'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Expanding'),
      '#description' => t('Use file event_expanding.js with function called before kwicks expanding animation begins'),
      '#default_value' => $this->options['expanding'],
    );
    $form['collapsing'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Collapsing'),
      '#description' => t('Use file event_collapsing.js with function called before kwicks collapsing animation begins'),
      '#default_value' => $this->options['collapsing'],
    );
    $form['completed'] = array(
      '#type' => 'checkbox',      
      '#title' => t('Completed'),
      '#description' => t('Use file event_completed.js with function called when animation completes'),
      '#default_value' => $this->options['completed'],
    );
    $form['customcss'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a custom CSS, will not disable default CSS'),
      '#default_value' => $this->options['customcss'],
    );
    $form['customcsspath'] = array(
      '#type' => 'textfield',
      '#size' => 10,
      '#title' => t('Custom CSS path'),
      '#description' => t('path of custom CSS, relative to module\'s folder'),
      '#default_value' => $this->options['customcsspath'],
    );
  }

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    $options = &$form_state['values']['style_options'];
    if (!is_numeric($options['defaultKwick'])) {
      form_error($form['defaultKwick'], t('Please specify a numerical value for default Kwick'));
    }
    if (!is_numeric($options['spacing'])) {
      form_error($form['spacing'], t('Please specify a numerical value for default spacing'));
    }
    if (!is_numeric($options['duration'])) {
      form_error($form['duration'], t('Please specify a numerical value for default duration'));
    }
    if (!is_numeric($options['max']) && $options['max']!= '') {
	form_error($form['max'], t('Please specify a numerical value for default Max'));
    }
    if (!is_numeric($options['min']) && $options['min']!= '') {
	form_error($form['min'], t('Please specify a numerical value for default Min'));
    }
    // check if min/max aren't both filled with some value
    if($options['max']!= '' && $options['min']!= '') {
      form_error($form['min'], t('You can specify Min or Max, but not both.'));
    }
    if ($options['customcss']) {
      $custom_css = drupal_get_path('module', 'views_kwiks') . '/' . $options['customcsspath'];
      if(!file_exists($custom_css)) {        
	form_error($form['customcsspath'], t('Please specify valid path'));
      }
    }
  }

  // Allow the style to do stuff before each row is rendered. 
  function pre_render($result) {
    if (!empty($this->row_plugin)) {
      $this->row_plugin->pre_render($result);
    }
  }


}


