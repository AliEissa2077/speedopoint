#include "flightticket.h"

flightticket::flightticket()
{

}

flightticket::flightticket(int ad, int child, bool oneway, date dep, date arr, airport f, airport t, std::string tictype, bool refund, user* account,float dur, payment pay, flightlisting* l)
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
    paymnt = pay;
	flight_duration = dur;
    listing = l;
}
void flightticket::setReturn(date d) {
    returnTime = d;
}
flightlisting* flightticket::getListing() {
    return listing;
}

user* flightticket::getUser () {
    return acc;
}

float flightticket::getPaymentVal() {
    return paymnt.getValue();
}
date flightticket::getDate() {
    return departure;
}
int flightticket::getAdults() {
    return adults;
}
int flightticket::getChildren() {
    return children;
}
