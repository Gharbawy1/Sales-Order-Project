#include "Stock.h"
#include<Windows.h>
#include<iomanip>
void loading(int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << "OKEY !! PLEASE WAIT FEW SECOND UNTILL THERE IS A VACANT PALCE FOR THESE PRODUCTS ";
		for (int j = 0; j < i; j++)
		{
			cout << ".";
		}
		cout << endl;
		Sleep(100); // delay for 100 milliseconds
		system("cls"); // clear the console
	}

}
int Stock::Count = 0;
Stock::Stock() {

}
Stock::Stock(int UserSize) {
	//CountForOrder = 0;
	m_MAX_SIZE = UserSize;
	//ProductsList = new ProductQuan[m_MAX_SIZE];
}
ProductQuan* Stock::Search(int id)
{
		bool Isfound = false;
		for (int i = 0; i < Count; i++) {
			if (ProductsList[i].m_Product.GetId() == id) {// error
				Isfound = true;
				cout << "> PRODUCT FOUNDED SUCCESSFULLY \n";
				return &(ProductsList[i]);
			}
		}if (Isfound == false) {
			throw " NOT FOUNDED \n";

		}

}
void Stock::AddProductToStock() {
	bool IsProductFound = false;
	cout << "> Enter The Product ID : "; int id; cin >> id;
	for (int i = 0; i < Count; i++) {
		if (ProductsList[i].m_Product.GetId() == id) {
			cout << "> FOUNDED SUCCESSFULLY :)\n";
			system("pause");
			// Old Quantity+=new Quantity 
			cout << "> Please Enter The Product Quantity : "; int Quan; cin >> Quan;
			ProductsList[i].AddQuantity(Quan);
			cout << "> QUANTITY ADDED SUCCESSFULLY :) \n\n";
			IsProductFound = true;
			break;
		}
	}
	if (Count < m_MAX_SIZE ) { 
		if (IsProductFound == false) {
			cout << "> NOT FOUNDED :(\n";
			cout << "> DO YOU WANT TO ADD THIS NEW PRODUCT TO YOUR STOCK ? (y/n) "; char n; cin >> n;
			if (n == 'y') {
				//loading(9);
				ProductQuan product;
				product.SetProductData();// 0 => 
				product.SetQuantity();
				ProductsList[Count] = product;
				Count++;
			}
		}
		cout << ">> Product Added Successfully :)\n";
		system("pause");
	}
	else {
		cout << "> THIS STOCK IS FULL :(\n\n";
	}
}
void Stock::UpdateStockProduct() {
	bool IsProductFound = false;
	cout << "> Enter The Product ID : "; int id; cin >> id;
	for (int i = 0; i < Count; i++) {
		if (ProductsList[i].m_Product.GetId() == id) {
			IsProductFound = true;
			cout << "> FOUNDED SUCCESSFULLY :) \n\n";
			system("pause");
			//ProductsList[i].SetNewProductData();
			if (ProductsList[i].SetNewProductData() == false) // mean that user choosed updating Quantity
			{
				cout << "> Please Enter The Quantity : "; int MoreQuant; cin >> MoreQuant;
				ProductsList[i].AddQuantity(MoreQuant);
				cout << ProductsList[i].GetQuantity();
				//system("pause");
				break;
			}
		}
	}
	if (IsProductFound == false) {
		cout << "> NOT FOUNDED :(\n";
		system("pause");
	}
}
void Stock::DeleteProduct() {
	bool IsProductFound = false;
	cout << "> Enter The Product ID : "; int id; cin >> id;
	for (int i = 0; i < Count; i++) {
		if (ProductsList[i].m_Product.GetId() == id) {
			cout << "> FOUNDED SUCCESSFULLY :)\n";
			IsProductFound = true;
			cout << "ARE YOU SURE TO DELETE PRODUCT " << ProductsList[i].GetProductName() << " ID : " << ProductsList[i].m_Product.GetId() <<"(y/n)";
			char c;
			cin >> c;
			if (c == 'y')
			{
				cout << "> Product Deleted Successfully :) \n";
				while (i < Count - 1)
				{
					ProductsList[i] = ProductsList[i + 1];
					i++;
				}
				Count--;
				m_MAX_SIZE--;
				break;
			}
			else {
				break;
			}
		}
		system("pause");
	}if (IsProductFound == false) {
		cout << "Oh NOO !! Product NOT FOUND PLEASE SURE FROM YOUR DETAILS YOU ENTERD AND TRY AGAIN :\\ \n";
	}
}
int Stock::GetSpecificProductQuantity(int id) // to get quantity for specific product
{
	for (int i = 0; i < Count; i++) {
		if (ProductsList[i].m_Product.GetId() == id) {
			return ProductsList[i].GetQuantity();
			break;
		}
	}
	
}
void Stock::PrintAllProducts() {
	for (int i = 0; i < Count; i++) {
		ProductsList[i].PrintProductData();
	}
}