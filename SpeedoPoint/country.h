#pragma once
#ifndef COUNTRY_H
#define COUNTRY_H
#include <vector>
#include <string>
#include <iostream>

struct Coords {
    int x = 0;
    int y = 0;
    Coords(int a, int b) : x(a) , y(b) {}
};

class country {
private:
	std::string name;
    //std::vector<std::string> banned;
    bool banned;
	std::vector<std::string> cities;

    std::vector<Coords> coords;


public:
    country(){}
	country(std::string name_, bool ban);
	void addCity(std::string city);
    std::string getName();
    std::vector<std::string> getCities();
    std::vector<Coords> get_coordinates();
};

#endif COUNTRY_H
