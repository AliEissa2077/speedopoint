#include "airport.h"

airport::airport(){

}
airport::airport(std::string airport_name, country count, int index) {
    ctry = count;
    cityIndex = index;
    name= airport_name;
}

country airport::getCountry()
{
    return ctry;
}

int airport::getIndex()
{
    return cityIndex;
}

std::string airport::getName() {
    return name;
}





