<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
/*
创建该表的结构：
先设计表结构：
create table user_list(
	user_id int auto_increment primary key,
	user_name varchar(10),
	user_pass char(32), #md5加密，结果固定32位
	age tinyint unsigned,
	edu enum('小学', '中学', '大学', '硕士', '博士'),
	xingqu set('排球', '篮球', '足球', '中国足球', '地球'),
	`from` enum('东北', '华北', '西北', '华东', '华南', '华西'),
	reg_time datetime
);
*/

$link = mysql_connect("localhost", "root", "");
mysql_query("set names utf8");
mysql_query("use php");

if(!empty($_GET['id'])) {
	$id = $_GET['id'];
	$sql = "delete from user_list where user_id = $id";
	$result = mysql_query($sql);
	//判断结果：
	if($result === false) {
		echo "<br />抱歉，删除数据失败，原因请参考：" . mysql_error();
	}
	else {
		echo "<br />删除成功！";
	}
}



if(!empty($_POST)) {
	
	//先接收表单数据：
	$username = $_POST['username'];
	$password = $_POST['password'];
	$age = $_POST['age'];
	$xueli = $_POST['xueli'];
	$aihao = $_POST['aihao'];//这是一个数组结果,类似这样：array('aa', 'bb', 'cc');
	$xingqu = "";
	for($i = 0; $i < count($aihao); ++$i) {
		if($i == count($aihao)-1) {//最后一项，不要加逗号
			$xingqu .= $aihao[$i];
		}
		else{
			$xingqu .= $aihao[$i] . ",";
		}
	}
	//此for循环之后，$xingqu就成了类似这样的字符串：“aa,bb,cc”;
	//实际上，这个数组要变为该形式的字符串，还有更好的做法：
	$xingqu = implode(',', $aihao);//这里覆盖了前面的值；
	//implode($s1, $arr1)含糊，用于将数组$arr1中的每一项，以指定的字符串$s1串联起来成为一个“长字符串”
	$from = $_POST['from'];

	//然后，构建sql语句（insert语句）:
	$sql = "insert into user_list (user_name, user_pass, age, edu, xingqu, `from`, reg_time)values(";
	$sql .= "'$username',md5('$password'),$age,'$xueli','$xingqu','$from',now())";
	//echo $sql;

	//执行sql语句：
	$result = mysql_query($sql);//此时才去执行sql语句，此时sql语句中的单引号才在sql中发挥作用

	//判断结果：
	if($result === false) {
		echo "<br />抱歉，添加数据失败，原因请参考：" . mysql_error();
	}
	else {
		echo "<br />添加成功！";
	}
}
?>
<form name="form1" action="" method="post">

	 <h1>添加数据</h1>
	 用户名：<input type="text" name="username"><br />
	 密码：<input type="password" name="password"><br />
	 年龄：<input type="text" name="age"><br />
	 学历：<select name="xueli">
	   <option value="小学">小学</option>
	   <option value="中学">中学</option>
	   <option value="大学">大学</option>
	   <option value="硕士">硕士</option>
	   <option value="博士">博士</option>
	 </select><br />
	 兴趣爱好：
	 <input type="checkbox" name="aihao[]" value="排球">排球
	 <input type="checkbox" name="aihao[]" value="篮球">篮球
	 <input type="checkbox" name="aihao[]" value="足球">足球
	 <input type="checkbox" name="aihao[]" value="中国足球">中国足球
	 <input type="checkbox" name="aihao[]" value="地球">地球<br />

	 来自：
	 <input type="radio" name='from' value="东北">东北
	 <input type="radio" name='from' value="华北">华北
	 <input type="radio" name='from' value="西北">西北
	 <input type="radio" name='from' value="华东">华东
	 <input type="radio" name='from' value="华南">华南
	 <input type="radio" name='from' value="华西">华西<br />

	 <input type="submit" value="提交" >

</form>
<?php
$sql = "select * from user_list;";
$result = mysql_query($sql);
echo "<table border='1'>";
while($rec = mysql_fetch_array($result)) {
	echo "<tr>";
	echo "<td>{$rec['user_name']}</td>";
	echo "<td>{$rec['age']}</td>";
	echo "<td>{$rec['edu']}</td>";
	echo "<td>{$rec['xingqu']}</td>";
	echo "<td>{$rec['from']}</td>";
	echo "<td>{$rec['reg_time']}</td>";
	echo "<td>";
	echo "<a href='2day10_zuoye_biaodan.php?id={$rec['user_id']}' onclick='return queren()'>删除</a>";
	echo "</td>";
	echo "</tr>";
}
echo "</table>";
?>

</body>
</html>
<script>
	function queren() {
		var s1 = window.confirm("你真的要删除吗？");//只能返回true或false
		if(s1 === true) {
			return true;
		}
		else {
			return false;
		}
	}
</script>