#include "payment.h"
class wallet {
private:
	float amount;
public:
	wallet();
	wallet(float amt); // amt -> amount to initalize wallet with
	float getAmoount();
	void deposit(float amt);
	void pay(float amt);
	int redeem();
	void refund(Payment payment);
};