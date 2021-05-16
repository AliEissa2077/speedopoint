#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H



#include "country.h"

class airport {
private: 
    country ctry;
	int cityIndex;
public:
	airport();
    airport(country count, int index);
	country getCountry();
	int getIndex();
};
#endif AIRPORT_H
