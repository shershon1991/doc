<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//怪物类(抽象类)
abstract class Guai{
	protected $blood = 100;
	abstract function Attack();//抽象方法
}
//蛇怪类
class Snake extends Guai{
	 function Attack(){//具体去实现该父类继承下来的抽象方法
		echo "<br />悄悄靠近主人公，然后迅猛咬一口";
		$this->blood--;//自身掉血1点
	}
}
//虎怪类
class Tiger extends Guai{
	 function Attack(){//具体去实现该父类继承下来的抽象
		echo "<br />猛扑猛咬主人公";
		$this->blood--;//自身掉血1点
	}
}
//妖怪类：这个类作为抽象类，可以不去实现父类的抽象方法；
//也可以去实现： 
abstract class Yao extends Guai{
	//abstract function Attack();//抽象方法
	//这里，这个抽象方法仍然是保留的父类抽象方法的身份
}
//八戒
class bajie extends Yao{
	function Attack(){
		echo "<br />抡起钉耙打下去";
		$this->blood -= 2;//自身掉血2点
	}
}
?>
</body>
</html>