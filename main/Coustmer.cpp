#include "Coustmer.h"
int Coustmer::Count = 0;

Coustmer::Coustmer()
{
	Count++;
	m_id = Count;
	OrderCounter = 0;
}

void Coustmer::AddOrder(int id)
{
	OrdersListID[OrderCounter] = id;
	OrderCounter++;
}

void Coustmer::PrintOrders()
{
	for (int i = 0; i < OrderCounter; i++) {
		cout << ">> ORDER " << i+1 << " ID : " << OrdersListID[i] <<"\n";
	}
}

/*
void Coustmer::SetCount(int Coun)
{
	AllOrdersMainCounter = Coun;
}*/





