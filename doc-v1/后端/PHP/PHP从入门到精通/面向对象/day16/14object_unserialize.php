<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
include './Xuliehua.class.php';

//这里演示对象的反序列化效果：
$s1 = file_get_contents("./obj1.txt");
$o2 = unserialize($s1);
echo "<pre>";
var_dump($o2);
echo "</pre>";
$o2->f1();
?>
</body>
</html>