(function ($) {

  // Adjust the overlay dimensions.
  Drupal.behaviors.convert_content_type = {
    
    attach: function (context) {
      $('#overlay:not(.export-as-overlay)', context).each(function() {
       
	}).addClass('export-as-overlay');
    }
    
  };

})(jQuery);