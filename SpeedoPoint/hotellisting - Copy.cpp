#include "hotellisting.h"
#include "date.h"

hotellisting::hotellisting() {
	cityIndex = -1;
	area = -1;
	wifi = false;
	bfast = false;
	person = -1;
	refundable = false;
	dinner = false;
	pets = false;
	roomType = "";
}

hotellisting::hotellisting(hotel hot, country location, int index, int area_, bool wifi_, bool breakfast, int numPeople, bool refund, bool dinner_, bool pet, std::string roomtype): htl(hot), loc(location), cityIndex(index), area(area_), wifi(wifi_), bfast(breakfast), person(numPeople), refundable(refund), dinner(dinner_), pets(pet), roomType(roomtype) {


}



reservation hotellisting::reserve(user acc){


}

bool hotellisting::verifyLoc(string l, string city) {
    if (l.compare(loc.getName()) == 0) {
        if (city.length() > 1) {
            vector<string> list = loc.getCities();
            for (int i = 0; i < list.size(); i++) {
                if (city.compare(list[i]) == 0) {
                    return true;
                }
            }
            return false;
        }
        else return true;
    }
    else { return false;}
}

int hotellisting::getPricePerNight() {
    return pricePerNight;
}
int hotellisting::getHotelRating() {
    return htl.getRating();
}
hotel hotellisting::getHotel() {
    return htl;
}
bool hotellisting::getPets() {
    return pets;
}
bool hotellisting::getDinner() {
    return dinner;
}
bool hotellisting::getRefundable() {
    return refundable;
}
int hotellisting::getMaxPersons() {
    return person;
}
bool hotellisting::getBfast() {
    return bfast;
}
bool hotellisting::getWifi() {
    return wifi;
}
int hotellisting::getArea() {
    return area;
}
country hotellisting::getLoc() {
    return loc;
}
int hotellisting::getCityIndex() {
    return cityIndex;
}

