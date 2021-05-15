#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H



#include "country.h"

class airport {
private: 
	country country;
	int cityIndex;
public:
	airport();
	airport(country ctry, int index);
	country getCountry();
	int getIndex();
};
#endif AIRPORT_H