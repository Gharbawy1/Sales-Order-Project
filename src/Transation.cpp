#include "Transation.h"
int Transation::m_TransactionId = 0;
Transation::Transation()
{
	++m_TransactionId;
	ID = m_TransactionId;
	payment = nullptr;
}

string Transation::GetPaymentMethodForTrans()
{
	return payment->GetPaymentMethod();
}

int Transation::GetPaidMoney()
{
	return payment->GetAmount();
}

void Transation::SetTrasicationData()
{
		// set payment
	cout << "> PLEASE ENTER THE PAYMETN METHOD : \n    [1] Cash .\n    [2] Credit .\n    [3] Check .\n";
	int choose;
	cout << "            > PLEASE SELECT ONE OPTION : "; cin >> choose;
	switch (choose)
	{
	case 1 :
		payment = new Cash;
		payment->SetPaymentData();
		break;
	case 2:
		payment = new Credit;
		payment->SetPaymentData();
		break;
	case 3 :
		payment = new Check;
		payment->SetPaymentData();
		break;

	}
}

int Transation::GetTransactionId()
{
	return ID;
}


void Transation::Display()
{
	payment->DisplayPaymentData();
}