#pragma once
#ifndef CRUISERESERVATION_H
#define CRUISERESERVATION_H
#include "cruise.h"
#include "payment.h"
#include "user.h"

class cruisereservation {
private:
	cruise cruise;
	payment payment;
	int adults;
	int children;
	user acc;
public:
	cruisereservation();
	cruisereservation(cruise crs, payment pay, int ad, int child, user user);
};



#endif CRUISERESERVATION_H