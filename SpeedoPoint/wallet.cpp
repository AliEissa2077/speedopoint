#include "wallet.h"


wallet::wallet(float amt) {
    amount = amt;
}
wallet::wallet()
{
	amount = 0;
}

float wallet::getAmount()
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
    int temp = points;
    points = 0;
    return temp;
}

void wallet::refund(payment payment_)
{
	amount = amount + payment_.getValue();  //--> deletes reservation from account (ADD LATER) 
}








