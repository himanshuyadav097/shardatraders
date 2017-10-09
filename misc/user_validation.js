var root_base_url =location.protocol + "//" + location.host+'/';
var specialChars = "<>@!#$%^&*()_+[]{}?:;|'\"\\,./~`-=";
var specialChars_WithNumber= "<>@!#$%^&*()_+[]{}?:;|'\"\\,./~`-=0123456789";
var specialChars_withOut_at = "<>!#$%^&*()[]{}?:;|'\"\\,/~`=";
function register_user_validation()
{
	
	if(jQuery( "#edit-f-name" ).val() == "")
	{
		alert("First name is required");
		jQuery("#edit-f-name").parent().addClass('has-error');
		return false;
	}else{
		jQuery("#edit-f-name").parent().removeClass('has-error');
	}
	
	if(jQuery( "#edit-l-name" ).val() == "")
	{
		alert("Last name is required");
		jQuery("#edit-l-name").parent().addClass('has-error');
		return false;
	}else{
		jQuery("#edit-l-name").parent().removeClass('has-error');
	}
	
	if(jQuery( "#address" ).val() == "")
	{
		alert("address type is required");
		jQuery("#address").parent().addClass('has-error');
		return false;
	}else{
		jQuery("#address").parent().removeClass('has-error');
	}
		 
	
				
    }
