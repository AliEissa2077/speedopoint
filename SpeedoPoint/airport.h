#include "country.h"

class airport {
private: 
	country country;
	int cityIndex;
public:
	airport();
	airport(country ctry, int index);
	country getCountry();
	int getIndex();
};