#pragma once
#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include "country.h"


class hotel {
private:
	std::string name;
	country country;
	int cityIndex;
	float rating;
	int priceRange;
	bool pool;
	int rating_counter;
public:
	hotel();
	hotel(std::string name_, country ctry, int index, int range, bool pool_);
	void updateRating(float rt);
};

#endif HOTEL_H