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
    bool beach;
	bool pool;
	int rating_counter;
public:
	hotel();
    hotel(std::string name_, country c, int index, int range, bool pool_);
	void updateRating(float rt);
    int getRating();
    bool getPool();
    bool getBeach();
    int getRatingsCount();
    int getPriceRange();
    std::string getName();
};

#endif HOTEL_H
