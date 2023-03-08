<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class C1{
    public $name;
    function __construct($n){
	$this->name = $n;
    }
    function __destruct(){
	echo "<br />{$this->name}被销毁了";
    }
}
$o1 = new C1('A');//程序运行结束，变量（对象）肯定都会被销毁！
$o2 = new C1('B');
$o3 = new C1('C');
echo "<br />"; var_dump($o1);
echo "<br />"; var_dump($o2);
echo "<br />"; var_dump($o3);
echo "<hr />";

unset($o1);//断开变量$o1跟其“变量编号数据#1”的联

$o21 = $o2;//值传递
unset($o2);//问：对象B被销毁了吗？答：没有销毁
//因为$o2变量中还存储了B对象的编号（#2)
//但此时最后程序结束时，会先销毁$o21,再销毁$o3;

$o31 = & $o3;//引用传递；此时2个变量共同指向一个编号数据
unset($o3);//问：对象‘C’被销毁了吗？答：没有
//因为$o31变量还是指向了对象C的编号（#3）
//虽然$o3此时断开跟该数据的联系，但$o31还没有断开

$o4 = new C1('D');
$o41 = & $o4;//引用传递，此时2个变量共同指向一个编号数据（#4）
$o4 = 44;//其实是详单与给予其一个普通的数据值；
//问：对象D此时会被销毁吗？此时会被销毁

echo "<br />程序结束（程序的最后一行）";
?>
</body>
</html>