#pragma once
#ifndef DATE_H
#define DATE_H
#include <ctime>

class date {
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	date();
	date(int d, int m, int y, int h, int min);
};



#endif DATE_H