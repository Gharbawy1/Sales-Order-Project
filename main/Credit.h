#pragma once
#include"Payment.h"
class Credit : public Payment
{
private:
	string m_Number;
	//date expireDate
	string m_VisaType;
public:
	string GetNumber();
	string GetVisaType();
	double GetAmount();
	string GetPaymentMethod();
	void SetPaymentData();
	void DisplayPaymentData();
};

