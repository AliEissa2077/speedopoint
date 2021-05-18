#pragma once
#ifndef STOP_H
#define STOP_H
#include "country.h"
#include "airline.h"
#include "date.h"
class stop {
private:
	country loc;
	int cityIndex;

    airline airlne;
	date time;

public:
    stop* next;
	stop();
    stop(country location, int index, airline airl, date d);
    void add_stop(country locatiuon, int index, airline airl, date d);
    date getTime();
    airline getAirline();
    int getIndex();
    country getLoc();


};

#endif STOP_H
