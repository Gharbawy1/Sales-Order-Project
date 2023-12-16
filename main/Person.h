#pragma once
#include"Coustmer.h"
#include<string>
class Person :public Coustmer
{
private :
	string m_BilingAddress;
	string m_FullName;
	int m_PresonOrderCount;
public:
	Person();
	void Print();
	void SetData();
	int GetCoustmerId();
	void SetNewData();
	string GetName();
};

