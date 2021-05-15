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
hotellisting::hotellisting(hotel hot, country location, int index, int area_, bool wifi_, bool breakfast, int numPeople, bool refund, bool dinner_, std::string roomtype): hotel(hot), loc(location), cityIndex(index), area(area_), wifi(wifi_), bfast(breakfast), person(numPeople), refundable(refund), dinner(dinner_), pets(pet), roomType(roomtype) {
}
reservation hotellisting::reserve(user acc){
}