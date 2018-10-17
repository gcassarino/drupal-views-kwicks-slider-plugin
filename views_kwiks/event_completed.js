function(){
  var kwick_id = $('#kwiks-galleria_kwiks').data('kwicks').getActive(); // returns zero based index if kwick is expanded; returns -1 if collapsed
  //if($('#kwiks-galleria_kwiks #kwicks-'+kwick_id+'-kwick-'+kwick_id).width() >= 400){
    $('#kwiks-galleria_kwiks #kwicks-'+kwick_id+'-kwick-'+kwick_id+' .views-field-title').contents().css("color" , "#00CC6E");
    $('#kwiks-galleria_kwiks #kwicks-'+kwick_id+'-kwick-'+kwick_id+' .views-field-title').fadeIn('slow');
    $('#kwiks-galleria_kwiks #kwicks-'+kwick_id+'-kwick-'+kwick_id+' .views-field-title-1').fadeIn('slow');
    $('#kwiks-galleria_kwiks #kwicks-'+kwick_id+'-kwick-'+kwick_id+' .views-field-body').fadeIn('slow');
  //}  
}