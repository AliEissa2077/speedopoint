#pragma once
#ifndef CRUISE_H
#define CRUISE_H
#include "date.h"
#include "cruisecompany.h"
#include "country.h"
#include <string>
#include "stop.h"
#include "cruisereservation.h"
#include "user.h"
#include "user.h"
#include "country.h"
#include "reservation.h"

class cruise {
private:
	date start;
	date end;
	std::string cruiseModel;
	int pricePerPerson;
	cruisecompany company;
	country depCountry;
    int depCityIndex;
	country arrCountry;
	int arrivalCityIndex;
    stop* stops;
	std::string suiteType;
public:
	cruise();
    cruise(date start_, date end_, std::string model, int price, country dep, country arr, int index, stop* stp, std::string type);
    cruisereservation* reserve(user* acc, int adult, int child);
    int getPricePerPerson();
    int getDuration();
    country getDepCountry();
    int getDepIndex();
    country getArrCountry();
    int getArrIndex();
    cruisecompany getCompany();
    float subtract(date d, date f);

    bool verifyLoc(string loc, string city);
};

#endif CRUISE_H
