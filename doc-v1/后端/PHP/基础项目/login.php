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
if(isset($_POST['button'])){
	$username = $_POST['username'];
	$pwd = $_POST['pwd'];

	mysql_connect('localhost:3306', 'root', '') or die(mysql_error());
	mysql_query('use php');
	mysql_query('set names utf8');

	$sql = "select * from `user` where username='$username' and `password`='$pwd'";
	$result = mysql_query($sql);
	//获取结果集的记录数
	if(mysql_num_rows == 1){
		//echo "登陆成功";
		header("location:showgoods.php");
	}
	else{
		echo "登录失败";
	}
}
<form name="form1" action="" method="post">
	<table width="500" border="1" align="center">
		<tr>
			<td colspan="2">用户登录</td>
		</tr>
		<tr>
			<td>用户名：</td>
			<td><input type="text" name="username" id="username"></td>
		</tr>
		<tr>
			<td>密码：</td>
			<td><input type="password" name="pwd" id="pwd"></td>
		</tr>
		<tr>
			<td colspan="2" align="center"><input type="submit" name="button" id="button" value="提交 "></td>
		</tr>
	</table>
</form>
</body>
</html>