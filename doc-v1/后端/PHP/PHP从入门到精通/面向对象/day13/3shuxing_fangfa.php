<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
class MyDreamGirl {
    var $name = '小花';//此时它叫做“属性”了（原来是变量的）
    var $age = '18';
    var $edu = '大学';

    //此时它叫做“方法”了（原来是函数的）
    function xiyifu() {
        echo "<br />{$this->age}的{$this->edu}学历的{$this->name}在勤快地洗衣服。";
    }
    function zuofan() {
        echo "<br />{$this->age}的{$this->edu}学历的{$this->name}在快乐地做饭。";
    }
    function GetPingfanghe($x, $y) {
	$result = $x*$x + $y*$y;
	return $result;
    }
}
$obj1 = new MyDreamGirl();
$obj1->xiyifu();
$obj1->zuofan(); 


$obj2 = new MyDreamGirl();
$obj2->name = '小红';
$obj2->age = '19'; 
$obj2->edu = '高中';
$obj2->xiyifu();
$obj2->zuofan();

$v1 = $obj2->GetPingfanghe(3,4);
echo "<br />v1 = $v1";
?>
</body>
</html>