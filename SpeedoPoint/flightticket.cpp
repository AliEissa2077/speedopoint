#include "flightticket.h"

flightticket::flightticket()
{

}

flightticket::flightticket(int ad, int child, bool oneway, date dep, date arr, airport f, airport t, std::string tictype, bool refund, user* account,float dur)
{
	adults = ad;
	children = child;
	one_way = oneway;
	departure = dep;
	arrival = arr;
	from = f;
	to = t;
	std::string ticketType = tictype;
	refundable = refund;
	acc = account;
	flight_duration = dur;
}