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
#include"Member.h"
#include"LMS.h"
#include"CollectionBooks.h"

using namespace std;

//****************************COMPOSITE CLASS*******************************//

class LoginSystem // Object Composition " A login system has a member credential"
{
private:
	MemberCredentials mem;//object used of another class
	int op;
public:
	//----------------------------------------------------------------------------------------------
	LoginSystem();//default constructor using member intializer list

	LoginSystem(MemberCredentials m, int o);//using parametrized constructor

	//----------------------------------------------------------------------------------------------
	void welcomeDisplay(); //display for the first screen including the project name and members

	//----------------------------------------------------------------------------------------------
	void userChoice();

	//----------------------------------------------------------------------------------------------
	void signup();
	//-------------------------------------------------------------------------------
	void login();

};
