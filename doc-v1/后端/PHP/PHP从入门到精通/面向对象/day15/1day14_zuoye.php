<!DOCTYPE HTML>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" /> 
  <title>网页标题</title>
</head>
<body>
<?php
/*
设计如下几个类：
商品类，有名称，有价钱，库存数，可显示自身信息（名称，价钱）。
手机类，是商品的一种，并且有品牌，有产地，可显示自身信息。
图书类，是商品的一种，有作者，有出版社，可显示自身信息。
创建一个手机对象，并显示其自身信息；
创建一个图书对象，并显示其自身信息；
扩展要求：尽量体现封装性就跟好了。
*/

class Product{
	protected $name;
	protected $price = 0;//价格
	protected $storage = 0;//库存
	protected function ShowInfo(){
		echo "<p>商品名称：" . $this->name;
		echo "<br />商品价格：" . $this->price;
	}

	function __construct($name, $price, $storage){
		$this->name = $name;
		$this->price = $price;
		$this->storage = $storage;
	}
}


class Mobile extends Product{
	protected $brand;
	protected $chandi;
	protected $storage = 0;

	function __construct($name, $price, $storage, $brand, $chandi){
		
		parent::__construct($name, $price, $storage);

		$this->brand = $brand;
		$this->chandi = $chandi;
	}

	function ShowInfo(){
		parent::ShowInfo();
		echo "<br />商品品牌：" . $this->brand;
		echo "<br />商品产地：" . $this->chandi;
		echo "<br />库存：" . $this->storage;

	}
}

$m1 = new Mobile('联想3280', 1208, 1000, 'lenovo', '北京上地信息产业基地');
$m1->ShowInfo();


class Book extends Product{
	protected $author;
	protected $publisher;

	function __construct($name, $price, $storage, $author, $publisher){
		
		parent::__construct($name, $price, $storage);

		$this->author = $author;
		$this->publisher = $publisher;
	}

	function ShowInfo(){
		parent::ShowInfo();
		echo "<br />作者：" . $this->author;
		echo "<br />出版社：" . $this->publisher;
	}
}

$b1 = new Book('你早该这么玩excel', 100, 1000, 'topu', '北京中关村互联网教育中心');
$b1->ShowInfo();

?>
</body>
</html>