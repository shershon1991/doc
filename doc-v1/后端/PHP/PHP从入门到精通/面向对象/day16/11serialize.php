<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
$v1 = 1;
$v2 = 'abc';
$v3 = false;
$v4 = array(41, 42, 42);

//转为字符串
$str1 = serialize($v1);
$str2 = serialize($v2);
$str3 = serialize($v3);
$str4 = serialize($v4);
file_put_contents('./file1.txt', $str1);

//将$str1存储到问价file1.txt中
file_put_contents('./file2.txt', $str2);
file_put_contents('./file3.txt', $str3);
file_put_contents('./file4.txt', $str4);
?>
</body>
</html>