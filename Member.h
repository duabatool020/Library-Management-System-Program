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

class MemberCredentials // Object Composition " A login system has a member credential"
{
	//------------------------------------------------------------------------------------------------
private: //private members having all the credentials of a member
	string name, name1, email, pass, pass1, repass, back;
public:
	//------------------------------------------------------------------------------------------------
	MemberCredentials();//default constructor
	//using set methods individually to get the credential from user and set them to specific private members
	//------------------------------------------------------------------------------------------------
	void setname();
	void setname1();
	void setemail();
	void setpass();
	void setpass1();
	void setrepass();
	void setback(string back);
	//using get method
	//------------------------------------------------------------------------------------------------
	string getname();
	string getname1();
	string getemail();
	string getpass();
	string getpass1();
	string getrepass();
	string getback();
};
