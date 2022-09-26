<?php
//先：获取数据的逻辑（虽然很简单）
$t = date("Y-m-d H:i:s");

//根据用户的选择，去确定要使用的“模板文件”：
if(!empty($_GET['ban'])){
	$ban = $_GET['ban'];
} 
else{
	$ban = "red";
}
$file = "./3show_time_" . $ban . ".html";

//后：载入一个“静态网页”，并在其中输出并显示该数据
include $file;
?>
