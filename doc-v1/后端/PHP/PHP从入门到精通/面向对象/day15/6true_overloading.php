<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//设定目标：设计一个类，这个类的实例可以实现如下需求：
//调用方法f1:
//传入一个参数，就返回其本身；
//传入2个参数，就求其平方和；
//传入3个参数，就求其立方和。
class A{
	//这是一个魔术方法，在A的对象调用不存在的方法的时候
	//会被自动调用来应付这种情况：
	function __call($Func_name, $argument){
	//就表示要处理调用时形式上使用f1这个不存在的方法
		if($Func_name === 'f1'){
			$len = count($argument);//获得实参的数量
			if($len < 1 || $len >3){
				trigger_error("使用非法的方法!", E_USER_ERROR);
			}
			else if($len == 1){
				return $argument[0];
			}
			else if($len == 2){
				return $argument[0]*$argument[0] + $argument[1]*$argument[1];
			}
			else if($len == 3){
				$v1 = $argument[0];
				$v2 = $argument[1];
				$v3 = $argument[2];
				return $v1*$v1*$v1 + pow($v2, 3) + pow($v3, 3);
			}
		}
		else if($Func_name === 'f2'){

		}
		else if($Func_name === 'f3'){

		}
	}
}
$a1 = new A();	//实例化出来一个对象 
$v1 = $a1->f1(1);
$v2 = $a1->f1(2,3);
$v3 = $a1->f1(4,5,6);
echo "v1 = $v1, v2 = $v2, v3 = $v3";
?>
</body>
</html>