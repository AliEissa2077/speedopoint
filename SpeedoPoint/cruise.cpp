#include "cruise.h"

cruise::cruise()
{

}

cruise::cruise(date start_, date end_, std::string model, int price, country dep, country arr, int index, stop* stp, std::string type)
{
	start = start_;
	end = end_;
	std::string cruisemodel = model;
	pricePerPerson = price;
	depCountry = dep;
	arrCountry = arr;
	arrivalCityIndex = index;
    stops = stp;
	std::string suiteType = type;

}

int cruise::getPricePerPerson()
{
	return pricePerPerson;
}


int cruise::getDuration()
{
    return subtract(start, end);
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
float cruise::subtract(date d, date f) {
    float var1 = 0;
        var1 += d.getMonth() * 30;
        var1 += d.getDay();


        float var2 = f.getMonth()*30 + f.getDay();

        return var2 - var1;
}

cruisecompany cruise::getCompany()
{
	return company;
}

bool cruise::verifyLoc(string loc, string city)
{
	if (loc.compare(loc.getName()) == 0)
	{
		if (city.length() > 1)
		{
			vector<string> list = loc.getCities();
			for (int i = 0; i < list.size(); i++)
			{
				if (city.compare(list[i]) == 0)
				{
					return true;
				}
			}
			return false;
		}
		else return true;
	}
	else { return false; }
}
