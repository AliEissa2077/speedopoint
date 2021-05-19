#include "reservation.h"
#include "user.h"




hotellisting* reservation::getListing()
{
	return listing;
}

reservation::reservation()
{

}


reservation::reservation(hotellisting* list, date start, int num, payment payment_, user* account)
{
	listing = list;
	starting = start;
	numDays = num;
    paymnt = payment_;
	acc = account;
}

