#pragma once
#ifndef STOP_H
#define STOP_H
#include "country.h"
#include "airline.h"
#include "airport.h"
#include "date.h"
class stop {
private:
	country loc;
	int cityIndex;
    airport aPort;
    //airline airlne;
	date time;

public:
    stop* next;
	stop();
    stop(country location, int index, airport airl, date d);
    void add_stop(country locatiuon, int index, airport airl, date d);
    date getTime();
    airport getAirport();
    int getIndex();
    country getLoc();


};

#endif STOP_H
