<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//演示foreach值变量的“值传递”含义：
//遍历过程中值变量默认的传值方式是值传递。
$arr4 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
foreach($arr4 as $key => $value) {
	$value = $value * 2;
	echo "<br />$key : $value";
}
//芮然foreach中，修改了value的值，但是数组本身是没有改变的：
echo "<br />结果为："; print_r($arr4);

//演示foreach值变量的“引用传递”含义：
//遍历过程中值变量使用“引用传递”（&)方式：
$arr4 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
foreach($arr4 as $key => & $value) {
	$value = $value * 2;
	echo "<br />$key : $value";
}
//芮然foreach中，修改了value的值，但是数组本身是没有改变的：
echo "<br />结果为："; print_r($arr4);

//演示：foreach默认是原数组上进行遍历：
$arr5 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
foreach($arr5 as $k1 => $v1) {
	echo "<br />$k1 : $v1";
	if($k1 === 3) {
		break;
	}
}
$r1 = current($arr5);
$r2 = key($arr5);
echo "<br />此时数字指针指向的单元为：$r2=>$r1";

//演示：挡在foreach循环过程中，“修改数组”，则我们可以观察到：
//次修改不影响遍历的“本来”过程：即虽然修改了，但遍历不受影响
//好像还按照“既定方针”进行下去
$arr6 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
foreach($arr6 as $k2 => $v2) {
	echo "<br />$k2 : $v2";
	if($k2 === 3) {
		$arr6[99] = "新的数据项";
		//即当我们循环到中途时，对该数组添加了一项
		//而且，是添加到数组末尾。
	}
}
echo "<br />但此时，其实该项目已经添加进去了：<br />";
print_r($arr6);
?>
</body>
</html>