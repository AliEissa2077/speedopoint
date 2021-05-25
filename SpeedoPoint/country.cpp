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

int country:: get_x_coordinate(int x)
{
	return x;
}

int country::get_y_coordinate(int y)
{
	return y;
}
