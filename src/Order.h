#pragma once
#include"OrderItem.h"
#include"Stock.h"
#include"Transation.h"
#include<vector>
#include"Coustmers.h"
//#include"Person.h"
#include<Windows.h>
#include <cstdlib>
#include <ctime>
class Order
{
private :
	int m_id; // cant be edited
	int m_number;
	//time date;
	double m_Total;
	OrderItem orderItemList[10];
	int m_OrderItemCounter;
	Stock* stk;
	Coustmers* CoustmerOrder;//  to call search function
	double TotalOrderPrice;
	vector<Transation> TransactionsList;
	int TransationsCounter;
public:
	Order();
	Order(Stock *, Coustmers*);
	void AddItem(OrderItem&);
	void CreateOrder(); 
	void SetOrderId(); 
	int GetOrderId();
	friend ostream& operator<<(ostream&, Order&); 
	double GetTotalOrderPrice(); 
	void EditOrder(); 
	void SetNewOrderNumber();

	
	void AddTransaction(Transation&);
	void ViewTransactons();
};

