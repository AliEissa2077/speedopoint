#include "stop.h"








country stop::getLoc()
{
	return loc;

}

int stop::getIndex()
{
	return cityIndex;
}

airline stop::getAirline()
{
    return airlne;
}

date stop::getTime()
{
	return time;
}


stop::stop(country location, int index, airline airl, date d)
{

	loc = location;
	cityIndex = index;
    airlne = airl;
	time = d;
    next = NULL;
}

void stop::add_stop(country location, int index, airline airl, date d) {
    stop* newone = new stop(location, index, airl, d);
    stop* curr = this;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newone;
}



