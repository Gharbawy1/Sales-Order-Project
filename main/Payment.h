#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Payment
{
protected:
	//date m_paied_date;
	double m_Amount;

public:
	virtual double GetAmount() = 0;
	virtual string GetPaymentMethod() = 0;
	virtual void SetPaymentData() = 0;
	virtual void DisplayPaymentData() = 0;
};

