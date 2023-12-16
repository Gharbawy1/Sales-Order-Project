#pragma once
#include"Coustmer.h"
#include"Company.h"
#include"Person.h"
class Coustmers
{
private :
	static int CoustmersClassCounter;
	Coustmer** CoustmerList;
	int SizeOfCoustmersList;
public:
	Coustmers(int);
	void AddCoustmer(); //done
	void AddCopmany(); // done
	void AddPerson(); // done
	void EditCoustmer(); // done
	void Search(string); // done
	void SearchSubString(); // done
	void DeleteCoustmer();// done
	bool Search(int);
	void Print();// done 
	Coustmer* SearchForCoustmer(int);// done
	void PrintIdForSpiceficCoustmer();
};

