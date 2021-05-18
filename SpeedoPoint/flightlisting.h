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
    airline airlne;
    stop* stops;
	int stopnum;
	date dep;
	date arr;
	int pricepertraveller;
	std::string cabin;
	std::string plane;
	int carronW;
	int checkedBaggageW;
	int additionalBagPrice;
public:
	flightlisting();
    flightlisting(airline air, stop* stp, int sptnum, date departure, date arrival, int price, std::string cabin_, std::string planeModel, int carryOn, int CheckedW, int additionalWPrice);
	flightticket reserve(user acc);
    int getPriceperTraveller();
    int getAirlineRating();
    float CalculateFlightDur();
    float _CalculateFlightDur(stop* stp); //recursive
    country getDepCountry();  // makes a new country objects with country name and one city in the vector (the airport city loc) and returns it
    country getArrCountry();  // +1

    bool verifyFromAndToLocs(string locdep, string citydep, string locArrive, string cityArrive);

};



#endif FLIGHTLISTING_H
