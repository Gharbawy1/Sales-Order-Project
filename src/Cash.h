#pragma once
#include"Payment.h"
class Cash : public Payment
{
private :
	double CashValue;

public :
	double GetAmount();
	double GetCashValue();
	string GetPaymentMethod();
	void SetPaymentData();
	void DisplayPaymentData();

};

