<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
include "./page2.php";//成功就有返回值1，但这里不用它
$v1 = include "./page2.php";//有返回值，并放入变量v1
echo "<br />"; var_dump($v1);
$v2 = include "./no_this_page.php";//有返回值，是false,并放入变量v2
echo "<br />"; var_dump($v2);

echo "<hr />";
$v3 = include_once "./page3.php"; //此被载入文件中有return
echo "<br />111";

echo "<hr />";
$v4 = include_once "./page4.php"; //此被载入文件中有return
echo "<br />111";
echo "<br />"; var_dump($v4);
?>
</body>
</html>