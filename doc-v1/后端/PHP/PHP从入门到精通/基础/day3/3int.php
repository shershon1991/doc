<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$n1 = 123; //这是10进制的一个数字
$s1 = decbin($n1); //将10进制转换为2进制
$s2 = decoct($n1); //将10进制转换为8进制
$s3 = dechex($n1); //将10进制转换为16进制
echo "<br />$n1" . "的2进制形式为：$s1";
echo "<br />$n1" . "的8进制形式为：$s2";
echo "<br />$n1" . "的16进制形式为：$s3";

$v1 = 0x123;
$result = octdec($v1);
echo "<br />$v1" . "的10进制形式为：$result";
?>


</body>
</html>