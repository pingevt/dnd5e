<?php
//dpm($class);
//dpm($elements);
?>

<div id="class-<?php print $class->class_id; ?>">
  <?php
    print render($content);
  ?>
</div>

