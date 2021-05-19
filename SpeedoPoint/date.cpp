#include "date.h"

int getYear();
int getMonth();
int getDay();
int getHour();
int getMinute();




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

}