<?php
//dpm($spell);
//dpm($elements);
?>

<div id="spell-<?php print $spell->spell_id; ?>">
  <?php
    print render($content);
  ?>
</div>