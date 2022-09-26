<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//公司成员：
class Member{
	public $name = "匿名";
	public $age = 18;
	public $sex;
	function __construct($name, $age, $sex){
		$this->name = $name;
		$this->age = $age;
		$this->sex = $sex;
	}
}
//讲师类：
class Teacher extends Member{
	public $edu = "大学";
	public $major;
	function __construct($name, $age, $sex, $edu, $major){
		//$this->name = $name;
		//$this->age = $age;
		//$this->sex = $sex;
		//以上三行（若干行），被下面一行代替
		parent::__construct($name, $age, $sex);
		$this->edu = $edu;
		$this->major = $major;
	}
	function ShowInfo(){
		echo "<br />姓名：{$this->name}";
		echo "<br />年龄：{$this->age}";
		echo "<br />性别：{$this->sex}";
		echo "<br />学历：{$this->edu}";
		echo "<br />专业：{$this->major}";
	}
}
$t1 = new Teacher("张三", 30, "男", "大学", "PHP");
$t1->ShowInfo();
?> 
</body>
</html>