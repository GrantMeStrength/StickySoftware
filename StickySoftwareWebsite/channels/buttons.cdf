<?XML version="1.0"?>
<CHANNEL 
	HREF="mctp://192.168.0.2/channels/buttons.cdf" 
	BASE="http://192.168.0.2/channels/"
	SELF="http://192.168.0.2/channels/buttons.cdf"
	ID="Buttons"
>
	<TITLE>Buttons</TITLE>
	<ABSTRACT>Displays Big Buttons</ABSTRACT>
	<USAGE VALUE="MobileDesktopComponent"/>
    
	
    	<ITEMFORMAT VALUE=";Logo,Cont,Calc,Date,Notes,Inbox,Tasks,Voice,Channels"/>
   	<ITEM HREF="buttons.mcd" ID="Buttons_D">	
	<ITEMSCRIPT VALUE="Buttons_S"/>
    	</ITEM>	

	<CHANSCRIPT VALUE="Buttons_S"/>
	<ITEM HREF="http://192.168.0.2/channels/buttons.mcs" ID="Buttons_S">
	<USAGE VALUE="None"/>
	</ITEM>

    <ITEM HREF="http://192.168.0.2/channels/wcelogo.gif" ID="0" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but1.gif" ID="1" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but2.gif" ID="2" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but3.gif" ID="3" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but4.gif" ID="4" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but5.gif" ID="5" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but6.gif" ID="6" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but7.gif" ID="7" ISVISIBLE="NO"/>
    <ITEM HREF="http://192.168.0.2/channels/but8.gif" ID="8" ISVISIBLE="NO"/>

   
    	

    
    
    

	
    

</CHANNEL>