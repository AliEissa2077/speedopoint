#pragma once
#ifndef CRUISERESERVATION_H
#define CRUISERESERVATION_H
//#include "cruise.h"
#include "payment.h"
//#include "user.h"

class cruise;
class user;

class cruisereservation {
private:
    cruise* cruze;
    payment paymnt;
	int adults;
	int children;
    user* acc;
public:
    bool rated = false;
	cruisereservation();
    cruisereservation(cruise* crs, payment pay, int ad, int child, user* user);
    cruise* getListing();
};



#endif CRUISERESERVATION_H
