#pragma once
#include"Product.h"
class ProductQuan 
{
private:
	int m_Quantity;

public:
	//friend ostream& operator<<(ostream&, ProductQuan&);
	//friend istream& operator>>(istream&, ProductQuan&);
	ProductQuan();
	int GetPrice();
	Product m_Product;

	void SetQuantity();
	int GetQuantity();
	
	bool SetNewProductData();
	void SetProductData();
	
	void PrintProductData();
	
	//int GetProductId();
	string GetProductName();
	
	void AddQuantity(int);
	void ReduceTheQuantity(int);
	
};

