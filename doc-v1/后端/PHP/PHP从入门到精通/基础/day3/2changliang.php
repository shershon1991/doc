<!DOCTYPE HTML>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  	<title>网页标题</title>
</head>
<body>
<?php
//常量的定义语法1：
//define("常量名", 常量值);
define("PI", 3.14);
define("SCHOOL", "传智播客");

//定义语法2：
//const 常量名 = 常量值;
const CC1 = 1234;
const CC2 = 'abcd';

//使用形式1：直接使用其名字
echo "<br />常量PI的值为：" . PI;  //注意，不能写在引号中
echo "<br />常量SCHOOL为：" . SCHOOL;
$s1 = PI * 3 * 3;  //求半径为3的圆面积

//使用形式2：constant("常量名"); //注意：常量名是一个字符串
$s2 = constant("PI") * 3 * 3;
echo "<br />s1 = $s1, s2 = $s2";
echo "<br />" . SCHOOL . constant("CC1") . constant("CC2");

//取得常量值的灵活性语法：
$i = 1;
$c1 = "CC" . $i;
echo "<br />常量\$c1的值为："  . constant($c1); //输出1234

if(defined("PI")){
	echo "常量PI已经存在"; //通常此时就可以去使用它！
}
else{
	echo "常量PI不存在"; //通常判断为不存在是为了来定义它！
	define("PI", 3.14);
}
$s3 = PI * 5 * 5;
echo "<br />面积为：$s3";
echo "<hr />";
echo  "v1的值为" . $v1;   //注意，该变量v1未定义过
echo  "C1的值为" . C1;    //注意，该变量C1未定义过

//魔术常量
echo "<br />" . __FILE__;
echo "<br />" . __DIR__;
echo "<br />" . __LINE__;
echo "<br />" . __LINE__;
echo "<br />" . __LINE__;
?>
</body>
</html>