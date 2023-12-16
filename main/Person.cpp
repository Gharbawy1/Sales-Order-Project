#include "Person.h"
#include<Windows.h>
Person::Person() {
	m_PresonOrderCount = 0;
}
void Person::Print() {
	cout << " | Coustmer Info | \n\n";
		
	cout << "> Your FullName : " << m_FullName;
	cout << "\n> Your Biling - Address : " << m_BilingAddress;
	cout << "\n> Your Phone : " << m_Phone<<"\n\n";

}

void Person::SetData()
{
	cout << " | Now Your ID IS : " << m_id <<" |\n";
	cout << "- Enter Your Full Name :"; cin>>m_FullName;
	cout << "- Enter Your Biling- Address : "; cin>> m_BilingAddress;
	cout << "- Enter Your Phone : "; cin>> m_Phone;

}

int Person::GetCoustmerId()
{
	return m_id;
}

void Person::SetNewData()
{
	cout << "> DO YOU WANT TO MODIFY \n   [1] Name .\n   [2] Biling - Address .\n   [3] Phone . \n";
	int* selectOption; selectOption = new int;
	do
	{
		cout << " > PLEASE SELECT ONE OPTION : ";
		cin >> *selectOption;
		if (*selectOption < 1 || *selectOption>3)
		{
			cout << "OOPS :\ !! PLEASE ENTER VALIED OPTION !\n";
			Sleep(1500);
		}
	} while (*selectOption < 1 || *selectOption>3); // for checking

	switch (*selectOption)
	{
	case 1:
		cout << "> Your New FullName ( Old - "<<m_FullName<<" -) : "; cin>> m_FullName;
		cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";

		break;
	case 2:
		cout << "> Enter Your New Biling- Address  ( Old - " << m_BilingAddress << " -) : "; cin>> m_BilingAddress; 
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
		break;

	case 3 :
		cout << "> Enter Your New Phone ( Old - " << m_Phone << " - ) : "; cin>> m_Phone;
		cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
		break;
	}
	delete selectOption;
}

string Person::GetName()
{
	return m_FullName;
}

