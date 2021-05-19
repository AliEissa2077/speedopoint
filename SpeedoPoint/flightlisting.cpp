#include "flightlisting.h"

flightlisting::flightlisting() {

}
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

flightticket* flightlisting::reserve(user* acc, int adults, int children, bool oneway, bool refund)
{
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    flightticket* result = new flightticket(adults, children, oneway, dep, arr, stops->getAirport(), curr->getAirport(), cabin, refund, acc, CalculateFlightDur());

    return result;
}

int flightlisting::getPriceperTraveller()
{
    return pricepertraveller;
}

int flightlisting::getAirlineRating()
{
    return airlne.getRating();
}

float flightlisting::CalculateFlightDur() {
    return _CalculateFlightDur(stops);
}


float flightlisting::subtract(date d, date f) {
    float var1 = 0;
        var1 += d.getDay()*24;
        var1 += d.getHour();
        var1 += d.getMinute()/60.0;

        float var2 = f.getDay()*24 + f.getHour() + f.getMinute() / 60.0;
        cout << var1;
        cout <<endl;
        return var2 - var1;
}


float flightlisting::_CalculateFlightDur(stop* stp) {
    stop* last = stp;
    while (last->next != NULL) {
        last = last->next;
    }
    return abs(subtract(stp->getTime(), last->getTime()));
}

country flightlisting::getDepCountry() // makes a new country objects with country name and one city in the vector (the airport city loc) and returns it
{
    return stops->getLoc();

}

country flightlisting::getArrCountry() // +1
{
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr->getLoc();

}


bool flightlisting::verifyFromAndToLocs(string locdep, string citydep, string locArrive, string cityArrive)
{
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    if (locdep.compare(stops->getLoc().getName()) != 0 || locdep.compare(curr->getLoc().getName()) != 0) {
        return false;
    }
    if (citydep.length() > 1) {
        if (locdep.compare(stops->getLoc().getCities()[stops->getIndex()]) != 0) {
            return false;
        }
    }
    if (cityArrive.length() > 1) {
        if (locdep.compare(curr->getLoc().getCities()[curr->getIndex()]) != 0) {
            return false;
        }
    }
    return true;
}
