#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H



#include "country.h"

class airport {
private: 
    std::string name;
    country ctry;
	int cityIndex;
public:
	airport();
    airport(std::string airport_name, country count, int index);
	country getCountry();
	string getName();
	int getIndex();
};
#endif AIRPORT_H
