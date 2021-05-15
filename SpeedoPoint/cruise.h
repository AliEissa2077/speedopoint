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

class cruise {
	date start;
	date end;
	std::string cruiseModel;
	int pricePerPerson;
	cruisecompany company;
	country depCountry;
	country arrCountry;
	int arrivalCityIndex;
	stop stops;
	std::string suiteType;
public:
	cruise();
	cruise(date start_, date end_, std::string model, int price, country dep, country arr, int index, stop stop, std::string type);
	cruisereservation reserve(user acc);
};

#endif CRUISE_H