#pragma once
#include"Product.h"
#include"ProductQuan.h"
class OrderItem
{
private :
	
	double m_OrderQuantity_WillSaled;
	double m_SalePrice;
	int NewDiffrecneQuantity; //  this var will be used when i want to calc the price of الفرق بين الكميله الجديده والقديمه 
public:	
	ProductQuan *m_products;
	void SetSaledQauntity(int);
	double GetSaledQuantity(); // Saled Quantity
	double GetTotalPrice();
	double GetPricePerUnit();
	string GetNamePerUnit();
	void ReduceTheQuantityInOrderItem();
	int GetAvalibleQuantity();
	friend ostream& operator<<(ostream&, OrderItem&);
	bool Update();
	// i will make a function that return the new quan if i ubdate the ordred
	// to make me know الفرق بين الكميه القديمه والجديده عشان اقدر احسب الفرق ف 
	// محموع السعر
	void ReturnTheNewQuan(int);
	int ReturnTheNewPrice();// عشان احسب فرق الفلوس لو بالنقصان واقدر اطرحه من الاجمالي

};

//مسؤوليه كلاس اوردر ايتم هو حساب كل منتج لوحده بكميته و السعر الفردي للمنتج