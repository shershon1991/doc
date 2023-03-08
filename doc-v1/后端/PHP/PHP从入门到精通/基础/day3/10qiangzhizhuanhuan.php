<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$v1 = 123;
$s1 = (float) $v1; //将v1的值转换为float类型
                  //注意此时$v1里面还是整数123
$s2 = (string) $v1; //将v1的值转换为string类型
echo "<br />s1为"; var_dump($s1);
echo "<br />s2为"; var_dump($s2);

$v2 = 123;
setType($v2, "string"); //直接转换v2的类型为string
echo "<br />v2为"; var_dump($v2);
?>
</body>
</html>