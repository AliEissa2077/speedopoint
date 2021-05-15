#include "date.h"
#include "user.h"
#include <iostream>
using namespace std;
class payment {
private:
	float amount;
	bool paymentType; // 1 for card 0 for wallet 
	date date;
	user user;
public:
	payment();
	payment(float amt, bool pymtType, date pytDate, user user_);
	float getValue();
	void showInvoice();
};