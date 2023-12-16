#pragma once
#include"Coustmer.h"
class Company : public Coustmer
{
private :
	string m_Location;
	string m_CompanyName;

public :
	Company();
	void Print();
	void SetData();
	void SetNewData();
	int GetCoustmerId();
	string GetName();
	
};


