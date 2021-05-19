#pragma once
#ifndef WALLET_H
#define WALLET_H

#include "payment.h"
class wallet {
private:
	float amount;
public:
	wallet();
	wallet(float amt); // amt -> amount to initalize wallet with
	float getAmount();
	void deposit(float amt);
	void pay(float amt);
	int redeem();
	void refund(payment payment_);
};

#endif WALLET_H
