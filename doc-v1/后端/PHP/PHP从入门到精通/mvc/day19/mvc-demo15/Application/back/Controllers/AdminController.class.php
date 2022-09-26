<?php
class AdminController extends BaseController{
	function LoginAction(){
		//echo "欢迎。。。";
		include VIEW_PATH . 'login.html';
	}
	function CheckLoginAction(){
		//echo "检测用户名密码。。。";
		//接收登录表单的2个数据项：
		$user = $_POST['username'];
		$pass = $_POST['password'];
		$model = ModelFactory::M('AdminModel');
		$result = $model->CheckAdmin($user, $pass);
		if($result === true){
			echo "登陆成功。。。";
			//header("location:去登陆后的第一个页面");
		}
		else{
			//失败了就提示，并可以跳转到登录界面
			$this->GotoUrl("用户名或密码错误！", "?p=back&c=Admin&a=login", 2);
		}
	}
}