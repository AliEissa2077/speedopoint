#pragma once
#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class airline {
private:
	std::string name;
	int rating;
	int safetyrating;
	int pricerange;
public:
	airline();
	airline(std::string name_, int rt, int srt, int range); // rt -> rating, srt-> safety rating
	void setRating(int rt);
	void setSRating(int srt);
	void setRange(int range);
	void setName(std::string name_);
	int getRating();
	int getSRating();
	int getRange();
	std::string getName();
	void updateRating(int rt); //updates rating after user gives review
};

#endif AIRLINE_H