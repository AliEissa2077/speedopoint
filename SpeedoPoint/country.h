#pragma once
#ifndef COUNTRY_H
#define COUNTRY_H
#include <vector>
#include <string>

class country {
	std::string name;
	bool banned;
	std::vector<std::string> cities;
public:
	country();
	country(std::string name_, bool ban);
	void addCity(std::string city);
};

#endif COUNTRY_H