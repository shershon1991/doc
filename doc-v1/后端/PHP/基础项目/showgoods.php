<html>
<head>
	<meat http-equiv="content-type" content="text/html;charset=utf-8" />
	<title>网页标题</title>
	<meta name="keywords" content="关键词列表" />
	<meta name="description" content="网页描述" />
	<link rel="stylesheet" type="text/css" href="style/common.css" />
</head>
<body>

<?php  
header("content-type:text/html;charset=utf-8");
@mysql_connect('localhost', 'root', '') or die(mysql_error());
mysql_query('use php');
mysql_query('set names gbk');

$sql = "select * from product";
$result = mysql_query($sql);
// die(print_r($result));
// var_dump($result);die();
?>
<table width="980">
<tr>
	<th>编号</th><th>商品名称</th><th>价格</th><th>品牌</th><th>产地</th><th>修改</th><th>删除</th>
</tr>
<?php
//循环匹配成关联数组
while($rows=mysql_fetch_assoc($result)){
	echo "<tr align='center'>";
	echo '<td>'.$rows['pro_id'].'</td>';
	echo '<td>'.iconv('gbk','utf-8',$rows['pro_name']).'</td>';
	echo '<td>'.$rows['price'].'</td>';
	echo '<td>'.iconv('gbk','utf-8',$rows['pinpai']).'</td>';
	echo '<td>'.iconv('gbk','utf-8',$rows['chandi']).'</td>';
	echo '<td><input type="button" value="修改" /></td>';
	echo '<td><input type="button" value="删除"></td>';
	echo "</tr>";
}
?>
</table>
</body>
</html>