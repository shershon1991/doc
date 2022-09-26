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
//连接数据库
@mysql_connect('localhost', 'root', '') or die(mysql_error());
mysql_query('use php');
mysql_query('set names gbk');
//1.求总记录数
$sql = "select count(*) from product";
$result = mysql_query($sql);
$row = mysql_fetch_row($result);  //将资源匹配成索引数组
$recordcount = $row[0];  //总记录数
//2.定义页面大小
$pagesize = 2;
//3.求总页数
$pagecount = ceil($recordcount/$pagesize);
//4.获得传递的当前页码
$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
if($pageno < 1){
	$pageno = 1;
} elseif($pageno > $pagecount){
	$pageno = $pagecount;
}
//5.求当前页的起始位置
$startno = ($pageno-1)*$pagesize;
//6.获取当前页的内容
$sql = "select * from product order by pro_id limit $startno,$pagesize";
$result = mysql_query($sql);
?>

<!--循环页面-->
<table width="1366">
<tr>
	<th>编号</th>
	<th>商品名称</th>
	<th>价格</th>
	<th>品牌</th>
	<th>产地</th>
	<th>修改</th>
	<th>删除</th>
</tr>
<?php
//循环匹配成关联数组
while($row=mysql_fetch_assoc($result)){
	echo "<tr>";
	echo '<td>'.$row['pro_id'].'</td>';
	echo '<td>'.iconv('gbk','utf-8',$row['pro_name']).'</td>';
	echo '<td>'.$row['price'].'</td>';
	echo '<td>'.iconv('gbk','utf-8',$row['pinpai']).'</td>';
	echo '<td>'.iconv('gbk','utf-8',$row['chandi']).'</td>';
	echo '<td><input type="button" value="修改" /></td>';
	echo '<td><input type="button" value="删除"></td>';
	echo "</tr>";
}
?>
</table>
<!--循环页面-->
<table>
<tr>
	<td>
		【<a href="fenye.php?pageno=1">首页</a>】
		【<a href='fenye.php?pageno=<?php echo $pageno-1; ?>'>上一页</a>】
		【<a href='fenye.php?pageno=<?php echo $pageno+1; ?>'>下一页</a>】
		【<a href='fenye.php?pageno=<?php echo $pagecount; ?>'>尾页</a>】
	</td>
	<td>&nbsp;
	<?php
	for($i=1;$i<=$pagecount;++$i){
		echo '<a href="fenye.php?pageno=' . $i . '">' . $i . '</a>&nbsp;&nbsp;';
	}
	?>  
	</td>
</tr>
</table>
</body>
</html>