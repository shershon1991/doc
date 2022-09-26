<?php
header("content-type:text/html;charset=utf-8");
require './ShowDateTime.class.php';

if(!empty($_GET['c']) && $_GET['c'] == 'date'){
	$obj = new ShowDateTime();
	$t = $obj->ShowDate();
}
else if(!empty($_GET['c']) && $_GET['c'] == 'time'){
	$obj = new ShowDateTime();
	$t = $obj->ShowTime();
}
else{
	$obj = new ShowDateTime();
	$t = $obj->ShowDateTime();
}

include './mvc_showdatetime.html';