<?XML version="1.0"?>
<CHANNEL 

	HREF="mctp://www.sticky.co.uk/channels/countdown.cdf" 
	BASE="http://www.sticky.co.uk/channels/"
	SELF="http://www.sticky.co.uk/channels/countdown.cdf"
	ID="CountDown"
>
    <!-- LOCALIZE TITLE VALUE -->
    <TITLE>CountDown</TITLE>
    <ABSTRACT>Displays time until Y2K</ABSTRACT>
    <LOGO HREF="http://www.sticky.co.uk/channels/logo.gif" STYLE="IMAGE"/>
    <LOGO HREF="http://www.sticky.co.uk/channels/logo.gif" STYLE="IMAGE-WIDE"/>

    <SCHEDULE STARTDATE="1999-01-21">
	<INTERVALTIME DAY="7"/>
	<LATESTTIME DAY="4"/>
    </SCHEDULE>

    <USAGE VALUE="MobileDesktopComponent"></USAGE>
    <CHANSCRIPT VALUE="CSCount"/>
	
    <ITEM HREF="http://www.sticky.co.uk/channels/countdown.mcs" ID="CSCount" ISVISIBLE="NO"><USAGE VALUE="NONE"/></ITEM>
   
</CHANNEL>
