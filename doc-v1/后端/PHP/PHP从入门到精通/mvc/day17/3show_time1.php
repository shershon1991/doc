<?php
header("content-type:text/html;charset=utf-8");
$t = date("Y-m-d H:i:s");

if(!empty($_GET['color'])){
	$color = $_GET['color'];
}
else{
	$color = 'green';
}
$file = '3show_time'.$color.'.html';

include $file;
