#include "cruisereservation.h"
#include "cruise.h"
#include "user.h"

cruisereservation::cruisereservation()
{

}

cruisereservation::cruisereservation(cruise* crs, payment pay, int ad, int child, user* u)
{
	cruze = crs;
	paymnt = pay;
	adults = ad;
	children = child;
    acc = u;

}

cruise* cruisereservation::getListing() {
    return cruze;
}
