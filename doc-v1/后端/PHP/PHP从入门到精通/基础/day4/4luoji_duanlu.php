<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
//此函数知识为了说明要对2个数据(x,y)进行
//复杂的计算，然后得出一个真假结论
function f1($x, $y) {
	$m1 = $x*2;
	$m2 = $y*3;
	return $m1 + $m2;	
}
$n1 = 3;
$n2 = 4;
//if判断语句写法1：
if($n1 > $n2 && f1($n1, $n2) > 20) {
	//这里完成某种任务1
}
else {
	//这里完成另一些任务2
}
//if判断语句写法2：
if(f1($n1, $n2) > 20 && $n1 > $n2) {
	//这里完成某种任务1
}
else {
	//这里完成另一些任务2
}
//写法1和写法2最终计算结果是一样的！
//但写法1具有优势：它又是可能不需要进行“复杂”计算
//就可以得到判断结果，这就是“短路”现象
//写法2却总是先去进行“复杂”计算，显然术语消耗资源行为
?>
</body>
</html>