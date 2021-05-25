#include "reservation.h"
#include "user.h"




hotellisting* reservation::getListing()
{
	return listing;
}

reservation::reservation()
{

}


reservation::reservation(hotellisting* list, date start, int num, payment payment_, user* account, int adult, int child)
{
	listing = list;
	starting = start;
	numDays = num;
    paymnt = payment_;
	acc = account;
    adults = adult;
    children = child;
}
date reservation::getDate() {
    return starting;
}
int reservation::getDaysnum() {
    return numDays;
}
int reservation::getAdults() {
    return adults;
}
int reservation::getChildren() {
    return children;
}
float reservation::getPaymentVal() {
    return paymnt.getValue();
}
user* reservation::getUser() {
    return acc;
}
