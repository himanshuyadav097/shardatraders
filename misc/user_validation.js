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
	
	if(jQuery( "#edit-qty" ).val() == "")
	{
		alert("qty is required");
		jQuery("#edit-qty").parent().addClass('has-error');
		return false;
	}else{
		jQuery("#edit-qty").parent().removeClass('has-error');
	}
	
	if(jQuery( "#edit-pay-status" ).val() == "" || jQuery("#edit-pay-status" ).val() == '0')
	{
		alert("PAY STATUS is required");
		jQuery("#edit-pay-status").parent().addClass('has-error');
		return false;
	}else{
		jQuery("#edit-pay-status").parent().removeClass('has-error');
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

	jQuery("#st-inventery-add #edit-unit-prices, #st-inventery-add #edit-qty, #st-inventery-add #edit-unit").blur(function(){  
		

		var material_value = jQuery("#edit-qty").val();
		var material_price = jQuery("#edit-unit-prices").val();
		var material_total = '';
		var material_unit = jQuery("#edit-unit").val();
	
		if(material_value != '' && material_price != '' && material_unit != '0')
			{
			
			
				material_total = parseInt(material_value) * parseInt(material_price);
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
	
	/**
	 * 
	 * borrower pay and pay remiang validation
	 * 
	 */
	jQuery(".mobileval").keyup(function() {

		if (this.value.match(/[^0-9-+]/g)) {

			this.value = this.value.replace(/[^0-9-+]/g, '');
		}
		
		
	});
	

	
	jQuery("#st-order-add #edit-base-price, #st-order-add #edit-qty").blur(function(){  
		var material_value = jQuery("#edit-qty").val();
		var material_price = jQuery("#edit-qty-baseprice").val();
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

	/**
	 * borrower edit remaing payment 
	 * 
	 */
	jQuery("#st-borrower-add #edit-pay").blur(function(){  
	
		var total_price = jQuery("#edit-total-price").val();
		var pay = jQuery("#edit-pay").val();


		var pay_rem = '';
		
	//	var material_cost_price = '';
	//	var Netprofit = '';

	//	var material_unit = jQuery("#edit-unit").val();
		
		if(pay != ''  )
			{
			pay_rem = parseInt(total_price) - parseInt(pay);
				//material_cost_price = material_value * 272;
				//Netprofit = material_total - material_cost_price;
		}else
		if(pay != ''  &&  parseInt(total_price) < parseInt(pay))
		{
		pay_rem = 0;
			//material_cost_price = material_value * 272;
			//Netprofit = material_total - material_cost_price;
	}
		jQuery("#edit-payment-remaining").val(pay_rem);
		
		//jQuery("#edit-cost-price").val(material_cost_price);
		
		//jQuery("#edit-net-profit").val(Netprofit);

		if(pay == 0)
		{
			//jQuery("#edit-base-price").css("border", "1px solid red");
			return false;
		}
	else
		{
			jQuery("#edit-pay").css("border", "1px solid #ccc");
		}
    }); 
	
	jQuery("#edit-f-name ,#edit-l-name").keypress(function(e) {
		//alert("hii");
		//exit;
        var key = e.keyCode;
        if (key >= 48 && key <= 57) {
            e.preventDefault();
            console.log("hello");
        }
    });
	jQuery("#edit-qty,#edit-unit-prices,#edit-total-price,#edit-base-price,#edit-sale-price").keypress(function (event) {
	     //if the letter is not digit then display error and don't type anything
	     if (event.which != 8 && event.which != 0 && (event.which < 48 || event.which > 57)) {
	        //display error message
	    	 jQuery("#errmsg").html("Digits Only").show().fadeOut("slow");
	               return false;
	    }
	   });
	jQuery(" #edit-qty,#edit-qty-totall").blur(function(){  
		
		var qty_value = jQuery("#edit-qty").val();
		var qtybase_price = jQuery("#edit-qty-totall").val();
		if(parseInt(qty_value)> parseInt(qtybase_price)){
		

			 jQuery("#edit-qty").val('');
			
		}
		//jQuery("#edit-qty").val(material_total);

		
		//var edit-qty = jQuery("#edit-qty").val();
		//var edit-qty-baseprice = jQuery("#edit-qty-baseprice").val();
	//	var material_total = '';
		//var material_unit = jQuery("#edit-unit").val();
		
		/*if(edit-qty != '' && edit-qty-baseprice != '' && edit-qty > edit-qty-baseprice )
			{
				alert("wrong");
			}*/
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

 /**
  * Pay and pay remaing validation 
  * 
  * 
  */

function paycal_rem_pay(){
	
	
	var material_total_price= jQuery("#edit-total-price").val();
	var material_pay_total = jQuery("#edit-pay-totall").val();
	var material_remaing_pay = '';




	if(material_total_price != '' && material_pay_total != '' )
		{
		material_remaing_pay = parseInt(material_total_price) - parseInt(material_pay_total);
		
		

			
	}
	jQuery("#edit-payment_remaining-totall").val(material_remaing_pay);
	jQuery( "#edit-payment_remaining-totall" ).prop( "readonly", true );

}