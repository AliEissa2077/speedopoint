#pragma once
#ifndef CRUISECOMPANY_H
#define CRUISECOMPANY_H
#include <string>
class cruisecompany {
private:
	std::string name;
	int rating;
	int safetyRating;
	int priceRange;
    int ratingcount;
public:
	cruisecompany();
	cruisecompany(std::string name_, int rt, int srt, int range);
	void updateRating(int rt);
};




#endif CRUISECOMPANY_H
