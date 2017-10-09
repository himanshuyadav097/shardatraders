<?php
function ws_account_services_resources() {
	$resources = array (
			   'drupal_test' => array (
					'actions' => array (		
				  'userregister' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'userregister',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
							'userlogin' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'userlogin',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
					'userlogout' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'userlogout',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
					 'groupJoin' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'groupJoin',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
					
					'usergroup' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'usergroup',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
					'forgetpassword' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'forgetpassword',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
					  'profileupdated' => array (
									'file' => array (
											'type' => 'inc',
											'module' => 'ws_account',
											'name' => 'ws_account.resource'
									),
									'callback' => 'profileupdated',
									'args' => array (
											array (
													'name' => 'data',
													'type' => 'struct',
													'description' => 'The note object',
													'source' => 'data',
													'optional' => FALSE
											)
									),
									'access callback' => '_ws_account_services_access'
							),
								
					), 
					 'retrieve' => array (
							'file' => array (
									'type' => 'inc',
									'module' => 'ws_account',
									'name' => 'ws_account.resource' 
							),
							'callback' => '_ws_account_retrieve',
							 'args' => array(
                                                              array(
                                                                                 'name' => 'uidee',
                                                                                 'optional' => FALSE,
                                                                                 'source' => array('path' => 0),
                                                                                 'type' => 'int',
                                                                                 'description' => 'uid',
                                                                 ), 	 
                                                              array(
                                                                             	'name' => 'uid',
                                                                              	'optional' => TRUE,
                                                                              	'source' => array('param' => 'uid'),
                                                                              	'type' => 'int',
                                                                              	'description' => 'uid of user',
                                                               ),
														 	  array(
														 				'name' => 'rid',
														 				'optional' => TRUE,
														 				'source' => array('param' => 'rid'),
														 				'type' => 'int',
														 				'description' => 'rid of user',
														 		),
                                                              array(
                                                                                 'name' => 'name',
                                                                                 'optional' => TRUE,
                                                                                 'source' => array('param' => 'name'),
                                                                                 'type' => 'string',
                                                                                 'description' => 'user name',
                                                                 ),
                                                 ),
							'access callback' => '_ws_account_services_access' 
					) 
			),
	);
	// TODO insert here
	return $resources;
}
/**
 * Access callback.
 */
function _ws_account_services_access($s) {
	return TRUE;
}
function _ws_account_retrieve($s,$uid,$rid,$name,$limit,$page,$sort) {
	$output = array();
	$where='';
 	if($s == 'userlist'){
 		$query = db_select ( 'users', 'p' )->extend ( 'PagerDefault' );
 		$query->extend ( 'PagerDefault' )
 		->fields ( 'p' );
 		if (isset( $uid ) ) {
 			$query->condition ( 'p.uid',$uid,'=' );
 		}
 		if (isset( $name )) {
 			$query->condition ( 'p.name',$name,'=' );
 		}
 		$output = $query->orderBy ( 'p.uid', 'asc' )->limit ( 20 )->execute ()->fetchall ();
 	}
 	if($s=='registrationlist'){
 		$query = db_select ( 'gb_user', 'p' )->extend ( 'PagerDefault' );
 		$query->extend ( 'PagerDefault' )
 		->fields ( 'p' );
 		if (isset( $rid ) ) {
 			$query->condition ( 'p.rid',$rid,'=' );
 		}
 		$output = $query->orderBy ( 'p.rid', 'asc' )->limit ( 20 )->execute ()->fetchall ();
 	}
 	if($s=='groupList'){
 		$query = db_select ( 'gb_group_members', 'p' )->extend ( 'PagerDefault' );
 		$query->extend ( 'PagerDefault' )
 		->fields ( 'p' );
 		if (isset( $rid ) ) {
 			$query->condition ( 'p.rid',$rid,'=' );
 		}
 		$output = $query->orderBy ( 'p.rid', 'asc' )->limit ( 20 )->execute ()->fetchall ();
 	}
	return $output;
}
/**
 * 
 * user regiser post api 
 */
function userregister($arg1) {
	
	
	session_start();
	$_SESSION["email"] = $arg1[email];
	$_SESSION["password"] = $arg1[password];
	$output=array();
	    if(validate_users($arg1[f_name]) && validate_users($arg1[l_name]) && validate_emails($arg1[email]) && validate_password($arg1[password]) )
	    {
	    	$str=$arg1[password];
	    	$pwd_md5= md5($str); 
	    	
	        $email_exits=db_query("SELECT email from gb_user where email='$arg1[email]' OR user_name='$arg1[user_name]'")->fetchAll();

		if(empty($email_exits) && !empty($arg1[user_name])){
			
			
			try {
				
				$inst_rec = db_insert ( 'gb_user' )->fields ( array (
						'user_name' => $arg1[user_name],
						'f_name' => $arg1[f_name],
						'l_name' => $arg1[l_name],
						'email' => $arg1[email],
						'password' =>$pwd_md5,
						'created' => time ()
				)
						)->execute ();
				$output['rid']=$inst_rec;
			}
			catch ( Exception $e ) {
			}
		}else{
			$output['error']='Duplicate Entry Or insert Username';
  		}
	    }
	    else
	    {
			$output['error']='Please Insert currect Keyword';
	    }
	    return  $output;
}
/**
 * validation code for users first name and last name also email 
 * 
 * 
 */
