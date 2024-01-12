/**
 * @file
 * Handles getting Service Messages from the server and displaying them.
 *
 * In order to bypass caching of the frontpage we use ajax to get the messages.
 * This way we ensure we start and stop displaying messages at the correc time.
 */

(function ($) {
  "use strict";

  Drupal.behaviors.fullTextReview = {
    attach: function (context) {
      const url = Drupal.settings.dingRediaMessages.messageUrl;
      var selector = ".frontpage-layout";
      $(selector, context).once("frontpage-layout", function () {
        var selectedElement = $(this);
        $.ajax({
          type: "POST",
          url: url,
          success: function (result) {
            if (result.hasMessage) {
              selectedElement.prepend(result.html);
            }
            $(".redia-service-message-icon-close").click(function () {
              $("#redia-frontpage-message-pane").hide();
            });
          },
        });
      });
    },
  };
})(jQuery);
