#pargma once
#ifndef STOP_H
#define STOP_H
#include "country.h"
#include "airline.h"
#include "date.h"
class stop {
private:
	country loc;
	int cityIndex;
	stop* next;
	airline airline;
	date time;
public:
	stop();
	stop(country locatiuon, int index, airline airl, date date);
	void add_stop(country locatiuon, int index, airline airl, date date);
};

#endif STOP_H