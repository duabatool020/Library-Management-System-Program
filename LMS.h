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
#include"CollectionBooks.h"

using namespace std;

//********************************DERIVED CLASS*****************************//
class LMS :public CollectionOfBooks
{
public:
	void AddBookrecord();//overrided function

	void showBooks();//overrided function

	void search();//overrided function

	void DeleteBooks();//overrided function

	void modifyRecord();//overrided function

	void totalBooks();//overrided function

	void calcdomain();//overrided function



	void menu();



	//************FRIEND FUNCTION + OPERATOR OVERLOADING********************//
	friend ostream& operator<<(ostream& output, LMS lms);
};

