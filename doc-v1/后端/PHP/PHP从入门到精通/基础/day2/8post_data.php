<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
//先一个一个获取数据：
$d1 = $_POST['data1'];
$d2 = $_POST['data2'];

if(!empty($_POST)){
	//然后输出
	echo "d1 = $d1, d2 = $d2";
	echo "<hr />";
	//再来看看整个$_POST这个数组数据
	print_r($_POST);
} 
else{
	echo "非法的页面访问";
}
?>
</body>
</html>