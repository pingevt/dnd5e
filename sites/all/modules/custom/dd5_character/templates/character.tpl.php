<?php
//dpm($character);
//dpm($elements);
?>

<div id="character-<?php print $character->char_id; ?>">
  <?php
    print render($content);
  ?>
</div>

