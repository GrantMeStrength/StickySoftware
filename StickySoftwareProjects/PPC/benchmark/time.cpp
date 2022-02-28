//
// *** Time Related Functions ***
//

// This function reads the system clock, and
// discovers the time integers. It uses this
// to set JD, the Julian Date which is the 
// time value for all the settings.

#include "stdafx.h"

CTime LocalTime;

long When()
{

 int local_day;
 int local_month;
 int local_year;
 int local_hour;
 int local_minute;
 int local_second;

	LocalTime = CTime::GetCurrentTime();
	local_hour=LocalTime.GetHour();
	local_minute=LocalTime.GetMinute();
	local_second=LocalTime.GetSecond();
	local_year=LocalTime.GetYear();
	local_month=LocalTime.GetMonth();
	local_day=LocalTime.GetDay();

	return (local_second+(60*local_minute)+(3600*local_hour));

}

