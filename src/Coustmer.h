#pragma once
#include<iostream>
#include<string>
//#include"Order.h"
using namespace std;
class Coustmer
{
protected:
	string m_Phone;
	int m_id;
public:
	int OrderCounter;
	int OrdersListID[10];
	static int Count;
	Coustmer();
	virtual void SetData()=0;
	virtual void Print()=0;
	virtual void SetNewData() = 0;
	virtual int GetCoustmerId() = 0;
	virtual string GetName() = 0;
	void AddOrder(int);
	void PrintOrders();
};
