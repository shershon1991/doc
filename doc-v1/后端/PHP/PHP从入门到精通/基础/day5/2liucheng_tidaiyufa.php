<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
	<title>网页标题</title>
</head>
<body>
<?php
$v1 = 5;
if($v1 >0):
	echo "abcd";
	echo "<br />123";
else:
	echo "XYZ";
endif;

echo "<hr />";
$v1 = 5;
while($v1 <= 10):
	echo "$v1<br />";
	$v1++;
endwhile;
?>
</body>
</html>