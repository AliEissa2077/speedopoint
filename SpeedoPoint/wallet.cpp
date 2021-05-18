#include "wallet.h"







wallet::wallet()
{
	amt = 0;
}

float wallet::getamount()
{
	return amount;
}

void wallet::deposit(float amt)
{
	amount = amount + amt;
}

void wallet::pay(float amt)
{
	amount = amount - amt;
}

int wallet::redeem()
{
	amount = 
}

void wallet::refund(payment payment_)
{
	amount = amount + payment_.getValue;  //--> deletes reservation from account (ADD LATER) 
}








