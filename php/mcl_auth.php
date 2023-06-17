<?php
	$p = array();
	parse_str($_SERVER['QUERY_STRING'], $p);
	system("bin/mcl_auth 'cJK8Q~KV7GWoZwMtusedzCHwbzPQhc6CWvaqzc-r' ".$p['code'])
?>
