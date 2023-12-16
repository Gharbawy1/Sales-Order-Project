#pragma once
#include"Payment.h"
class Check : public Payment
{
private :
	string name;
	string BankId;


public:
	string GetName();
	string GetBankId();
	double GetAmount();
	string GetPaymentMethod();
	void SetPaymentData();
	void DisplayPaymentData();

};

