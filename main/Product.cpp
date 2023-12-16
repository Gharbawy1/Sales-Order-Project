#include "Product.h"
#include<Windows.h>
Product::Product() {
	m_id = 0;
}
bool Product::Update()  {
	
		cout << "> DO YOU WANT TO MODIFY \n   [1] Product Name .\n   [2] Product Number .\n   [3] Product Price . \n   [4] Product Type . \n   [5] Product Quantity . \n";
		int* selectOption; selectOption = new int;
		bool IsHeChoosedQuantity = true; // return it when he dont choose from this 
		do
		{
			cout << " > PLEASE SELECT ONE OPTION : ";
			cin >> *selectOption;
			if (*selectOption < 1 || *selectOption>5)
			{
				cout << "OOPS :\ !! PLEASE ENTER VALIED OPTION !\n";
				Sleep(1500);
			}
		} while (*selectOption < 1 || *selectOption>5); // for checking

		switch (*selectOption)
		{
		case 1:
			cout << "> Enter New Product Name ( Old - " << m_Name << " -) : "; cin >> m_Name;
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";

			break;
		case 2:
			cout << "> Enter New Proudct Number  ( Old - " << m_Number << " -) : "; cin >> m_Number;
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
			break;

		case 3:
			cout << "> Enter New Product Price ( Old - " << m_Price << " - ) : "; cin >> m_Price;
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n";
			break;
		case 4:
			cout << "> Enter New Product Type ( Old - " << m_Type << " - ) : "; cin >> m_Type;
			cout << " ^_^ MODIFING DONE SUCCESSFULLY \n"; break;
		default:
			IsHeChoosedQuantity = false;
			return IsHeChoosedQuantity;
		}
		delete selectOption;
}
ostream& operator<<(ostream& out, Product& product) {
	cout << " | Product Info | \n\n";
	cout << "> Product ID Or Serial : "<< product.m_id;
	cout << "\n> Product Name : " << product.m_Name;
	cout << "\n> Product Number : " << product.m_Number;
	cout << "\n> Product Price : " << product.m_Price;
	cout << "\n> Product Type : " << product.m_Type;
	return out;
}
istream& operator>>(istream& input, Product& product) {
	cout << "- Product ID : "; cin >> product.m_id;
	cout << "- Proudct Name : "; cin >> product.m_Name;
	cout << " - Product Number : "; cin >> product.m_Number;
	cout << "- Product Price : "; cin >> product.m_Price;
	cout << "- Product Type : "; cin >> product.m_Type;
	return input;
}
int Product::GetId()const {
	return m_id; // Errrrrrrrrrrrrrrrrrrrrrrrrrrror :( :( :( :( :( :( :(
}
string Product::GetName()
{
	return m_Name;
}

int Product::GetPrice()

{
	
	return m_Price;
}
