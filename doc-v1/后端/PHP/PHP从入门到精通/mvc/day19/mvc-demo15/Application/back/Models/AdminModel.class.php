<?php
class AdminModel extends BaseModel{
	function CheckAdmin($user, $pass){
		$sql = "select count(*) as c  from admin_user where admin_name='$user' and admin_pass=md5('$pass');";
		//echo $sql;
		//echo "<br />" . md5($pass);
		//die();
		$result = $this->_dao->GetOneData($sql);	//返回一个数据值：表示找到的行数
		if($result == 1){	//表示找到1条数据，就是正确的身份验证
			//登陆成功后应该去修改（更新）该条数据：
			$sql = "update admin_user set login_times = login_times+1, last_login_time = now()";
			$sql .= "where admin_name='$user' and admin_pass=md5('$pass');";
			$result = $this->_dao->exec($sql);
			return true;
		}
		else{		//其他都是错误（通常就是0）
			return false;
		}
	}
}