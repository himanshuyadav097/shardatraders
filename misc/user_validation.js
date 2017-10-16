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
	
	if(jQuery( "#edit-phone" ).val() == "")
	{
		alert("Phone number is required");
		  jQuery("#edit-phone").parent().addClass('has-error');
	      return false;  
	  }  
	 else  
	 {  
		 jQuery("#edit-phone").parent().removeClass('has-error');
	 }
		var d=ValidatePhone("#edit-phone");
				 if(d=='F')
				 {  
		        alert("Phone number should be and minimum 10 or less than 16 digits");  
		        jQuery("#edit-phone").parent().addClass('has-error');
			      return false;  
				 }  
				 else  
				 {  
							 jQuery("#edit-phone").parent().removeClass('has-error');
				 }
	
}

/*$("#edit-m-unit-price").blur(function () {

    alert("Handler for .blur() called.");

});*/

jQuery(document).ready(function(){
	
	jQuery("#edit-unit-prices, #edit-qty, #edit-unit").blur(function(){  
		var material_value = jQuery("#edit-qty").val();
		var material_price = jQuery("#edit-unit-prices").val();
		var material_total = '';
		var material_unit = jQuery("#edit-unit").val();
		
		if(material_value != '' && material_price != '' && material_unit != '0')
			{
				material_total = material_value * material_price;
			}
		jQuery("#edit-total-price").val(material_total);
		if(material_unit == 0)
		{
			jQuery("#edit-unit").css("border", "1px solid red");
			return false;
		}
	else
		{
			jQuery("#edit-unit").css("border", "1px solid #ccc");
		}
    });  
});  
jQuery(document).ready(function(){
	
	jQuery("#edit-base-price, #edit-qty").blur(function(){  
		var material_value = jQuery("#edit-qty").val();
		var material_price = jQuery("#edit-base-price").val();
		var material_total = '';
	//	var material_cost_price = '';
	//	var Netprofit = '';

	//	var material_unit = jQuery("#edit-unit").val();
		
		if(material_value != '' && material_price != '' )
			{
				material_total = material_value * material_price;
				//material_cost_price = material_value * 272;
				//Netprofit = material_total - material_cost_price;
		}
		jQuery("#edit-total-price").val(material_total);
		
		//jQuery("#edit-cost-price").val(material_cost_price);
		
		//jQuery("#edit-net-profit").val(Netprofit);

		if(material_price == 0)
		{
			//jQuery("#edit-base-price").css("border", "1px solid red");
			return false;
		}
	else
		{
			jQuery("#edit-base-price").css("border", "1px solid #ccc");
		}
    });  
	
	
});

//Not enter numeric Number

jQuery(document).ready(function(){

	jQuery("#edit-f-name ,#edit-l-name").keypress(function(event){
	        var inputValue = event.which;
	        // allow letters and whitespaces only.
	        if(!(inputValue >= 65 && inputValue <= 120) && (inputValue != 32 && inputValue != 0)) { 
	            event.preventDefault(); 
	        }
	    });  
	});

//Validate phone number function

function ValidatePhone(ids) {
	
    var phoneRegExp = /^((\+)?[1-9]{1,2})?([-\s\.])?((\(\d{1,4}\))|\d{1,4})(([-\s\.])?[0-9]{1,12}){1,2}$/;
    var phoneVal = jQuery(ids).val();
    var numbers = phoneVal.split("").length;
    if (10 <= numbers && numbers <= 16 && phoneRegExp.test(phoneVal)) {
        return 'S';
    }
    else{
    	return 'F';
    }
    }


//Validate enter only integer value

jQuery(document).ready(function () {
	  //called when key is pressed in textbox
	jQuery("#edit-qty,#edit-unit-prices,#edit-total-price,#edit-base-price,#edit-sale-price").keypress(function (event) {
	     //if the letter is not digit then display error and don't type anything
	     if (event.which != 8 && event.which != 0 && (event.which < 48 || event.which > 57)) {
	        //display error message
	    	 jQuery("#errmsg").html("Digits Only").show().fadeOut("slow");
	               return false;
	    }
	   });
	});