Action()
{

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
		"URL=http://computer-database.gatling.io/computers/338", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?p=2", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("delete", 
		"Action=http://computer-database.gatling.io/computers/338/delete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/338", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("UA-CPU", 
		"AMD64");

	lr_think_time(4);

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(36);

	web_url("12", 
		"URL=http://computer-database.gatling.io/computers/12", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("12_2", 
		"Action=http://computer-database.gatling.io/computers/12", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/12", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value=Apple III1111", ENDITEM, 
		"Name=introduced", "Value=2001-01-01", ENDITEM, 
		"Name=discontinued", "Value=2020-03-22", ENDITEM, 
		"Name=company", "Value=2", ENDITEM, 
		LAST);

	return 0;
}