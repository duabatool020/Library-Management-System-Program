#pragma once
#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
//#include<assert.h>
#include<cstdlib>
#include <stdlib.h>
#include<iomanip>
//#include<ctype.h>
#include <vector>


using namespace std;

//\\\\\\\\\\\\\\\\\\\\\\POLYMORPHISIM\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  
//**********************BASE CLASS/ABSTRACT CLASS********************//
class CollectionOfBooks
{
protected:
	char nameOfBook[40];
	char authOfBook[40];
	char domainOfBook[40];
	char publishDate[40];
public:
	virtual void AddBookrecord() = 0;//pure virtual function
	virtual void showBooks() = 0;//pure virtual function
	virtual void search() = 0;//pure virtual function
	virtual void modifyRecord() = 0;//pure virtual function
	virtual void DeleteBooks() = 0;//pure virtual function
	virtual void totalBooks() = 0;//pure virtual function
	virtual void calcdomain() = 0;//pure virtual function
};//end of base class

