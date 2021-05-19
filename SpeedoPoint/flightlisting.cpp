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
    flightticket* result; // = new flightticket(adults, children, oneway, dep, arr, stops->getAirport(), curr->getAirport(), cabin, refund, acc, CalculateFlightDur());

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
airline flightlisting::getAirline() {
    return airlne;
}

int flightlisting::getDepCityIndex() {
    return stops->getIndex();
}
int flightlisting::getArrCityIndex() {
    stop * curr = stops;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    return curr->getIndex();
}
string flightlisting::getDepTime() {
    string result;
    result += to_string(dep.getHour()) + ":" + to_string(dep.getMinute());
    result += " " + to_string(dep.getDay()) + "/" + to_string(dep.getMonth()) + "/" + to_string(dep.getYear()) + " ";
    return result;
}
string flightlisting::getArrTime() {
    string result;
    result += to_string(arr.getHour()) + ":" + to_string(arr.getMinute());
    result += " " + to_string(arr.getDay()) + "/" + to_string(arr.getMonth()) + "/" + to_string(arr.getYear()) + " ";
    return result;
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
