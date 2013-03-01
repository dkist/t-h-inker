(function ($) {

  // Adjust the overlay dimensions.
  Drupal.behaviors.save_settings = {
    
    attach: function (context) {
      $('#overlay:not(.save_settings_overlay)', context).each(function() {
     var $test = $(this).find('.page-convert-content-type');
        
      /*  if ($test){
          // adjust the overlay
          $(this).css({
            'width'     : '20%',
            'min-width' : '20%'
          });
            
          $('.add-or-remove-shortcuts', this).hide();  // hide "add short-cut" button
          $('#branding', this).hide();  // hide branding container
        } */
      }).addClass('save_settings_overlay');
    }
    
  };

})(jQuery);