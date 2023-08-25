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

using namespace std;


MemberCredentials::MemberCredentials()
{//default constructor
	name = name1 = email = pass = pass1 = repass = back = "N/A";//set all strings to N/A by default
}

void MemberCredentials::setname() {
	cout << "\n\t\t\t\t   USERNAME : "; cin >> name;
}
void MemberCredentials::setname1() {
	cout << "\n\t\t\t\t USERNAME / E-MAIL : "; cin >> name1;
}
void MemberCredentials::setemail() {
	cout << "\t\t\t\t   E-MAIL : "; cin >> email;
}
void MemberCredentials::setpass() {
	cout << "\t\t\t\t   PASSWORD : "; cin >> pass;
}
void MemberCredentials::setpass1() {
	cout << "\t\t\t\t   PASSWORD : "; cin >> pass1;
}
void MemberCredentials::setrepass() {
	cout << "\t\t\t\t   RE-TYPE your PASSWORD : "; cin >> repass;
}
void  MemberCredentials::setback(string back) {
	this->back = back; //using this method
}
//using get method
//------------------------------------------------------------------------------------------------
string MemberCredentials::getname() {
	return name;
}
string MemberCredentials::getname1() {
	return name1;
}
string MemberCredentials::getemail() {
	return email;
}
string MemberCredentials::getpass() {
	return pass;
}
string MemberCredentials::getpass1() {
	return pass1;
}
string MemberCredentials::getrepass() {
	return repass;
}
string MemberCredentials::getback() {
	return back;
}