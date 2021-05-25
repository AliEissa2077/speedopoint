#pragma once
#ifndef CRUISECOMPANY_H
#define CRUISECOMPANY_H
#include <string>
class cruisecompany {
private:
	std::string name;
	float rating;
	float safetyRating;
	int priceRange;
    int ratingcount;
public:
	cruisecompany();
	cruisecompany(std::string name_, float rt, float srt, int range);
	void updateRating(int rt);
    std::string getName();
    int getRating();
    int getPriceRange();
    int getSafety();
};




#endif CRUISECOMPANY_H
