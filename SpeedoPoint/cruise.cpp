#include "cruise.h"

cruise::cruise()
{

}

cruise::cruise(date start_, date end_, std::string model, int price, country dep, country arr, int index, stop stop, std::string type)
{
	start = start_;
	end = end_;
	std::string cruisemodel = model;
	pricePerPerson = price;
	depCountry = dep;
	arrCountry = arr;
	arrivalCityIndex = index;
	stops = stop;
	std::string suiteType = type;

}

int cruise::getPricePerPerson()
{
	return pricePerPerson;
}


int cruise::getDuration()
{
	return (end - start);
}
country cruise::getDepCountry()
{
	return depCountry;
}
int cruise::getDepIndex()
{
	return depCityIndex;
}
country cruise::getArrCountry()
{
	return arrCountry;
}

int cruise::getArrIndex()
{
	return arrivalCityIndex;
}

cruisecompany cruise::getCompany()
{
	return company;
}

bool cruise::verifyLoc(string loc, string city)
{

}