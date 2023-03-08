<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class  A{
	public  $p1 = 1;
	function __get($prop_name){
		echo "<br />你小心啊，你正用的属性{$prop_name}还没有定义呢";
		//这里，只是表名：我们这里有这个机会（机制）可以应对这种情况
		//比如还可以这样来处理
		echo "<br />属性{$prop_name}不存在！";
		return "";	//也可以返回0或false,或任何其他被“看做没有”的数据；
		//也可以这样处理：
		trigger__error("发生错误：属性不存在。", E_USER_ERROR);
		die();
	}
}
$a1 = new A();
echo  $a1->p1;	//1;
echo  $a1->p2;	//一旦该类中定义了__GET方法，此时就不会出错
				//而是直接调用该方法了
//则：php中的重载技术，就是来应对上述“出错”的情况
//代码不出错，而且还能“优雅处理”；
echo  $a1->p3;	

$v1 = isset($a1->p2);	//对不存在的属性判断，结果是false
var_dump($v1);
?>

</body>
</html>