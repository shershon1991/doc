<?php
require './MyDateTime.class.php';

//根据用户请求，以决定获取什么样的时间：
//效果1
if(!empty($_GET['f']) && $_GET['f'] == 'date'){
	//$t = date("Y-m-d");
	$obj = new MyDateTime();
	$t = $obj->GetDate();
}
//效果2
else if(!empty($_GET['f']) && $_GET['f'] == 'time'){
	//$t = date("H:i:s");
	$obj = new MyDateTime();
	$t = $obj->GetTime();
}
else{//默认
	//$t = date("Y-m-d H:i:s");
	$obj = new MyDateTime();
	$t = $obj->GetDateTime();
}

//表现（展示）改时间：
include './4mvc_time_demo1.html';
?>