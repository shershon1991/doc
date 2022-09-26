<?php

//在php里面生成json信息
//json_encode(数组/对象);

//索引数组
$color = array("red", "green", 'blue');
echo json_encode($color),"<br />"; //js数组 ["red","green","blue"]

//关联数组
$city = array('hubei'=>'wuhan', 'beijing'=>'haidian', 'chongqing'=>'huilongguan');
echo json_encode($city),"<br />"; //json对象 {"hubei":"wuhan","beijing":"haidian","chongqing":"huilongguan"}

//索引关联数组
$city1 = array('hubei'=>'wuhan', 'beijing'=>'haidian', 'chongqing'=>'huilongguan', 'shenzhen');
echo json_encode($city1),"<br />"; //json对象 {"hubei":"wuhan","beijing":"haidian","chongqing":"huilongguan","0":"shenzhen"}

//多维数组，看当前维数的类型：
    //关联/索引关联数组---》json对象
    //索引数组---》js数组

//对象生成json信息
class Person{
	public $name = "tom";
	public $age = 23;
	public function run(){
		echo "is running";
	}
}
$per = new Person();
//生成json信息只考虑属性
echo json_encode($per);