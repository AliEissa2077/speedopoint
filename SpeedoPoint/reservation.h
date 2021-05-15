#pragma once 
#ifndef RESERVATION_H
#define RESERVATION_H
#include "hotellisting.h"
#include "hotel.h"
#include "user.h"
#include "payment.h"
#include "date.h"
class reservation {
private:
	hotellisting listing;
	date starting;
	int numDays;
	hotel hotel;
	payment payment;
	user acc;
public:
	reservation();
	reservation(hotellisting list, date stat, int num, payment payment_, user account);
};


#endif RESERVATION_H