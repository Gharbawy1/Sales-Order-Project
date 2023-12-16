#include "ProductQuan.h"
ProductQuan::ProductQuan() {
	m_Quantity = 0;
}

int ProductQuan::GetPrice()
{
	return m_Product.GetPrice();
}

void ProductQuan::SetQuantity()
{
	cout << "> Enter The Product Quantity : "; cin >> m_Quantity;
}

bool ProductQuan::SetNewProductData()
{
	return m_Product.Update();
}
/*
ostream& operator<<(ostream& out, ProductQuan& product) {
		 out << product.m_Product;

	return out;
}
istream& operator>>(istream& input, ProductQuan& product) {
	input >> product.m_Product;
	return input;
}*/
/*
int ProductQuan::GetProductId() {
	return m_Product.GetId();
}*/
void ProductQuan::SetProductData()
{
	cin >> m_Product;
}
void ProductQuan::PrintProductData()
{
	cout << m_Product;
	cout << "\n- QUNATITY : " << m_Quantity;
	cout << "\n-----------------------------\n";

}


string ProductQuan::GetProductName()
{
	return m_Product.GetName();
}

int ProductQuan::GetQuantity()
{
	return m_Quantity;
}
void ProductQuan::AddQuantity(int MoreQuan) {
	m_Quantity += MoreQuan;
}
void ProductQuan::ReduceTheQuantity(int SaledQuan) {
	if (m_Quantity >= SaledQuan) {
		m_Quantity -= SaledQuan;
	}
	else {
		throw"> Sorry :( , This Quantity Is Not Available now :(\n\n  > THE AVALIBLE QUANTITY OF THIS PRODUCT NOW IS : ";
		system("pause");
	}
}





