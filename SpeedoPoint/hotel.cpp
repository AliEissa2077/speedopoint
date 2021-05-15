#include "hotel.h"

hotel::hotel() {
	name = "";
	cityIndex = -1;
	rating = 0;
	priceRange = 0;
	pool = false;
	rating_counter = 0;
}
hotel::hotel(std::string name_, country ctry, int index,int range, bool pool_) : name(name_), country(ctry), cityIndex(index), priceRange(range), pool(pool_){
	rating = 0;
	rating_counter = 0;
}
void hotel::updateRating(float rt) {
	float total_rating = rating * rating_counter;
	float new_total_rating = total_rating + rt;
	rating_counter++;
	rating = new_total_rating / rating_counter;
}