#include "flightlisting.h"

flightlisting::flightlisting(airline air, stop* stp, int sptnum, date departure, date arrival, int price, std::string cabin_, std::string planeModel, int carryOn, int CheckedW, int additionalWPrice)
{
	airlne = air;
	stops = stp;
	stopnum = sptnum;
	dep = departure;
	arr = arrival;
	pricepertraveller = price;
	std::string cabin = cabin_;
	std::string plane = planeModel;
	carronW = carryOn;
	checkedBaggageW = CheckedW;
	additionalBagPrice = additionalWPrice;

}

flightticket reserve(user acc)
{


}

int flightlisting::getPriceperTraveller()
{
    return pricepertraveller;
}

int flightlisting::getAirlineRating()
{

}

float flightlisting::CalculateFlightDur()
{

}

float flightlisting::_CalculateFlightDur(stop* stp) //recursive
{


}

country flightlisting::getDepCountry() // makes a new country objects with country name and one city in the vector (the airport city loc) and returns it
{

}

country flightlisting::getArrCountry() // +1
{

}


bool flightlisting::verifyFromAndToLocs(string locdep, string citydep, string locArrive, string cityArrive)
{

}
