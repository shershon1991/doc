<?php
class ProductController extends BaseController{
	function ShowAllProductAction(){
		//echo "aa";
		$obj = ModelFactory::M('ProductModel');
		$data1 = $obj->GetAllProduct();	//是一个二维数组
		include './Application/front/views/Product_list.html';
	}
	function DetailAction(){
		echo "bb你好";
	}
	function DelAction(){
		$id = $_GET['id'];
		$obj = ModelFactory::M('ProductModel');
		$result = $obj->DelProductById($id);
		$this->GotoUrl("删除成功", "?c=Product&a=ShowAllProduct", 1);

	}
}
