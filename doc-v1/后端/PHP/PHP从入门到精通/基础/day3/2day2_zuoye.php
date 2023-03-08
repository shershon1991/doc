<!DOCTYPE HTML>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
    <title>网页标题</title>
</head>
<body>
<?php
echo "<table>";
echo "</table>";

if(!empty($_POST)) {
	$name = $_POST['name'];
	$password = $_POST['password'];
	$sex = $_POST['sex'];
	$age = $_POST['age'];
	$province = $_POST['province'];
	$hr = $_POST['hr'];
	$txt = $_POST['txt'];
	echo "<br />姓名：$name";
	echo "<br />密码：$password";
	echo "<br />性别：$sex";
	echo "<br />年龄：$age";
	echo "<br />省份：$province";
	echo "<br />爱好：";
	//print_r($hr);
	//方法1：不好！
	//方法2：稍有不好
	//foreach($hr as $key => $value) {
	//	echo $value . ",";
	//}
	//方法3：
	$len = count($hr); //获取数组的长度！
	$str = "";
	for($i=0;$i<$len;$i++){
	    if($i == $len-1) {//如果是最后一项
            $str .= $hr[$i]  . "。";
	    }
	    else {
		    $str .= $hr[$i] . ",";
	    }
    }
	echo $str;
	echo "<br />自我评价：$txt";
}
?>

<form action="" method="post">
    <table width=800 border='1' cellpadding='4'>
        <caption><h2>个人详细信息</h2></caption>
        <tr>
        	<td align="center">姓名</td>
        	<td><input type="text" name="name" /></td>
        </tr>
        <tr>
        	<td align="center">密码</td>
        	<td><input type="password" name="password" /></td>
        </tr>
        <tr>
        	<td align="center">性别</td>
        	<td>
        	   <input type="radio" name="sex" value="男" checked="checked" />男
        	   <input type="radio" name="sex" value="女" />女
        	</td>
        </tr>
        <tr>
        	<td align="center">年龄</td>
        	<td><input type="text" name="age" maxlength="3" /></td>
        </tr>
        <tr>
        	<td align="center">籍贯</td>
        	<td>
        	省份：<select name="province">
        	          <option value="北京">北京</option>
        	          <option value="天津">天津</option>
        	          <option value="上海">上海</option>
        	          <option value="武汉">武汉</option>
        	      </select>
        	</td>
        </tr>
        <tr>
        	<td align="center">个人爱好</td>
        	<td>
            	<input type="checkbox" name="hr[]" value="绘画">绘画
            	<input type="checkbox" name="hr[]" value="写作">写作
            	<input type="checkbox" name="hr[]" value="健身">健身
            	<input type="checkbox" name="hr[]" value="逛街">逛街 <br />
            	<input type="checkbox" name="hr[]" value="学习">学习
            	<input type="checkbox" name="hr[]" value="舞蹈">舞蹈
            	<input type="checkbox" name="hr[]" value="下棋">下棋
            	<input type="checkbox" name="hr[]" value="音乐">音乐
        	</td>
        </tr>
        <tr>
        	<td align="center">自我评价</td>
        	<td><textarea cols="40%" rows="5" name="txt"></textarea></td>
        </tr>
        <tr>
        	<td>
                <input type="submit" value="提交" />
        	    <input type="hidden" name="zhr" value="1991" />
            </td>
        </tr>
    </table>
</form>
</body>
</html>