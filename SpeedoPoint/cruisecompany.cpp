#include "cruisecompany.h"

cruisecompany::cruisecompany()
{

}

cruisecompany::cruisecompany(std::string name_, int rt, int srt, int range)
{
	std::string name = name_;
	rating = rt;
	safetyRating = srt;
	priceRange = range;
}

void cruisecompany::updateRating(int rt)
{
    ratingcount++;
    rating = ((rating *(ratingcount - 1)) + rt) / ratingcount;
}
