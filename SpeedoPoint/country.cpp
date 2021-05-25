#include "country.h"



country::country(std::string name_, bool ban)
{
	name = name_;
	banned = ban;
}

void country:: addCity(std::string city)
{
	bool flag = false;
	for (auto x : cities)
	{
		if (x == city)
		{
			flag = true;
		}
	}

	if (!flag)
	{
		cities.push_back(city);
	}
}

std::string country::getName()
{
	return name;
}

std::vector<std::string>country::getCities()
{
	return cities;
}

std::vector<Coords> country::get_coordinates() {
    return coords;
}
