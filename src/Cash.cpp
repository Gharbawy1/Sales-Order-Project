#include "Cash.h"

double Cash::GetAmount()
{
    return m_Amount;
}

double Cash::GetCashValue()
{
    return CashValue;
}

string Cash::GetPaymentMethod()
{
    return "Cash";
}

void Cash::SetPaymentData()
{
    cout << "> ENTER THE AMOUNT YOU WANT TO PAY : ";
    cin >> m_Amount;
    cout << "> CASH VALUE : ";
    cin >> CashValue;
}

void Cash::DisplayPaymentData()
{
    cout << "\n > AMOUNT YOU PAY : " << m_Amount;
    cout << "\n > CASH VALUE : "<<CashValue<<"\n";
}
