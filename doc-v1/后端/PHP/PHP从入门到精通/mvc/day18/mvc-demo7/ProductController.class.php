<?php
header("content-type:text/html; charset=utf-8");
require './ProductModel.class.php';
require './ModelFactory.class.php';

class ProductController{
	function ShowAllProductAction(){
		//echo "aa";
		$obj = ModelFactory::M('ProductModel');
		$data1 = $obj->GetAllProduct();	//是一个二维数组
		include './Product_list.html';
	}
	function DetailAction(){
		echo "bb你好";
	}
	function DelAction(){
		echo "cc";

	}
}

$ctrl = new ProductController();
$act = !empty($_GET['a']) ? $_GET['a'] : "Index";
$action = $act . "Action";	
$ctrl->$action();	//可变函数——>>可变方法