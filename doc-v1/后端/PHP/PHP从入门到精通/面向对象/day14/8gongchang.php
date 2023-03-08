<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class A{};
class B{};
//设计一个工厂类：这个工厂类有一个静态方法：
//通过该方法可以获得指定来的对象！
class Gongchang{
	static function GetObject($className){
		$obj = new $className();//这是可变类！
		return $obj;
	}
}
$o1 = Gongchang::GetObject("A");
$o2 = Gongchang::GetObject("B");
$o3 = Gongchang::GetObject("A");
var_dump($o1); echo "<br />";
var_dump($o2); echo "<br />";
var_dump($o3); echo "<br />";
?>
</body>
</html>