#pragma once
#include<iostream>
#include<string>
using namespace std;
class Product
{
private:
	int m_id; 
	string m_Name;
	string m_Number;
	double m_Price;
	int m_Type;

public:
	Product();
	int GetId()const;

	bool Update();
	friend ostream& operator<<(ostream&, Product&);
	friend istream& operator>>(istream&, Product&);
	string GetName();
	int GetPrice();
};

