<?php
	$p = array();
	parse_str($_SERVER['QUERY_STRING'], $p);
	system("bin/mcl_auth_rf ".$p['xb']." ".$p['u']." ".$p['e'])
?>
