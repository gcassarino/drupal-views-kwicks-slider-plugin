# drupal-views-kwicks-slider-plugin
Drupal 6 Views Style plugin that displays results using the Kwicks https://github.com/Mottie/Kwicks plugin for jQuery.

[DEMO](https://www.quovadiscom.com/old-site/www.quovadiscom.com/content/drupal-views-kwicks-slider-plugin/index.html)

A kwicks slider for drupal 6. Kwicks for JQuery is a plugin created by [Jeremy Martin](https://github.com/jmar777) https://github.com/jmar777/kwicks

However, this plugin uses the version of Mottie https://github.com/Mottie/Kwicks because offers better control on events.

Install as usual, the module provides a new Style option called "kwiks" when choosing the Display Style of the View.

The module should work as it is: needed files from Mottie's Kwicks plugin are located inside "kwiks" folder, but if you want to update the JQuery Kwicks plugin copy the updated files in the folder "kwiks" within the module.

Access to plugin settings page to adjust the options. Options from Mottie's plugin are available.

A custom css (custom.css) and some events are included as examples.  To use the custom.css provided specify the path of custom CSS in  "Custom CSS path" option of the plugin settings page. The path is relative to module's folder, if you wish to use another css.

![views plugin setup](http://www.quovadiscom.com/sites/default/files/views-plugin-setup.jpg "views plugin setup")

Select the desired event (optionally) in the plugin Style settings and then modify the corresponding files inside the module's folder as you wish. The files are event_init.js, event_expanding.js, event_completed.js, event_collapsing.js

This plugin works with default Drupal JQuery, Ajax pager for faster navigation is supported. Works well on touch screen devices.

# NOTE:
this is an old project for Drupal 6 reported here on Github for the convenience of [those who still use D6](https://www.drupal.org/project/usage/drupal), the original page is here http://www.quovadiscom.com/content/drupal-views-kwicks-slider-plugin

