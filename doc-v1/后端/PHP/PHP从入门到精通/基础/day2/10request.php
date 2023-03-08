<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
if(!empty($_POST)) {
	echo "<p>post数据：<br />";
	print_r($_POST);
}
if(!empty($_GET)) {
	echo "<p>get数据：<br />";
	print_r($_GET);
}
if(!empty($_REQUEST)) {
	echo "<p>request数据：<br />";
	print_r($_REQUEST);
	echo "<br />也可以这样写：";
	echo "<br />" . $_REQUEST['d1'];
	echo "<br />" . $_REQUEST['d2'];
	echo "<br />" . $_REQUEST['age'];
	echo "<br />" . $_REQUEST['data1'];
	echo "<br />" . $_REQUEST['data2'];
}
?>

<form action="10request.php?d1=5&d2=cctv&age=18" method="post">
  	数据1：<input type="text" name="data1" />
  	<br />
  	数据2：<input type="text" name="data2" />
  	<br />
  	<input type="submit" value="提交" />
</form>
</body>
</html>