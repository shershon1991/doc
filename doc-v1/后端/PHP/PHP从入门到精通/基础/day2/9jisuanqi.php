<!DOCTYPE HTML>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
if(!empty($_POST)){
	$num1 = $_POST['data1'];
	$num2 = $_POST['data2'];
	$fuhao = $_POST['yunsuanfu'];
	if($fuhao == '+'){
	    $jieguo = $num1 + $num2;
	}
	elseif($fuhao == '-'){
        $jieguo = $num1 - $num2;
	}
	elseif($fuhao == '*'){
        $jieguo = $num1 * $num2;
	}
	elseif($fuhao == '/'){
        $jieguo = $num1 / $num2;
	}
}
else{
	echo $num1 = "";
	echo $num2 = "";
	echo $jieguo = "";
	echo $fuhao = "";
}
?>

<!--当action是空字符串的时候，是提交到本页面！
表单中的所有数据，要想提交，必须有name
-->
<form action="" method="post">
  	<input type="text" name="data1" value="<?php echo $num1;?>" />
  	<select name="yunsuanfu">
      	<option value="+" <?php if($fuhao=='+'){echo 'selected="selected"';}?>>+</option>
      	<option value="-" <?php if($fuhao=='-'){echo 'selected="selected"';}?>>-</option>
      	<option value="*" <?php if($fuhao=='*'){echo 'selected="selected"';}?>>*</option>
      	<option value="/" <?php if($fuhao=='/'){echo 'selected="selected"';}?>>/</option>
	</select>    
	<input type="text" name="data2" value="<?php echo $num2;?>" />
	<input type="submit" value="=" />
	<input type="text" name="result" value="<?php echo $jieguo;?>" />
	<br />
	<input type="reset" value="重置" />
</form>
</body>
</html>