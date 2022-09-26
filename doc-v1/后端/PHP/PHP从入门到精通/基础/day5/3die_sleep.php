<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
echo "<br />A";
echo "<br />当前时间为：" . date("Y-m-d H:i:s");
sleep(3);  //停止3秒，然后继续执行
echo "<br />当前时间为：" . date("Y-m-d H:i:s");
die("<br />终止！");
echo "<br />a";
echo "<br />b";
?>
</body>
</html>