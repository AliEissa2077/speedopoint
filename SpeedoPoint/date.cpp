#include "date.h"

date::date()
{

}

date::date(int d, int m, int y, int h, int min)
{
	day = d;
	month = m;
	year = y;
	hour = h;
	minute = min;
}

date::date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int date::getYear()
{
	return year;
}

int date::getMonth()
{
	return month;
}

int date::getDay()
{
	return day;
}

int date::getHour()
{
	return hour;
}

int date::getMinute()
{
	return minute;
}