<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
include './Xuliehua.class.php';

$obj1 = new Xuliehua();
echo "<pre>";
var_dump($obj1);
echo "</pre>";
//下面开始进行序列化操作：
$s1 = serialize($obj1);
file_put_contents('./obj1.txt', $s1);
?>
</body>
</html>