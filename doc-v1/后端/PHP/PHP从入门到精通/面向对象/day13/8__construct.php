<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class MyDreamGirl{
    var $name;
    var $age;
    var $edu;

    function xiyifu(){
        echo "<br />{$this->age}岁的{$this->edu}学历";
	echo "的{$this->name}在勤快地洗衣服";
    }
}
$girl1 = new MyDreamGirl();//创建一个对象
$gril1->name = '小花';//然后分别设置其属性
$gril1->age = 18;
$gril1->edu = '大学';
$gril1->xiyifu();

$girl2 = new MyDreamGirl();//再创建一个对象
$gril2->name = '小红';
$gril2->age = 19;
$gril2->edu = '高中';
$gril2->xiyifu();

//以上方式，new一个对象出来，就要需要数据赋值（初始化），
//然后才能合适地使用（调用）该方法以完成一定的任务。

echo "<hr />";
class NvShen{
    var $name;
    var $age;
    var $edu;
    function __construct($p1, $p2, $p3){
	$this->name = $p1;//将$p1数据赋值给当前对象的name属性
	$this->age = $p2;//$this这个词就代表当前这个new出来的对象
	$this->edu = $p3;
	//目前，构造方法只演示了给“自己”的属性赋值；
	//其实，还可以做得更多：调用方法以完成某些任务；
    }
    function xiyifu(){
        echo "<br />{$this->age}岁的{$this->edu}学历";
	echo "的{$this->name}在勤快地洗衣服";
    }
}
//new这个NvShen类，也就是创建这个女神对象的同时
//就会自动去调用该类中的构造方法：__construct($p1, $p2, $p3)
//这里，new后面的类名括号中的就是对应实参；
$girl3 = new NvShen('小花', 18, '大学');
$girl3->xiyifu();
$girl4 = new NvShen('小红', 19, '高中');
$girl4->xiyifu();
?>
</body>
</html>