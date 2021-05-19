#include "payment.h"



float payment::getValue()
{
	return amount;
}

void payment::showInvoice()
{

}
payment::payment() {

}


payment::payment(float amt, bool pymtType, date pytDate, user* user_)
{
	amount = amt;
	paymentType = pymtType;
	dte = pytDate;
	usr = user_;
}
