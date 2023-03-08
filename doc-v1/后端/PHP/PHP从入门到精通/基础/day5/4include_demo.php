<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
echo "<p>使用相对路径载入";
include './page1.php';


echo "<p>使用绝对路径载入(方法1）";
include __DIR__ . '\page1.php';

echo "<p>使用绝对路径载入(方法2）";
$root = $_SERVER['DOCUMENT_ROOT']; //获得当前站点的根目录
include $root . '\php' . '\day5' . '\page1.php';

?>
</body>
</html>