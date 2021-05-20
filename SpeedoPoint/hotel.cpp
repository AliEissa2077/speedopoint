#include "hotel.h"

hotel::hotel() {
	name = "";
	cityIndex = -1;
	rating = 0;
	priceRange = 0;
	pool = false;
	rating_counter = 0;
}
hotel::hotel(std::string name_, country c, int index,int range, bool pool_) : name(name_), ctry(c), cityIndex(index), priceRange(range), pool(pool_){
	rating = 0;
	rating_counter = 0;
}
void hotel::updateRating(float rt) {
	float total_rating = rating * rating_counter;
	float new_total_rating = total_rating + rt;
	rating_counter++;
	rating = new_total_rating / rating_counter;
}

int hotel::getRating() {
    return rating;
}
bool hotel::getPool() {
    return pool;
}
int hotel::getRatingsCount() {
    return rating_counter;
}
int hotel::getPriceRange() {
    return priceRange;
}
std::string hotel::getName() {
    return name;
}
bool hotel::getBeach() {
    return beach;
}
country hotel::getCountry() {
    return ctry;
}
int hotel::getIndex() {
	return cityIndex;
}
