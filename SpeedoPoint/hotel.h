#pragma once
#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include "country.h"


class hotel {
private:
	std::string name;
    country ctry;
	int cityIndex;
	float rating;
	int priceRange;
	bool pool;
	int rating_counter;
public:
	hotel();
    hotel(std::string name_, country c, int index, int range, bool pool_);
	void updateRating(float rt);
    int getRating();
};

#endif HOTEL_H
