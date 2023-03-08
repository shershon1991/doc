<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
//这里演示的是一些常见的自动转换
$v1 = 1 + 2;  //3
$v2 = 1 + "2";  //3
$v3 = "1" + 2;  //3
$v4 = "1" + "2";  //3
//在php中，算术运算符，就只是对数值进行计算
$v5 = 1 + "2abc"; //3
$v6 = "1" + "2abc"; //3
$v7 = "1def" + "2abc"; //3
$v8 = "1def" + "abc2"; //1
$v9 = "def1" + "abc2"; //0
//。。。可见这种识别字符串中数字的转换规则
//是，支取“识别”字符串的前面的数字部分
$v10 = 1 + true;   //2
$v11 = 1 + false;   //1
//以上预算中，也适用于-, *, /, %
?>
</body>
</html>