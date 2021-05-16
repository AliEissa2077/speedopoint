#pragma once
#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class airline {
private:
	std::string name;
	float rating;
	float safetyrating;
	int pricerange;
	int rating_counter;
public:
	airline();
    airline(std::string name_, int range, float srt);
	void setRating(float rt, int num);
	void setSRating(float srt);
	void setRange(int range);
	void setName(std::string name_);
	int getRating();
	int getSRating();
	int getRange();
	std::string getName();
    void updateRating(float rt); //updates rating after user gives review
};

#endif AIRLINE_H
