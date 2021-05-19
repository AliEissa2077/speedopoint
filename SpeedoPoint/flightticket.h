#pragma once
#ifndef FLIGHTTICKET_H
#define FLIGHTTICKET_H
#include "date.h"
#include "airport.h"
#include <string>
//#include "user.h"
#include "payment.h"

class user;

class flightticket {
private:
	int adults;
	int children;
	bool one_way;
	date departure;
	date arrival;
	airport from;
	airport to;
	int max_baggage;
	std::string ticketType;
	bool refundable;
    user* acc;
	payment payment;
	int flight_duration;
public:
	flightticket();
    flightticket(int ad, int child, bool oneway, date dep, date arr, airport f, airport t, std::string tictype, bool refund, user* account, float dur);
};







#endif FLIGHTTICKET_H
