<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//
class A{
	function __construct(){
		echo "<br />父类中的构造方法";
		var_dump($this);
	}
}
class B extends A{
	function __construct(){
		echo "<br />子类中的构造方法";
		var_dump($this);
	}
}
class C extends A{
	//这个类中没有构造方法
}
$o1 = new B();
$o2 = new C();




?>
</body>
</html>