<?php
// $Id: 

/**
 * @file views-kwiks.tpl.php
 * View template to display a list using kwiks.
 */
?>
<ul id="kwiks-<?php print $view->name; ?>">  	
  <?php 
    $kwik_id = 0; // zero based index for id, according to .getActive() return values
    foreach ($rows as $row) :      
  ?>
      <li id="kwicks-<?php print $kwik_id; ?>-kwick-<?php print $kwik_id; ?>"><?php print $row; ?></li>	    
  <?php
    $kwik_id++;
    endforeach; 
  ?>	
</ul>