<!DOCTYPE HTML>
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
    <title>网页标题</title>
</head>
<body>
<?php
//写一个页面server.php,并输出至少5个$_SERVER内的元素信息，并说明是什么含义，页面表现像是如下：
    echo "<table border='1'>";
    echo "<tr>";
        echo "<td>元素名称</td>";
        echo "<td>使用形式</td>";
        echo "<td>结果</td>";
        echo "<td>含义</td>";
    echo "</tr>";

    echo "<tr>";
        echo "<td>PHP_SELF</td>";
        echo "<td>\$_SERVER['PHP_SELF']</td>";
        echo "<td>" . $_SERVER['PHP_SELF'] . "</td>";
        echo "<td>代表当前网页的地址</td>";
    echo "</tr>";

    echo "<tr>";
        echo "<td>DOCUMENT_ROOT</td>";
        echo "<td>\$_SERVER['DOCUMENT_ROOT']</td>";
        echo "<td>" . $_SERVER['DOCUMENT_ROOT'] . "</td>";
        echo "<td>代表当前站点的真实物理路径</td>";
    echo "</tr>";
    //。。。。更多行。。。  
echo "</table>";

//方法2:
$arr1 = array("PHP_SELF", "DOCUMENT_ROOT", "SERVER_NAME", "REMOTE_ADDR", "SCRIPT_FILENAME");
$arr2 = array("当前网页路径", "站点根目录", "站点名", "客户端IP", "网页物理路径");
echo "<table border='1'>";
foreach($arr1 as $key => $value) {
	echo "<tr>";
	    echo "<td>$value</td>";
	    echo "<td>" . "$" . "_SERVER['$value']</td>";
	    echo "<td>" . $_SERVER[$value] . "</td>";
	    echo "<td>" . $arr2[$key] . "</td>";
	echo "</tr>";
    }
echo "</table>";
?>
</body>
</html>