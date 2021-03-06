<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */

global $user;
if ($user->uid) { // this user is already logged in
	//print "Access Denied: You do not have access to this page.";
} else {
	drupal_set_message("Access Denied: Please Login");
	$dest = drupal_get_destination();
	print_r($dest);
	drupal_goto('user', array('query' => $dest)); // this remembers where the user is coming from
}

?>
<?php 
if ($user->uid) {
  print 'Welcome '.$user->name.'!';
}
else {
  print 'Welcome, Guest!';
}
?>
<style>
table, th, td {
	border: 1px solid black;
	border-collapse: collapse;
}

th, td {
	padding: 5px;
	text-align: left;
}

.gateway-table {
	width: 100%;
}

table.gateway-table td {
	width: 50%;
}
</style>

<header id="navbar" role="banner"
	class="<?php print $navbar_classes; ?>">
	<div class="<?php print $container_class; ?>">
		<div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left"
				href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
				<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
			</a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
        <a class="name navbar-brand" href="<?php print $front_page; ?>"
				title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <button type="button" class="navbar-toggle"
				data-toggle="collapse" data-target=".navbar-collapse">
				<span class="sr-only"><?php print t('Toggle navigation'); ?></span>
				<span class="icon-bar"></span> <span class="icon-bar"></span> <span
					class="icon-bar"></span>
			</button>
      <?php endif; ?>
    </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
			<nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
		</div>
    <?php endif; ?>
  </div>
</header>

<div class="main-container <?php print $container_class; ?>">

	<header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header>
	<!-- /#page-header -->

	<div class="row">
  
    <?php if (!empty($page['block_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['block_first']); ?>
      </aside>
		<!-- /#sidebar-first -->
    <?php endif; ?>
       
    <?php if (!empty($page['block_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['block_second']); ?>
      </aside>
		<!-- /#sidebar-first -->
    <?php endif; ?>
    
    <?php if (!empty($page['block_third'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['block_third']); ?>
      </aside>
		<!-- /#sidebar-first -->
    <?php endif; ?>
    
   <?php if (!empty($page['block_fourth'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['block_fourth']); ?>
      </aside>
		<!-- /#sidebar-first -->
    <?php endif; ?>
    
    <section <?php print $content_column_class; ?>>
 
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php  // print render($page['content']); ?>
    </section>
    
       <?php 
     
       if(user_is_logged_in()){
  if( !in_array('traders-help', $user->roles)){
        ?>
    <h2>Product Status</h2>

		<table  width="100%">
			<tr>
				<th>ProductName</th>
				<th>Qty Remain</th>
				<th>Remaing Product INR</th>
				<th>Total Selling INR</th>
				<th colspan="2">Net Profit INR</th>

			</tr>
		

   <?php
				
$result = db_query ( "select 
   		o.mid,
   		sum(o.net_profit) SUM ,sum(o.total_price) as total_sell_price ,
   		i.qty,
   		p.total_price,
   		m.name
   		from st_order 
   		as o left join st_inventery as i 
   		on o.mid=i.mid left join st_price 
   		as p on i.mid=p.mid left join st_material 
   		as m on p.mid=m.mid group by o.mid" )->fetchAll ();
				?>
   <?php
				
$total = 0;
				foreach ( $result as $value ) {
					
					$total = $value->SUM + $total;
					?>
   <tr>
				<td><?php echo $value->name;?></td>
				<td><?php echo $value->qty; ?></td>
				<td><?php echo $value->total_price;?></td>
				<td><?php echo $value->total_sell_price; ?></td>
				<td colspan="2"><?php echo $value->SUM;?></td>

			</tr>
    <?php }?>
    
      <tr>
				<td colspan="4">Total Net profit</td>
				<td colspan="2"><?php echo $total;?></td>

			</tr>

		</table>
   <?php } ?>
  
   
    <h2>Borrower Orderwise</h2>

		<table width="100%">
			<tr>
				<th>OID</th>
				<!-- <th>User ID</th> -->
				<th>User Name</th>
				<th>Pay</th>
				<th>Pay Pending</th>
				<th>Pay Status</th>
				<th>Phone</th>
			</tr>
    <?php
							
$result = $result = db_query ( "select * from st_order as o inner join st_borrower as b on o.oid=b.oid where pay_status=2 order by b.payment_remaining asc " )->fetchAll ();
							
							foreach ( $result as $res ) {
								
								$user_id = $res->user_id;
								$res1 = get_data_by_pks ( 'st_customer', $user_id, 'cus_id' );
								?>
    		 <tr>
				<td><?php echo $res->oid;?></td>
				<td><?php echo ucfirst($res1->f_name.''.$res1->l_name);?></td>
				<td><?php echo $res->pay;?></td>
				<td><?php echo $res->payment_remaining;?></td>
				<td><?php echo product_status($res->pay_status);?></td>

				<td><?php echo $res1->phone;?></td>

			</tr>
    <?php }?>	<table>
    
   
    <h2>Borrower</h2>

			<table  width="100%">
				<tr>
					<th>Username</th>
					<!-- <th>User ID</th> -->

					<th>Payment Remaing</th>


				</tr>
    <?php
				
$resultb = db_query ( "select user_id,sum(payment_remaining) SUM from st_borrower as b where b.user_id in (select o.cus_id from st_order as o where o.pay_status=2 group by o.cus_id) group by b.user_id " )->fetchAll ();
				
				foreach ( $resultb as $res ) {
					
					$user_id = $res->user_id;
					$res1 = get_data_by_pks ( 'st_customer', $user_id, 'cus_id' );
					
					?>
    		 <tr>
					<td><?php echo ucfirst($res1->f_name);?></td>
					<td><?php echo $res->SUM ?></td>


				</tr>
    <?php }?>	<table>
    <?php }?>
    
    
    <?php if( !in_array('traders-help', $user->roles)){ ?>  
    
     <h2>Top 10 Customers</h2>

		<table width="100%">
			<tr>
			
				<!-- <th>User ID</th> -->
				<th>Cusomer name</th>
				<th>Net Profit</th>
				
			</tr>
    <?php
							
$result = $result = db_query ( "select sum(net_profit) SUM,o.cus_id  from st_order as o group by cus_id order by SUM DESC limit 10;


		" )->fetchAll ();
							
							foreach ( $result as $res ) {
								
								//$user_id = $res->user_id;
							$res1 = get_data_by_pks ( 'st_customer', $res->cus_id, 'cus_id' );
								?>
    		 <tr>
				<td><?php echo ucwords($res1->f_name.' '.$res1->l_name)?></td>
				<td><?php echo $res->SUM?></td>
				


			</tr>
    <?php }?>	<table>
    
   <?php }?>
    
    <?php if (!empty($page['sidebar_second'])): ?>

      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>
				<!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
				<div class="row">
  
  
   <?php if (!empty($page['middle'])): ?>

      <aside class="col-sm-12" role="complementary">
        <?php print render($page['middle']); ?>
      </aside>
					<!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
				</div>
 
<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php print $container_class; ?>">
 
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>
