<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//使用while和each和list配合来遍历该数组
$arr4 = array(1=>3, 'a1'=>11, 3=>5, "mn"=>18, 88=>2);
while(list($key, $value) = each($arr4)) {//几乎是模式化的写法
	//这里皆可以处理$key和$value了
	echo "<br />$key = $value";
}
//对比foreach的原始遍历语法：
echo "<hr />";
$arr4 = array(1=>3, 'a1'=>11, 3=>5, "mn"=>18, 88=>2);
foreach($arr4 as $key => $value) {
	echo "<br />$key = $value";
}
?>
</body>
</html>