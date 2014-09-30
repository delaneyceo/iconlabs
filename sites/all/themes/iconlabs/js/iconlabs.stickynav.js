(function ($) {

  Drupal.behaviors.iconlabsExampleBehavior = {
    attach: function (context, settings) {

      $('.l-navbar', context).once('foo', function () {
        $(this).waypoint('sticky');
      });
    }
  };
})(jQuery);
