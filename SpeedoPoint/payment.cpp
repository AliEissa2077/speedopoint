#include "payment.h"


float payment::getValue()
{
	return amount;
}

void payment::showInvoice()
{

}



payment::payment(float amt, bool pymtType, date pytDate, user* user_);
{
	amount = amt;
	paymentType = pymtType;
	dte = pytDate;
	usr = user_;
}











lass payment{
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