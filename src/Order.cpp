#include "Order.h"
Order::Order()
{
	m_number = 0;
	TransationsCounter = 0;
}
Order::Order(Stock* stock,Coustmers*coustmers)
{
	TransationsCounter = 0;
	stk = stock; 
	CoustmerOrder = coustmers;

	// assign to the porinter which stock can search 
	/*
		when i create Stock*stk;   = > he dont contain the adress of the stock 
		the soul is : when i create order i passing the adrees of the stock i created in the main fun
		and it spicify which stock i can find search function :) 
		DONE ^_^
		LOOK AT THE SMALL PAPER IN THE NOTE BOOK 
		*/
} 
void Order::AddItem(OrderItem&item)
{
	orderItemList[m_OrderItemCounter] = item;
	m_OrderItemCounter++;
}
void Order::SetOrderId() {
	srand(time(0));
	m_id = rand() % 1000 + 1; // generate a random number between 1 and 1000
}

int Order::GetOrderId() {
	return m_id;

}
double Order::GetTotalOrderPrice()
{
	return TotalOrderPrice;
}

void Order::EditOrder()
{
	cout << "> WHAT TO WANT TO EDIT IN YOUR ORDER ?\n    [1] Order Number .\n    [2] An Order Item .\n";
	int n; cout << "> SELECT ONE OPTION : "; cin >> n;
	switch (n)
	{
	case 1:
		SetNewOrderNumber();
		break;
	case 2 :
		cout << "> YOU HAVE " << m_OrderItemCounter << " ITEM IN YOUR ORDERS .\n\n";
		cout << ">> DO YOU WANT TO : \n    [1] Delete Item\n    [2] Update Item.\n   ";
		cout << "       > PLEASE ENTER ONE OPTION : "; int choice; cin >> choice;
		switch (choice)
		{
		case 1:
			// delete item by shiftihng
			break;
		case 2:
			cout << " >>  DO YOU KNOW THE ITEM WHICH YOU WANT TO UPDATE ?  (Y/N) ."; char c; cin >> c;
			if (c == 'y') {
				// choose which item
			}
			else if (c == 'n') {
				cout << "> OKEY WE WILL DISPLAY ALL THE ITEMS AND CHOOSE WHICH YOU WANT TO EDIT .\n";
				for (int i = 0; i < m_OrderItemCounter; i++) {
					cout << orderItemList[i];
				}//1 in array is 0
				cout << " >>>>>>>>> WHICH ITEM YOU WANT TO EDIT ? "; int itemindex; cin >> itemindex;
				//orderItemList[itemindex - 1].Update();
				
				if (orderItemList[itemindex - 1].Update() == true) {
					TotalOrderPrice -= orderItemList[itemindex - 1].ReturnTheNewPrice();
					// old total price - the price of the diff amount i rduced
				}
				else {
					TotalOrderPrice += orderItemList[itemindex - 1].ReturnTheNewPrice();
				}
			}


		}



	}
}

void Order::SetNewOrderNumber()
{
	cout << "> ENTER THE NEW NUMBER : "; cin >> m_number;
}

void Order::CreateOrder()
{
	bool IsCoustmerExeptionThrown = false;
	cout << "> PLEASE ENTER YOUR COUSTMER ID : "; int Coustmerid; cin >> Coustmerid;
	Coustmer* coustmer;
	coustmer = nullptr;
	try {
		 coustmer = CoustmerOrder->SearchForCoustmer(Coustmerid);
	}
	catch (const char* msg3) {
		cout << "ERROR : " << msg3;
		IsCoustmerExeptionThrown = true;
	}
	if (IsCoustmerExeptionThrown == false) {

		char AgainOrder;
		SetOrderId();
		coustmer->AddOrder(m_id);
		// coustmer which i found i add in it the id of the order 
		// fun in coustmer to print all the id order
		do {
			cout << "ENTER THE PRODUCT ID :"; int id; cin >> id;
			OrderItem orderitem;
			bool IsProductExpeotionThrown = false;
			bool IsAvalibleQuantityExpeotionThrown = false;
			try {
				orderitem.m_products = stk->Search(id);
			}
			catch (const char* msg) {
				cout << "> ERROR: " << msg << endl;
				AgainOrder = 'n';
				IsProductExpeotionThrown = true;
			}
			if (IsProductExpeotionThrown == false) {
				cout << "> ENTER THE QUANTITY YOU WANT : "; int Quan; cin >> Quan;
				orderitem.SetSaledQauntity(Quan);
				try {
					orderitem.ReduceTheQuantityInOrderItem();
				}
				catch (const char* msg) {
					cout << msg;
					cout << orderitem.GetAvalibleQuantity();
					AgainOrder = 'n';
					IsAvalibleQuantityExpeotionThrown = true;
				}
				// Stopped here error when i create 2 orders form the same product and the quantity ary not avalible 
				// he create and it is wrong
				if (IsAvalibleQuantityExpeotionThrown == false) {
					AddItem(orderitem);
					cout << "> ORDER HAS BEEN DONE SUCCESSFULLY WITH ID : " << m_id << "\n";
					cout << "  > YOU PAY       " << "X" << orderitem.GetSaledQuantity() << "  OF " << orderitem.GetNamePerUnit() << " - Price PerUnit " << orderitem.GetPricePerUnit() << "$\n";
					cout << "     > TOTAL IS : " << orderitem.GetTotalPrice() << "$"; Sleep(2000);
					TotalOrderPrice += orderitem.GetTotalPrice();
					cout << "\n  > DO YOU WANT TO ORDER AGAIN ? (y/n)"; cin >> AgainOrder;
				}


			}
		} while (AgainOrder == 'y');
	}
}

ostream& operator<<(ostream&out, Order&order)
{
	out << "\n\n      ========== ORDER ID : " << order.m_id << " ==========\n";
	for (int i = 0; i < order.m_OrderItemCounter; i++) {
		out << order.orderItemList[i];
	}	
	cout << ">>> TOTAL PRICE FOR ORDER : " << order.m_id << " IS : " << order.GetTotalOrderPrice()<<"$";
	return out;
}



void Order::AddTransaction(Transation& Transaction)
{
	TransactionsList.push_back(Transaction);
	TransationsCounter++;
}

void Order::ViewTransactons()
{
	cout << "\n >> YOUR TOTAL ORDER PRICE : " << TotalOrderPrice<<"\n";
	for (int i = 0; i < TransationsCounter; i++) {
		cout << " == TRANSACTION ID : " << TransactionsList[i].GetTransactionId() << " == .\n";
		cout << "- PaymentMethod : " << TransactionsList[i].GetPaymentMethodForTrans()<<"\n";
		 TransactionsList[i].Display();
	}

}
