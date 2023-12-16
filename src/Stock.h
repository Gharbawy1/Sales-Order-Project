#pragma once
#include"Product.h"
#include"ProductQuan.h"
class Stock
{
private:
	int m_MAX_SIZE;
	static int Count;
	ProductQuan ProductsList[50];

public:

	Stock();
	Stock(int);
	void AddProductToStock();
	void UpdateStockProduct();
	void DeleteProduct();
	int GetSpecificProductQuantity(int);
	//static int GetCounter();
	ProductQuan* Search(int);
	void PrintAllProducts();
};
	 

