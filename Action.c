Action()
{

	
		web_reg_save_param_ex(
		"ParamName=CompNameRandom",
		"LB=<td><a href=\"/computers/",
		"RB=\">",
		"Ordinal={RandomNumber}",
		SEARCH_FILTERS,
		LAST);
	
	
	web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("Next &rarr;", 
		"URL=http://computer-database.gatling.io/computers?p=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	
		web_reg_save_param_ex(
		"ParamName=CompNameDelete",
		"LB=<td><a href=\"/computers/",
		"RB=\">",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	

	web_url("Next &rarr;_2", 
		"URL=http://computer-database.gatling.io/computers?p=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?p=1", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(7);

	web_url("Belle", 
		"URL=http://computer-database.gatling.io/computers/{CompNameDelete}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?p=2", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("delete", 
		"Action=http://computer-database.gatling.io/computers/{CompNameDelete}/delete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/{CompNameDelete}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		LAST);

	lr_think_time(36);
	
		web_reg_save_param_ex(
		"ParamName=Name",
		"LB=\"name\" value=\"",
		"RB=\" ",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	/*
		web_reg_save_param_regexp(
		"ParamName=Name",
		"RegExp=<input type=\"text\" id=\"name\" name=\"name\" value=\"(.*)\" >",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	*/

	web_url("12", 
		"URL=http://computer-database.gatling.io/computers/{CompNameRandom}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("12_2", 
		"Action=http://computer-database.gatling.io/computers/{CompNameRandom}", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/{CompNameRandom}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value={Name}1", ENDITEM, 
		"Name=introduced", "Value={Date}", ENDITEM, 
		"Name=discontinued", "Value={CurrentDate}", ENDITEM, 
		"Name=company", "Value={Company}", ENDITEM, 
		LAST);

		lr_output_message("Comment: %s",lr_eval_string("{CompNameRandom}"));
		lr_output_message("Comment: %s",lr_eval_string("{RandomNumber}"));
	    lr_output_message("Comment: %s",lr_eval_string("{Name}1"));
	    lr_output_message("Comment: %s",lr_eval_string("{Company}"));
	    lr_output_message("Comment: %s",lr_eval_string("{Date}"));
	    lr_output_message("Comment: %s",lr_eval_string("{CurrentDate}"));

	
	
	return 0;
}