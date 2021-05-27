#include "cruisecompany.h"

cruisecompany::cruisecompany()
{

}

cruisecompany::cruisecompany(std::string name_, float rt, float srt, int range)
{
    name = name_;
	rating = rt;
	safetyRating = srt;
	priceRange = range;
}

void cruisecompany::updateRating(float rt)
{
    ratingcount++;
    rating = ((rating *(ratingcount - 1)) + rt) / ratingcount;
}

std::string cruisecompany::getName() {
    return name;
}
int cruisecompany::getRating() {
    return rating;
}
int cruisecompany::getPriceRange() {
    return priceRange;
}
int cruisecompany::getSafety() {
    return safetyRating;
}