function validate_users($string){
	
	if(preg_match('/[^a-z ]/i', $string))
	{ 
		return false;
	}
	return true;
}
  function validate_emails($string){
 
	if (filter_var($string, FILTER_VALIDATE_EMAIL)) 
	{
		return true;
	}
	return false;
} 
function validate_password($string){
	if(preg_match('/^[A-Za-z0-9_+!@#$%^&*]+$/u',$string))
	{
		return true;
	}
	return false;
}
/**
 * Forget password code start
 *
 */
 function forgetpassword($arg2){
	//$output=array();
	$email_exits=db_query("SELECT email from gb_user where email='$arg2[email]'")->fetchAll();
	if(!empty($email_exits)){
		$num=randomPassword();
	    if(is_numeric($num)){
			echo "numaric";
		}
			else{
				echo "no";
			}
		$pass=md5($num);
		$to      = 'himanshu.yadav@techletsolutions.com';
		$subject = 'Forget Password Is  '.$num.'';
		$message = 'Forget Password & password update';
		$headers = 'From: webmaster@example.com' . "\r\n" .
				'Reply-To: webmaster@example.com' . "\r\n" .
				'X-Mailer: PHP/' . phpversion();
		
		mail($to, $subject, $message, $headers);
		  try {
			$pwd_update=db_query("update  gb_user set password='".$pass."' where email='".$email_exits[0]->email."'")->execute();
		  	
		  } catch (Exception $e) {
		  	print_r($e);
		  }
		}
		else{
				print_r("email not exist");
		}
	}
function randomPassword() {
	$alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';
	$pass = array(); //remember to declare $pass as an array
	$alphaLength = strlen($alphabet) - 1; //put the length -1 in cache
	for ($i = 0; $i < 12; $i++) {
		$n = rand(0, $alphaLength);
		$pass[] = $alphabet[$n];
	}
	return implode($pass); //turn the array into a string
}
/**
 **********************************************************
 * 1.[POST]::User Login API Response l_id login Id
 *
 * @param unknown $data
 *
 * @return mixed|StdClass
 **********************************************************
 */


function userlogin($arg4){
	$output=array();
	$pwd_md6= md5($arg4[password]);
	$login_user=db_query("SELECT rid,user_name,password from gb_user where user_name='$arg4[user_name]' AND password='$pwd_md6'")->fetchAll();
	if(!empty($login_user)){
		
		$login_insert=db_insert('gb_login')->fields( array(
				'rid'=>$login_user[0]->rid,
				'is_login'=>1,
				't_time'=>time()
	)
				)->execute ();
				$output['login']=$login_insert;
	}else{
		
		$output['error']='Forget username password Please Register First';
		
	}
	return $output;
}
/**
 * User logout session destroy
 * email
 *
 */
function userlogout($arg1){
$logout=array();
$userlogout_update=db_query("update  gb_login set is_login=0 where rid='".$arg1[rid]."' OR l_id='".$arg1[l_id]."'")->execute();
return $logout[logout]=$userlogout_update;
}
/**
 *
 * user regiser post api
 */
function usergroup($arg1) {
	
	$output=array();
	$userid=db_query("SELECT * from gb_user where rid='$arg1[rid]'")->fetchAll();
	if(validate_users($arg1[g_name])){
	if(!empty($userid)){
		try {
			$inst_grp = db_insert ( 'gb_group' )->fields ( array (
					'g_name' => $arg1[g_name],
					'g_pic' => $arg1[g_pic],
					'created' => time (),
					'createdby'=>$arg1[rid]
			)
					)->execute ();
					$group_id=db_query("SELECT g_id from gb_group where g_name='$arg1[g_name]'")->fetchAll();
		
					try{
						$inst_grp = db_insert ( 'gb_group_members' )->fields ( array (
								'g_id' =>$group_id[0]->g_id,
								'rid' =>$arg1[rid],
								'createdby' =>$arg1[rid],
								'created' => time (),
								'is_admin' =>1,
								
						)
								)->execute ();
								$output['rid']=$inst_grp;
								
					}catch  ( Exception $e ){
						print_r($e);
						$output['error']="Could not insert record";
						
					}
		}
		catch ( Exception $e ) {
			$output['error']="Could not insert record";
				
		}
	}
	else{
		$output['error']="User not Available ";
	}
	
}else{
	
	$output['error']="Insert currect Group Name format ";
	
	
}
return $output;
}
function groupJoin($arg1) {
	
	$output=array();
	try {
		$inst_grp_member = db_insert ( 'gb_group_members' )->fields ( array (
								'g_id' =>$arg1[g_id],
								'rid' =>$arg1[rid],
								'is_admin'=>0,
								'created' => time ()
								)
								)->execute ();
								$output['gm_id']=$inst_grp_member;
								$output['g_id']=$arg1[g_id];
								$output['rid']=$arg1[rid];
	} catch (Exception $e) {
		
			$output['error']="Some exception errors";	
	
	}
	return $output;
}

/**
 * profile updted
 * f_name
 * l_name
 * email
 * password
 * 
 */
function profileupdated($arg4){
	$output=array();
	if(!empty($arg4)){
		$userdetail=db_query("SELECT rid,f_name,l_name,email,password from gb_user where rid='$arg4[rid]'")->fetchAll();
		
		try {
			echo $f_name=(isset($arg4[f_name]) && $arg4[f_name]!='')?$arg4[f_name]:$userdetail['f_name'];
			echo $l_name=(isset($arg4[l_name]) && $arg4[l_name]!='')?$arg4[l_name]:$userdetail['l_name'];
			echo $email=(isset($arg4[email]) && $arg4[email]!='')?$arg4[email]:$userdetail['email'];
			$user_detail_update=db_query("update  gb_user set f_name='".$f_name."',l_name='".$l_name."',email='".$email."' where rid='".$arg4[rid]."'")->execute();
			$output['rid']=$user_detail_update;
		} catch (Exception $e) {
			 $output['error']="some went error";
		}
	}
	return $output;
}