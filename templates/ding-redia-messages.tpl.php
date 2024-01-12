<?php

/**
 * @file
 * A Redia Service Message.
 * 
 */
?>

<div id="redia-frontpage-message-pane" class="panel-pane pane-message">
    <div class="panel-pane-inner">
        <div class="redia-servive-message-wrapper">
            <div class="redia-service-message-rectangle <?php print $message->level_class ?>">
                <div class="redia-service-message-combined-shape"><?php print $message->icon ?></div>
                <div class="redia-service-message-content">
                    <div class=" redia-service-message-text Body-bold">
                        <?php print $message->header ?>
                    </div>
                    <div class="redia-service-message-text-copy">
                        <?php print $message->body ?>
                    </div>
                    <?php if (isset($message->more_link)) : ?>
                        <div class="redia-service-message-more-link">
                            <?php print $message->more_link ?>
                       </div>    
                    <?php endif ?>
                </div>
                <?php if ($message->dismissible) : ?>
                    <div class="redia-service-message-icon-close">
                        <?php print $message->close_icon ?>
                    </div>
                <?php endif ?>
            </div>
        </div>
    </div>
</div>