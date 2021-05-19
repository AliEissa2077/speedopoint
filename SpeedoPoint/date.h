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
    float operator-(float inp) {
        float var1 = 0;
        var1 += day*24;
        var1 += hour;
        var1 += minute/60;
        return inp - var1;
    }
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();

};



#endif DATE_H
