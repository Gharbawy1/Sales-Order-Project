#include "Check.h"

string Check::GetName()
{
    return name;
}

string Check::GetBankId()
{
    return BankId;
}

double Check::GetAmount()
{
    return m_Amount;
}

string Check::GetPaymentMethod()
{
    return "Check";
}

void Check::SetPaymentData()
{

    cout << "> ENTER THE AMOUNT YOU WANT TO PAY : ";
    cin >> m_Amount;
    cout << "> BANK NAME : ";
    cin >> name;
    cout << "> ENTER THE BANK ID : ";
    cin >> BankId;
}

void Check::DisplayPaymentData()
{
    cout << "\n > AMOUNT YOU PAY : "<<m_Amount;
    cout << "\n > BANK NAME : "<<name;
    cout << "\n > BANK ID : "<<BankId<<"\n";
}
