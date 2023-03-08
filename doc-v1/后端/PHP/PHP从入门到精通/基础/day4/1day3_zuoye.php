<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
if(!empty($_POST)) {
	$num1 = $_POST['data1'];
	$fuhao = $_POST['yunsuanfu'];
	switch($fuhao) {
		case "1":
	    	$jieguo = decbin($num1);
	    	break;
		case "2":
        	$jieguo = decoct($num1);
	    	break;
		case "3":
        	$jieguo = dechex($num1);
	    	break;
	    case "4":
        	$jieguo = bindec($num1);
	    	break;
	    case "5":
        	$jieguo = octdec($num1);
	    	break;
	    case "6":
        	$jieguo = hexdec($num1);
	    	break;

    }
}
else {
	echo $num1 = "";
	echo $num2 = "";
	echo $jieguo = "";
	echo $fuhao = "";
}
?>
<!--当action是空字符串的时候，时提交到本页面！
表单中的所有数据，要想提交，必须有name
-->
<form action="" method="post">
  <input type="text" name="data1" value="<?php echo $num1;?>" />
  <select name="yunsuanfu">
      <option value="1" <?php if($fuhao=='1'){echo 'selected="selected"';}?>>10to2</option>
      <option value="2" <?php if($fuhao=='2'){echo 'selected="selected"';}?>>10to8</option>
      <option value="3" <?php if($fuhao=='3'){echo 'selected="selected"';}?>>10to16</option>
      <option value="4" <?php if($fuhao=='4'){echo 'selected="selected"';}?>>2to10</option>
      <option value="5" <?php if($fuhao=='5'){echo 'selected="selected"';}?>>8to10</option>
      <option value="6" <?php if($fuhao=='6'){echo 'selected="selected"';}?>>16to10</option>
  </select>    
  <input type="submit" value="转换" />
  <input type="text" name="result" value="<?php echo $jieguo;?>" />
 
</form>
</body>
</html>
<?php
//输出ASCII码的所有可见字符（编码为32-126的字符）
//提示：chr(n)可以获得编码为n的字符
for($i = 32; $i <= 126; $i++) {
	echo "<br />a" . chr($i) . "a";
}