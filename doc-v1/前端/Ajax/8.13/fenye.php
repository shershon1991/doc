<?php

header("content-type:text/html;charset=utf-8");

$link = @mysql_connect('localhost', 'root', '');
mysql_select_db('test', $link);
mysql_query("set names utf-8");

include "./fenye.class.php";

$sql = "select * from fenye";
$rst = mysql_query($sql);
$total = mysql_num_rows($rst);
$per = 2;

$page = isset($_GET['page']) ? $_GET['page'] : 1;
//echo $page;die;
$page_obj = new Page($total, 2, $page);
//var_dump($page_obj);die;
$sql2 = "select name, price, number, weight from fenye " . $page_obj->lmt();
//echo $sql2;die;
$rst2 = mysql_query($sql2);

$pageList = $page_obj->pageList();

echo <<<EOF
<style type="text/css">
    table{
        width:700px;
        margin:auto;
        border:1px solid black;
        border-collapse: collapse;
    }
    td{
        border:1px solid black;
    }
</style>
<table>
    <tr>
        <td>名称</td>
        <td>价格</td>
        <td>数量</td>
        <td>重量</td>
    </tr>
EOF;

while($row2 = mysql_fetch_assoc($rst2)){
    //var_dump($row2);die;
    $str  = "<tr>";
    $str .= "<td>" . $row2['name']. "</td>";
    $str .= "<td>" . $row2['price']. "</td>";
    $str .= "<td>" . $row2['number']. "</td>";
    $str .= "<td>" . $row2['weight']. "</td>";
    $str .= "</tr>";
}
$str .= "<tr><td colspan='4'>" . $pageList. "</td></tr>";
$str .= "</table>";

echo $str;


