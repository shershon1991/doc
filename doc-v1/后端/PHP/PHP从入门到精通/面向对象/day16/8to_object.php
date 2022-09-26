<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php

$config = array(
    'host' => "localhost",
    'port' => 3306,
    'user' => "root",
    'pass' => "",
    'charset' => "utf8",
    'dbname' => "php"
);
$obj1 = (object)$config;
echo "<pre>";
var_dump($obj1);
echo "</pre>";
echo "<br />单独取user出来：" . $obj1->user;

$arr2 = array('pp1'=>1, 5=>15);
$obj2 = (object)$arr2; 
echo "<pre>";
var_dump($obj2);
echo "</pre>";
echo "<br />单独取pp1出来：" . $obj2->pp1;
//echo "<br />单独取5出来：" . $obj2->5;//报错
echo "<hr />";
$v1 = 1;    $objv1 = (object)$v1;
$v2 = 2.2;    $objv2 = (object)$v2;
$v3 = "abc";    $objv3 = (object)$v3;
$v4 = true;    $objv4 = (object)$v4;
var_dump($objv1);echo "<br />";
var_dump($objv2);echo "<br />";
var_dump($objv3);echo "<br />";
var_dump($objv4);echo "<br />";
?>
</body>
</html>