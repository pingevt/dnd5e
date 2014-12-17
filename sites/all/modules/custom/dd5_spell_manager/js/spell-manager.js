(function($) {

Drupal.behaviors.spellManager = {
  attach: function (context, settings) {

    // Toggle whether a spell is prepared.
    $('input.spell-prepared-toggle').click(function() {
      var path = '/dd5-ajax/spell-manager/spell-prepared/' + $(this).data('char-id') + '/' + $(this).data('spell-id') + '/' + $(this).attr('checked');
console.log(path);
      $.post(path, function( data ) {
console.log( data );
      });

    });

    //
    $('input.spell-cast-toggle').click(function() {
      var path = '/dd5-ajax/spell-manager/spell-cast/' + $(this).data('char-id') + '/' + $(this).data('spell-id') + '/' + $(this).data('spell-slot-level') + '/' + $(this).data('spell-slot-level-delta') + '/' + $(this).attr('checked');
console.log(path);
      $.post(path, function( data ) {
console.log( data );
      });

    });

  }
};

})(jQuery);
