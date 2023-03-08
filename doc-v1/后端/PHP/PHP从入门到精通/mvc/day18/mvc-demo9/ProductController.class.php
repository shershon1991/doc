<?php
class ProductController extends BaseController{
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
