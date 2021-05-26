#pragma once
#ifndef FLIGHTTICKET_H
#define FLIGHTTICKET_H
#include "date.h"
#include "airport.h"
#include <string>
//#include "user.h"
#include "payment.h"
//#include "flightlisting.h"

class flightlisting;
class user;

class flightticket {
private:
    flightlisting* listing;
	int adults;
	int children;
	bool one_way;
	date departure;
	date arrival;

    date returnTime;
	airport from;
	airport to;
	int max_baggage;
	std::string ticketType;
	bool refundable;
    user* acc;
    payment paymnt;
	int flight_duration;
public:
    bool rated = false;
	flightticket();
    flightticket(int ad, int child, bool oneway, date dep, date arr, airport f, airport t, std::string tictype, bool refund, user* account, float dur, payment pay, flightlisting* l);
    void setReturn(date d);
    flightlisting* getListing();
};







#endif FLIGHTTICKET_H
