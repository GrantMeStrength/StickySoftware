//
// *** Time Related Functions ***
//

// This function reads the system clock, and
// discovers the time integers. It uses this
// to set JD, the Julian Date which is the 
// time value for all the settings.

#include "stdafx.h"

extern void CalculateJulian();

CTime LocalTime;

extern short int local_day;
extern short int local_month;
extern short int local_year;
extern short int local_hour;
extern short int local_minute;
extern short int local_second;
extern short int local_timezone;
extern short int local_daylight;

void When()
{
	LocalTime = CTime::GetCurrentTime();
	local_hour=LocalTime.GetHour();
	local_minute=LocalTime.GetMinute();
	local_second=LocalTime.GetSecond();
	local_year=LocalTime.GetYear();
	local_month=LocalTime.GetMonth();
	local_day=LocalTime.GetDay();
	CalculateJulian();
}

