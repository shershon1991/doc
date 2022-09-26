<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
/*
定义一个“教师类”，并由此类实例化两个“教师对象”。该类至少包括3个属性，3个
方法，其中有个方法是“自我介绍”，就能把自身的所有信息显示出来。
*/
class Teacher{
	public $p1 = 1;
	var $p2;
	public $name = '匿名';
	public function IntroMe(){
		echo "<p>";
		echo "<br />属性p1:" . $this->p1;
		echo "<br />属性p2:" . $this->p2;
		echo "<br />姓名:" . $this->name;
		echo "</p>";
	}
}
$t1 = new Teacher();
$t1->p2 = 22;
$t1->name = "张三";
$t1->IntroMe();

/*
定义一个“学生类”，并有此类实例化两个“学生对象”。
该类包括姓名，性别，年龄等基本信息，并至少包括一个静态属性（表示总学生数）和一个常量，
以及包括构造方法和析构方法。
该对象还可以调用一个方法来进行“自我介绍”（显示其中的所有属性）。
构造方法可以自动初始化一个学生的基本信息，并显示“XX加入传智，当前有XX个学生”。
*/
class Student{
	const SCHOOL = '传智';
	public $name = '匿名';//这是name属性
	public $age = 0;
	var $sex = "男";
	static $count = 0;
	function __construct($name, $age = 0, $sex = '男'){
		$this->name = $name;//这里:$name是形参，name是属性
		$this->age = $age;
		$this->sex = $sex;
		self::$count++;//计数，计算有多少个学生（实例）；
		echo "{$name}加入传智，当前有" . self::$count . "个学生";
	}
	public function IntroMe(){
		echo "<p>";
		echo "<br />姓名:" . $this->name;
		echo "<br />性别:" . $this->sex;
		echo "<br />年龄:" . $this->age;
		echo "</p>";
	}
	function __destruct(){
		echo "<br />{$this->name}对象被销毁;";
	}
}
$s1 = new Student('谭晓珊', 20);
$s1->IntroMe();

$s1 = new Student('刘冬', 20, '女');
$s1->IntroMe();

?>
</body>
</html>