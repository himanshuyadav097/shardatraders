<?php

/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/productlist Product List
 * @apiDescription  This API is used to get the info related to any category. 
 *  
 * @apiName Product List
 * @apiGroup Bestby
 * 
 * @apiParam {int} category Category Id.
 * @apiParam {int} limit Number of records to be fetched
 * @apiParam {int} page 
 * @apiParam {int} type 
 * @apiParam {int} sort Sort the records in (ASC) Ascending/ (DESC)Descending order.  
 * 
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 * 
 * @apiSampleRequest /api/v1/bestby/productlist
 * 
 **/
function mobile_list_apidoc() {
	mobile_list($data);
}


/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/product_detail Product Detail
 * @apiDescription  Product Detail api
 *
 * @apiName Product Detail
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/product_detail
 *
 **/
function mobile_detail_apidoc() {
	mobile_detail($data);
}


/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/top_listical Top Listical
 * @apiDescription Top Listical
 *
 * @apiName Top Listical
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/top_listical
 *
 **/
function listical_detail_apidoc() {
	listical_detail($data);
}



/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/deals_of_day Deals of the Day
 * @apiDescription Deals of the Day
 *
 * @apiName Deals of the Day
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/deals_of_day
 *
 **/
function deals_of_day_apidoc() {
	deals_of_day($data);
}



/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/listicals Listicals
 * @apiDescription Listicals
 *
 * @apiName Listicals
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/listicals
 *
 **/
function listical_completelist_apidoc() {
	listical_completelist($data);
}


/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/filer Filter
 * @apiDescription Filter
 *
 * @apiName Filter
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/filer
 *
 **/
function filter_detail_apidoc() {
	filter_detail($data);
}



/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/search_filter Search Filter
 * @apiDescription Search Filter
 *
 * @apiName Search Filter
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/search_filter
 *
 **/
function search_list_apidoc() {
	search_list($data);
}



/**
 * @apiVersion 1.0.0
 * @api {get} http://ecomm.com/api/v1/bestby/latest_reviews Latest Reviews
 * @apiDescription Latest Reviews
 *
 * @apiName Latest Reviews
 * @apiGroup Bestby
 *
 * @apiParam {int} add Add Values
 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 *
 * @apiSampleRequest /api/v1/bestby/latest_reviews
 *
 **/
function latest_reviews1_apidoc() {
	latest_reviews1($data);
}






/**
 * @apiVersion 1.0.0
 * @api {post} http://engage.com/v1/trivia/home Home (DOCUMENATION DEMO)
 * @apiDescription  This API is used to get the info related to home. In case isLoggedIn = 1 then his login token will be validated.
 * In case user is not logged in(isLoggedIn = 0) then return dasboard information accrodingly
 *
 * @apiName (DOCUMENATION DEMO) Home 
 * @apiGroup DEMO
 *
 *
 * @apiParam {int} uid User game uniqe id
 * @apiParam {char} deviceType User's device type. A= Android, I = Iphone, W = Web, S= SSO
 * @apiParam {int} uqid User's unique device id
 * @apiParam {int} isLoggedIn User is logged in or doing anonymous browsing. 0 = Anon browsing, 1 for logged in
 * @apiParam {int} loginType Login type of user f=Facebook, s=SSO, t=twitter. In case isLoggedIn flat is on this field is mandatory. In case user is connected with SSO pass SSO s, in case we connect with facebook pass f.
 * @apiParam {String} [loginId] loginType corresponding login ID
 * @apiParam {String} [loginToken] in case login Token is needed

 *
 * @apiSuccessExample {int} Success Response
 * HTTP/1.1 200 OK
 * status : "1"
 * message : "Home/Dashboard"
 * @apiSuccess {int}    status 0 means data fetched, 1 means something wrong happened
 * @apiSuccess {String} message Success or fail message.
 * @apiParam {int} uid User game uniqe id.
 * @apiSuccess {String[]} sponsor Sponsor data
 * @apiSuccess (Sponsor) {String} name Sponser name
 * @apiSuccess (Sponsor) {String} img_url Sponser image url
 * @apiSuccess {String[]} user User data array
 * @apiSuccess (user) {String} [name] Name of the user
 * @apiSuccess (user) {String} [post] Post of the user
 * @apiSuccess (user) {String} [country] Country name
 * @apiSuccess (user) {String} [profile_img]  URL of profile image. Download it and save it
 * @apiSuccess (user) {int} game_count="0"  Game played
 * @apiSuccess (user) {int} week_rank="0"  Weekly rank
 * @apiSuccess (user) {int} month_rank="0"  Month rank
 * @apiSuccess (user) {String} approx_rank Approximate rank of user in case user is not logged in
 * @apiSuccess {String[]} game Upcoming and closed game information
 * @apiSuccess (game) {int} isCurrentPlayed 0 if user has not played the current active game else 1
 * @apiSuccess (game) {int} currentGameId Current active game id. 0 in case no active game is there
 * @apiSuccess (game) {int} nextGameId Next game id. 0 in case no next game is announced
 * @apiSuccess (game) {String} nextGameTime Time in dd/mm/yyyy h:i:s format. Note that game time will be in IST timezone. Will need to settle the timezone of phone
 * @apiSuccess (game) {int} isShowResult 0 if user has already shown result else 1 i.e new result is annouced
 * @apiSuccess (game) {int} resultGameId Game id for which result has been announced
 * @apiSuccess (game) {int} resultMsg Message that need to be shown
 *
 * @apiSampleRequest /api/v1/trivia/home
 *
 **/
function home_apidoc() {
	home($data);
}
