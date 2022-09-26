<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$v1 = 1;
$v2 = 1;
$v1++; //此行后，v1为2 
++$v2; //此行后，v2为2
echo "<br />v1=$v1, v2=$v2";
//说明：独立的加加运算中，此时前自增和后自增效果一样！

echo "<hr />"; 
echo $v1++; //输出2，此行后，v1为3
echo "<br />";
echo ++$v2; //输出3，此行后，v2为3
echo "<br />v1=$v1, v2=$v2";

echo "<hr />";
$s1 = $v1++;//s1为3，此行后，v1为4
$s2 = ++$v2;//s2为4，此行后，v2为4
echo "<br />s1=$s1, s2=$s2";
echo "<br />v1=$v1, v2=$v2";
//可见，再有加加运算的其他语句中，
//前加加和后加加会有区别：
//影响其他语句的执行结果：
//前加加是先对自加变量加1，然后做其他运算
//后加加是做做其他运算，然后对自加变量加1

$t1 = microtime(true); //获得当前时间
for($i = 1; $i < 100000000; ++$i) {
	
}
$t2 = microtime(true); //获得当前时间
for($i = 1; $i < 100000000; $i++) {
	
}
$t3 = microtime(true); //获得当前时间
echo "<p>前加加耗时：" . ($t2-$t1);
echo "<p>后加加耗时：" . ($t3-$t2);

?>
</body>
</html>