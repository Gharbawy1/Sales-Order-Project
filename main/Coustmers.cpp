#include "Coustmers.h"
#include<Windows.h>
#include<algorithm>
int Coustmers::CoustmersClassCounter = 0;
Coustmers::Coustmers(int MaxSizeFromUser){
	SizeOfCoustmersList = MaxSizeFromUser;
	CoustmerList = new Coustmer * [SizeOfCoustmersList];
}
void Coustmers::AddCopmany()
{
	CoustmerList[CoustmersClassCounter] = new Company;
	CoustmerList[CoustmersClassCounter]->SetData();
	CoustmersClassCounter++;
}
void Coustmers::AddPerson()
{
	CoustmerList[CoustmersClassCounter] = new Person;
	CoustmerList[CoustmersClassCounter]->SetData();
	CoustmersClassCounter++;
}
void Coustmers::AddCoustmer() {
	cout << "> Are you  \n     [1] Person .\n     [2] Company .\n";
	 int* selectOption; selectOption = new int; 
	do
	{
		cout << " > PLEASE SELECT ONE OPTION : ";
		cin >> *selectOption;
		if (*selectOption < 1 ||  * selectOption>2)
		{
			cout << "OOPS :\ !! PLEASE ENTER VALIED OPTION !\n";
			Sleep(1500);
		}
	} while (*selectOption < 1 || *selectOption>2); // for checking
	switch (*selectOption)
	{
	case 1:
		AddPerson();
		cout << ":) YOU HAVE BEEN ADDED SUCCESSFULLY, WELCOME ^_^ \n";
		system("cls");
		break;
	case 2:
		AddCopmany();
		cout << ":) YOUR COMPANY HAVE BEEN ADDED SUCCESSFULLY, WELCOME  ^_^ \n";
		system("cls");
		break;

	}
	delete selectOption;
}
bool compareByName(Coustmer* e1, Coustmer* e2)
{
	return e1->GetName() < e2->GetName();
}
void Coustmers::SearchSubString() {
	sort(CoustmerList, CoustmerList + CoustmersClassCounter, compareByName);
	cout << "Enter The Company Name : ";
	string s;
	cin >> s;
	int count = 0;
	char c;
	for (int i = 0; i < CoustmersClassCounter; i++)
	{
		size_t found = CoustmerList[i]->GetName().find(s);
		if (found != string::npos)// it returns the value string::npos, which is a special value that represents "not found".
		{

			cout << "[" << (count++) + 1 << "] " << CoustmerList[i]->GetName() << endl;
		}

	}
	cout << "> SELECT THE NAME YOU WANT TO SEARCH FOR : ";
	string name;
	cin >> name;
	Search(name);
}
void Coustmers::Search(string name)
{

	bool found = false;
	for (int i = 0; i < CoustmersClassCounter; i++)
	{
		if (CoustmerList[i]->GetName() == name)
		{
			found = true;
			cout << "\n > FOUNDED SUCCSSFULLY ^_^\n";
			cout << " >> DO YOU WANT TO CONTINUE ?? (y/n)";
			char c; cin >> c;
			if (c == 'y') {
				CoustmerList[i]->SetNewData();
			}
			else {
				break;
			}
		}
		else if (found == false)
		{

			cout << "Oh NOO !! EMOLOYEE NOT FOUND PLEASE SURE FROM YOUR DETAILS YOU ENTERD AND TRY AGAIN :\ \n";
			break;


		}
	}

}
void Coustmers::EditCoustmer() {
	cout << "> DO YOU TO EDIT \n     [1] Person .\n     [2] Company . \n";
	int* selectOption; selectOption = new int; bool IsCoustmerFound = false;
	do
	{
		cout << " > PLEASE SELECT ONE OPTION : ";
		cin >> *selectOption;
		if (*selectOption < 1 || *selectOption>2)
		{
			cout << "OOPS :\ !! PLEASE ENTER VALIED OPTION !\n";
			Sleep(1500);
		}
	} while (*selectOption < 1 || *selectOption>2); // for checking
	switch (*selectOption)
	{
	case 1:
		//  modify a person and search with id ;
		cout << "Enter The ID Which You want To Modify : ";
		int* id; id = new int; cin >> *id;
		for (int i = 0; i < CoustmersClassCounter; i++)
		{
			if (CoustmerList[i]->GetCoustmerId() == *id)
			{
				IsCoustmerFound = true;
				cout << "\n FOUNDED SUCCSSFULLY ^_^\n";
				CoustmerList[i]->SetNewData();
				break;
			}
		}
		if (IsCoustmerFound == false) {
			cout << "> NOT FOUNDED :(\n";
			break;
		}
		break;
	case 2:
		SearchSubString();
		delete selectOption;

	}
}
void Coustmers::DeleteCoustmer() {
	bool found = false;
	cout << "> PLease Enter Your Id : "; int id; cin >> id;
	for (int i = 0; i < CoustmersClassCounter; i++)
	{
		if (CoustmerList[i]->GetCoustmerId() == id)
		{
			found = true;
			cout << "\n > FOUNDED SUCCSSFULLY ^_^\n";
			cout << " >> DO YOU SURE TO DELETE "<< CoustmerList[i]->GetName() <<" ?? (y / n)";
			char c; cin >> c;
			if (c == 'y') {
				delete CoustmerList[i];
				cout << ":) DELETED SUCCESSFULLY \n";
				while (i < CoustmersClassCounter - 1)
				{
					CoustmerList[i] = CoustmerList[i + 1];
					i++;
				}
				CoustmersClassCounter--;
				SizeOfCoustmersList--;
				break;
			}
			else {
				break;
			}
		}
		else if (found == false)
		{

			cout << "Oh NOO !! EMOLOYEE NOT FOUND PLEASE SURE FROM YOUR DETAILS YOU ENTERD AND TRY AGAIN :\\ \n";
			break;
		}
	}
}
bool Coustmers::Search(int id)
{
	bool IsFounded = false;
	for (int i = 0; i < CoustmersClassCounter; i++) {
		if (CoustmerList[i]->GetCoustmerId() == id) {
			IsFounded = true;
			return true;
		}
	}if (IsFounded == false) {
		return false;
	}
}
void Coustmers::Print() {
	for (int i = 0; i < CoustmersClassCounter; i++) {
		CoustmerList[i]->Print();
	}
}

Coustmer* Coustmers::SearchForCoustmer(int id) {
		bool Isfound = false;
		for (int i = 0; i < CoustmersClassCounter; i++) {
			if (CoustmerList[i]->GetCoustmerId() == id) {
				Isfound = true;
				cout << "> COUSTMER FOUNDED SUCCESSFULLY \n\n    > ";
				
				return &(*CoustmerList[i]);// index i has a pointer refer to a coustmer 
			}
		}if (Isfound == false) {
			throw " NOT FOUNDED \n";
		}
}

void Coustmers::PrintIdForSpiceficCoustmer()
{
	cout << "> PLEASE ENTER THE COUSTMER ID : "; int id; cin >> id;
	for (int i = 0; i < CoustmersClassCounter; i++) {
		if (CoustmerList[i]->GetCoustmerId() == id) {
			cout << "> FOUNDED SUCCESSFULLY \n";
			CoustmerList[i]->PrintOrders();
		}
	}
}
