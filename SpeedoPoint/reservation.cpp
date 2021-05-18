#include "reservation.h"





void reservation::getlisting()
{
	return listing;
}

reservation::reservation(hotellisting* list, date start, int num, payment payment_, user account)
{
	listing = list;
	starting = start;
	numDays = num;
	payment = payment_;
	acc = account;
}

