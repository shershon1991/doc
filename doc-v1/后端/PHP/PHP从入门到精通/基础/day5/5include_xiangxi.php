<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
主文件开始位置：
<?php
	echo "<br />主文件中的位置A";

	include "./page2.php"; //要载入的文件
	
	echo "<br />主文件中的位置B";
?>
<br />主文件结束位置：
</body>
</html>