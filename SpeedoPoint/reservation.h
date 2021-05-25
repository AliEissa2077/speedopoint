#pragma once 
#ifndef RESERVATION_H
#define RESERVATION_H
//#include "hotellisting.h"
#include "hotel.h"
//#include "user.h"
#include "payment.h"
#include "date.h"
class hotellisting;
class user;

class reservation {
private:
    hotellisting* listing;
	date starting;
	int numDays;
    int adults;
    int children;
    hotel htl;
    payment paymnt;
    user* acc;
public:
	reservation();
    reservation(hotellisting* list, date start, int num, payment payment_, user* account, int adult, int child);

    hotellisting* getListing();
    date getDate();
    int getDaysnum();
    int getAdults();
    int getChildren();
    float getPaymentVal();
    user* getUser();

};


#endif RESERVATION_H
