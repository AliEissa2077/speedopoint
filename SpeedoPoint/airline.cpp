#include "airline.h"

airline::airline() {
	name = "";
	rating = 0;
	safetyrating = 0;
	pricerange = 0;
	rating_counter = 0;
}
airline::airline(std::string name_, int range, float srt) : name(name_), pricerange(range), safetyrating(srt){
	rating = 0; //rating starts at 0 as no reviews yet
	rating_counter = 0;
} 
void airline::setRating(float rt, int num) {
	rating = rt;
	rating_counter = num;
}
void airline::setSRating(float srt) {
	safetyrating = srt;
}
void airline::setRange(int range) {
	pricerange = range;
}
void airline::setName(std::string name_) {
	name = name_;
}
int airline::getRating() {
	return rating;
}
int airline::getSRating() {
	return safetyrating;
}
int airline::getRange() {
	return pricerange;
}
std::string airline::getName() {
	return name;
}
void airline::updateRating(float rt) {
	float total_rating = rating * rating_counter;
	float new_total_rating = total_rating + rt;
	rating_counter++;
	rating = new_total_rating / rating_counter;
}//updates rating after user gives review
