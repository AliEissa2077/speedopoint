#include "stop.h"








country stop::getloc()
{
	return loc;

}

int stop::getindex()
{
	return cityIndex;
}

airline stop::getairl()
{
	reutrn airairline;
}

date stop::getd()
{
	return time;
}


stop::stop(country location, int index, airline airl, date d)
{

	loc = location;
	cityIndex = index;
	airline = airl;
	time = d;
}







#endif STOP_H