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
    stop(country location, int index, date dt);
    stop(country location, int index, airport airl, date dt);
    void add_stop(country location, int index, date dt);
    date getTime();
    airport getAirport();
    int getIndex();
    void setAirport(airport air);
    country getLoc();
    ~stop();
};

#endif STOP_H
