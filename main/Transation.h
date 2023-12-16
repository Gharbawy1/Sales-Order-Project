#pragma once
#include<iostream>
#include"Payment.h"
#include"Cash.h"
#include"Check.h"
#include"Credit.h"
using namespace std;

class Transation
{
private:
	// date
	static int m_TransactionId;
	int ID;
	Payment* payment;
public:
	Transation();
	string GetPaymentMethodForTrans();
	int GetPaidMoney();
	void SetTrasicationData();
	int GetTransactionId();
	void Display();
};

