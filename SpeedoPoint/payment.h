#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H


#include "date.h"
//#include "user.h"
#include <iostream>
using namespace std;

class user;

class payment {
private:
	float amount;
	bool paymentType; // 1 for card 0 for wallet 
    date dte;
    user* usr;
public:
	payment();
    payment(float amt, bool pymtType, date pytDate, user* user_);
	float getValue();
	void showInvoice();
};
#endif PAYMENT_H
