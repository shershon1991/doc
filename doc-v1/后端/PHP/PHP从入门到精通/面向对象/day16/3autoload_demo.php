<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
function __autoload($class_name){
    require './class/' . $class_name . ".class.php";
}
$obj1 = new A();//此时需要“A”这个类，就会自动调用__autoload()函数
		//并将“A”这个类名（字符串）传过去
var_dump($obj1);
?>
</body>
</html>