<?php

/**
 * [POST]::Function defined to obtain info regarding home based on logged in or not.
 * @param unknown $group
 */
function ws_masterlist($data) {

	$rtf = array();
	$masters_array = array();
	$group_name = $data [SERVICE_KEY_MASTER_GROUP];

	$masters_array = prepare_masters_list($group_name);
	
	if (! empty ( $masters_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_MASTER_ARRAY] = $masters_array;
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	
	
	// $rtf=$masters_array;
	return $rtf;
}

function ws_mobilelist($data) {

	$rtf = array();
	$detail_array = array();
	$detail_array = prepare_mobile_list($data);
	
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_PRODUCT_LIST] = $detail_array;
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}

	return $rtf;
}

function ws_mobiledetail($data) {

	$rtf = array();
	$detail_array = array();

	$detail_array = prepare_mobile_detail($data);

	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_PRODUCT_DETAIL] = $detail_array;
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}

	return $rtf;
}


function ws_top_product_list($data){
	
	
	$rtf = array();
	$detail_array = array();
	
	$detail_array = top_product_list($data);
	
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_LISTICAL_PRODUCTS] = $detail_array[SERVICE_KEY_LISTICAL_PRODUCTS];
		$rtf [SERVICE_KEY_LISTICAL_PAGE_TITLE] = $detail_array[SERVICE_KEY_LISTICAL_PAGE_TITLE];
		$rtf [SERVICE_KEY_LISTICAL_PAGE_IMAGE] = $detail_array[SERVICE_KEY_LISTICAL_PAGE_IMAGE];
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;
}	

function ws_deals_product_list($data){

	$rtf = array();
	$detail_array = array();
	$detail_array = deals_product_list($data);

	if (! empty ( $detail_array )) {
		
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_DEALS_PRODUCTS] = $detail_array;
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;
}


function ws_listicals_list($data){

	$rtf = array();
	$detail_array = array();

	$detail_array = listical_list($data);

	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_LISTICALS_LIST] = $detail_array[SERVICE_KEY_LISTICALS_LIST];
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;
}


/* function ws_filter_list($data){


	$rtf = array();
	$detail_array = array();

	$detail_array = listical_list($data);
	$rtf = array();
	$detail_array = array();
	
	$detail_array = filter_mongo_list($data);
	>>>>>>> Stashed changes
	
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		<<<<<<< Updated upstream
		$rtf [SERVICE_KEY_LISTICALS_LIST] = $detail_array[SERVICE_KEY_LISTICALS_LIST];
		=======
		$rtf [SERVICE_KEY_LISTICAL_PRODUCTS] = $detail_array[SERVICE_KEY_LISTICAL_PRODUCTS];
		$rtf [SERVICE_KEY_LISTICAL_PAGE_TITLE] = $detail_array[SERVICE_KEY_LISTICAL_PAGE_TITLE];
		$rtf [SERVICE_KEY_LISTICAL_PAGE_IMAGE] = $detail_array[SERVICE_KEY_LISTICAL_PAGE_IMAGE];
		>>>>>>> Stashed changes
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf; */



function ws_filter_list($data){
	$rtf = array();
	$detail_array = array();
	
	$detail_array = filter_mongo_list($data);
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_MOBILE_FILTER] = $detail_array[SERVICE_KEY_MOBILE_FILTER];
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;

	
}

function ws_search_list($data){
	$rtf = array();
	$detail_array = array();

	$detail_array = search_mongo_list($data);
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_SEARCH_LIST] = $detail_array[SERVICE_KEY_SEARCH_LIST];
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;
}

function ws_latest_reviews($data){
	$rtf = array();
	$detail_array = array();

	$detail_array = get_latest_reviews($data);
	if (! empty ( $detail_array )) {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_SUCCESS;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_SUCCESS_TEXT;
		$rtf [SERVICE_KEY_SEARCH_LIST] = $detail_array;
		$rtf ['total_product_reviews'] = $detail_array['total_product_reviews'];
	} else {
		$rtf [SERVICE_KEY_STATUS] = SERVICE_STATUS_FAIL;
		$rtf [SERVICE_KEY_STATUS_MESSAGE] = SERVICE_STATUS_FAIL_TEXT;
	}
	return $rtf;
}
