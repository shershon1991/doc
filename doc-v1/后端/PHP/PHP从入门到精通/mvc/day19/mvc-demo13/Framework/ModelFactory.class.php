<?php
//单例工厂类
//通过这个工厂类，可以传递过来一个模型类的类名
//并返回给该类一个实例（对象），而且保证其为“单例的”
class ModelFactory{
	static $all_model = array();//用于存储各个模型类的唯一实例（单例）
	static function M( $model_name){//$model_name是一个模型类的类名
		if( !isset(static::$all_model[$model_name]) //如果不存在
			||
		 !(static::$all_model[$model_name] instanceof $model_name)	//不是其实例
		  )	
		{
			static::$all_model[$model_name] = new $model_name();
		}
		return static::$all_model[$model_name];
	}
}