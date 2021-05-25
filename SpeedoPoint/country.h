#pragma once
#ifndef COUNTRY_H
#define COUNTRY_H
#include <vector>
#include <string>
#include <iostream>

class country {
private:
	std::string name;
	bool banned;
	std::vector<std::string> cities;
	int x_coordinate;
	int y_coordinate;

public:
    country(){}
	country(std::string name_, bool ban);
	void addCity(std::string city);
    std::string getName();
    std::vector<std::string> getCities();
	int get_x_coordinate(int x);
	int get_y_coordinate(int y);
};

#endif COUNTRY_H
