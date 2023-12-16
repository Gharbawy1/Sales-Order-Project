#include "OrderItem.h"

void OrderItem::SetSaledQauntity(int OrderdQuantity)
{
	m_OrderQuantity_WillSaled = OrderdQuantity;
}

double OrderItem::GetSaledQuantity()
{
	return m_OrderQuantity_WillSaled;
}

double OrderItem::GetTotalPrice()
{
	return (m_products->GetPrice())* m_OrderQuantity_WillSaled;
}

void OrderItem::ReduceTheQuantityInOrderItem()
{
	m_products->ReduceTheQuantity(m_OrderQuantity_WillSaled);
}

int OrderItem::GetAvalibleQuantity()
{
	return m_products->GetQuantity();
}
//i will make it boolean because in order class i want to know if i reduce the total
// price if i reduse then i will decrase the total price by the amount of the diff
bool OrderItem::Update()
{
	cout << "> PLEASE ENTER THE NEW QUANTITY YOU WANT TO PUY : "; int NewQuan; cin >> NewQuan;
	if (GetSaledQuantity() > NewQuan) {
		//50    450      500   
		// mean he reduce the quantity 
		// add the diff in stock 
		// and reduce from salled quantity 
		ReturnTheNewQuan(GetSaledQuantity() - NewQuan);
		// it get the diff between the old value and the new value
		m_products->AddQuantity(GetSaledQuantity() - NewQuan); // add the old quntity already paid and reduce form the base Quanity again 
		SetSaledQauntity(NewQuan); // for the current item
		return true;
		///////// endddddddddd here 7:44
	}
	else if (GetSaledQuantity() < NewQuan){

		ReturnTheNewQuan(abs(GetSaledQuantity() - NewQuan));

		try {
			m_products->AddQuantity(GetSaledQuantity());
			m_products->ReduceTheQuantity(NewQuan);
		}
		catch (char* msg) {
			cout << ">> ERORR : " << msg << "\n";

		}
		SetSaledQauntity(NewQuan);
		return false;// mean i increase the total price 
	}

}

void OrderItem::ReturnTheNewQuan(int NewQuan)
{
	// since the order item has a new quantity
	NewDiffrecneQuantity =  NewQuan;
}

int OrderItem::ReturnTheNewPrice()
{
	return GetPricePerUnit()*NewDiffrecneQuantity;
}



double OrderItem::GetPricePerUnit() {
	return m_products->GetPrice();
}
string OrderItem::GetNamePerUnit()
{
	return m_products->GetProductName();
}

ostream& operator<<(ostream&out, OrderItem&orderitem)
{
	out << "> YOU PAIED X" << orderitem.m_OrderQuantity_WillSaled<<" OF "<<orderitem.GetNamePerUnit()<<"\n";
	out << "> PRICE PRE UNIT : " << orderitem.GetPricePerUnit();
	out << "\n> TOTAL IS : "<<orderitem.GetTotalPrice()<<"$\n";
	out << "------------------------------\n";
	return out;
}
