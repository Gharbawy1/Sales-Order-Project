#include "Credit.h"

string Credit::GetNumber()
{
    return m_Number;
}

string Credit::GetVisaType()
{
    return m_VisaType;
}

double Credit::GetAmount()
{
    return m_Amount;
}

string Credit::GetPaymentMethod()
{
    return "Credit Card";
}

void Credit::SetPaymentData()
{
    cout << "> ENTER THE AMOUNT YOU WANT TO PAY : ";
    cin >> m_Amount;
    cout << "> CREDIT NUMBER : ";
    cin >> m_Number;
    cout << "> VISA TYPE : ";
    cin >> m_VisaType;

}

void Credit::DisplayPaymentData()
{
    cout << "\n > YOU PAY : "<<m_Amount;
    cout << "\n > CREDIT NUMBER : "<<m_Number;
    cout << "\n > VISA TYPE : "<<m_VisaType<<"\n";
}
