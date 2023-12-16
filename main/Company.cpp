#include "Company.h"
#include<Windows.h>
#include<string>
Company::Company()
{
	
	m_Location = "No Location Set";
	m_CompanyName = "No Name";
	m_Phone = "No Number ";
	
}

void Company::Print() {
	cout << " | Company Info | \n\n";
	cout << "> Company Name : " << m_CompanyName;
	cout << "\n> Company Location : " << m_Location;
	cout << "\n> Company Phone : " << m_Phone<<"\n";
}

void Company::SetData()
{
	cout << " | Company Info | \n";
	cout << "- Enter Company Name : "; cin>> m_CompanyName;
	cout << "- Enter Company Location : "; cin>> m_Location;
	cout << "- Enter Company Phone : "; cin>> m_Phone;
}
void Company::SetNewData() {
	cout << "> DO YOU WANT TO MODIFY \n   [1] Name .\n   [2] Location .\n   [3] Phone . \n";
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
		cout << "> Your New Company Name ( Old - " << m_CompanyName << " -) : ";cin>> m_CompanyName;
		cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";

		break;
	case 2:
		cout << "> Enter Your New Company Location  ( Old - " << m_Location << " -) : "; cin>> m_Location; 
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
		break;

	case 3:
		cout << "> Enter Your New Company Phone ( Old - " << m_Phone << " - ) : "; cin>> m_Phone;
		cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
		break;
	}
	delete selectOption;

}
int Company::GetCoustmerId()
{
	return m_id;
}
string Company::GetName()
{
	return m_CompanyName;
}




