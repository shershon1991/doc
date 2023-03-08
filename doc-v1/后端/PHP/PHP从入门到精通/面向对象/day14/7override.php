<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//动物类
class Animal{
	public $p1 = "能进食";
	function Move(){
		echo "<br />能移动身体！";
	}
}

//鱼类
class Fish extends Animal{
	public $skin = "布满鱼鳞";//皮肤
	public $p1 = "张开嘴巴吸水";//覆盖父类的同名属性
	function Move(){
		echo "<br />摆动尾巴前进！";//覆盖父类的同名方法
	}
}

//鱼类
class Bird extends Animal{
	public $skin = "布满羽毛";//皮肤
	public $p1 = "张开嘴巴啄食";//覆盖父类的同名属性
	function Move(){
		echo "<br />扇动翅膀飞翔前进！";//覆盖父类的同名方法
	}
}
?>
</body>
</html>