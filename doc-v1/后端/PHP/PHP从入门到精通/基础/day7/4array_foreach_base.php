<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$arr4 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
$v1 = current($arr4);  //获得当前单元的值
$v2 = key($arr4);  //获得当前单元的键（下标）
echo "<br />初始单元的下标和值分别为： $v2,$v1";
$v3 = next($arr4);
$v4 = key($arr4);
echo "<br />然后现在当前单元的下标和值分别为：$v4,$v3";
next($arr4);
next($arr4);
next($arr4);
$v3 = current($arr4);
$v4 = key($arr4);
echo "<br />连移3次后，则当前单元的下标和值分别为：$v4,$v3";
next($arr4);
$v3 = current($arr4);
$v4 = key($arr4);
echo "<br />指针到最后，然后再移动一下，则结果为：“下标和值”分别为：$v4,$v3";
echo "<br />实际情况，此时v3(值）为："; var_dump($v3);
echo "<br />实际情况，此时v4（键）为："; var_dump($v4);

echo "<h1>下面研究遍历之后的指针位置</h1>";
$arr5 = array(1=>3, 'a1'=>11, 3=>5, 'mn'=>18, 88=>2);
foreach($arr5 as $key => $value) {
	echo "<br />$key => $value";
}
$k = key($arr5);
$v = current($arr5);
echo "<br />此时（遍历之后），“位置”为："; var_dump($k);
echo "<br />此时（遍历之后），对应“值”为："; var_dump($v);

?>
</body>
</html>