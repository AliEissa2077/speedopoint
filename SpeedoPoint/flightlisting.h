#pragma once
#ifndef FLIGHTLISTING_H
#define FLIGHTLISTING_H
#include "airline.h"
#include "stop.h"
#include "date.h"
#include <string>
#include "user.h"
#include "flightticket.h"
class flightlisting {
private:
    string code;
    airline* airlne;
    stop* stops;
	int stopnum;
	date dep;
	date arr;
	int pricepertraveller;
    std::string cabin; //business, economy
	std::string plane;
	int carronW;
	int checkedBaggageW;
	int additionalBagPrice;
    bool refundable;
    bool oneway;
public:
    flightlisting();
    flightlisting(string code_, airline* air, stop* stp, int sptnum, date departure, date arrival, int price, std::string cabin_, std::string planeModel, int carryOn, int CheckedW, int additionalWPrice, bool ref, bool onew);
    flightticket* reserve(user* acc, int adults, int children, date d);
    flightticket* reserve(user* acc, int adults, int children, date d, date d2);
    int getPriceperTraveller();
    int getAirlineRating();
    float CalculateFlightDur();
    float _CalculateFlightDur(stop* stp); //recursive
    country getDepCountry();  // makes a new country objects with country name and one city in the vector (the airport city loc) and returns it
    int getDepCityIndex();
    int getArrCityIndex();

    string getDepTime();
    string getArrTime();
    country getArrCountry();  // +1
    airline* getAirline();
    float subtract(date d, date f);
    bool isOneW();
    bool isRefundable();

    bool verifyFromLocs(string locdep, string citydep);
    void addStop(country c, int i);

};



#endif FLIGHTLISTING_H
