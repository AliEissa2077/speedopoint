#include "stop.h"
country stop::getLoc()
{
	return loc;

}

int stop::getIndex()
{
	return cityIndex;
}

airport stop::getAirport()
{
    return aPort;
}

date stop::getTime()
{
	return time;
}


stop::stop(country location, int index, airport airl, date dt)
{
	loc = location;
	cityIndex = index;
    aPort = airl;
    time = dt;
    next = NULL;
}

void stop::add_stop(country location, int index, airport airl, date dt) {
    stop* newone = new stop(location, index, airl, dt);
    stop* curr = this;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newone;
}



