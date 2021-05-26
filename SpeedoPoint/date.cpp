#include "date.h"


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

date::date(int d, int m, int y, int h, int min)
{
    day = d;
    month = m;
    year = y;
    minute = min;
    hour = h;

}
date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
    minute = 0;
    hour = 0;
}
date::date() {
    day = 0;
    month = 0;
    year = 0;
    minute = 0;
    hour = 0;
}
