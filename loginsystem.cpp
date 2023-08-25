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
#include"LoginSystem.h"
using namespace std;


LoginSystem::LoginSystem() :op(0)//default constructor using member intializer list
{}
LoginSystem::LoginSystem(MemberCredentials m, int o)//using parametrized constructor
{
	mem = m;
	op = o;
}
//----------------------------------------------------------------------------------------------
void  LoginSystem::welcomeDisplay() //display for the first screen including the project name and members
{
	system("Color 5E");//setting the console color
	cout << "\n\n\t\t  ___________________________________________________________________________________" << endl << "\t\t  ___________________________________________________________________________________" << endl << endl
		<< "\t\t\t_|||||              |||||{{{{{          }}}}}|||||       (((((((((((\n" << "\t\t\t_|||||              ||||| {{{{{        }}}}} |||||     ((((((\n"
		<< "\t\t\t_|||||              |||||  {{{{       }}}}}  |||||   ((((((\n" << "\t\t\t_|||||              |||||   {{{{     }}}}}   ||||| ((((((\n"
		<< "\t\t\t_|||||              |||||    {{{{{  }}}}}    |||||   ((((((\n" << "\t\t\t_|||||              |||||     {{{{{}}}}}     |||||     (((((())))))\n"
		<< "\t\t\t_|||||              |||||      {{{{}}}}      |||||            )))))))\n" << "\t\t\t_|||||[[[[[[[[[[[[  |||||                    |||||              )))))))\n"
		<< "\t\t\t_|||||[[[[[[[[[[[[  |||||                    |||||     ))))))))))))))\n" << "\t\t  ___________________________________________________________________________________" << endl
		<< "\t\t  ___________________________________________________________________________________" << endl;
	cout << "\n\t\t\t\t\t\t LIBRARY MANAGEMENT SYSTEM \n";
	system("pause");
}
//----------------------------------------------------------------------------------------------

void LoginSystem::userChoice()
{
	system("cls");
	system("Color 2E");//setting the console color
	cout << "\n\t\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		<< "\n\t\t\t\t\t     LIBRARY MANAGEMENT SYSTEM \n\t\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	do {
		cout << "\n\t\t\t\t\t   %-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%\n\t\t\t\t\t   $                             $"
			<< "\n\t\t\t\t\t   $ SIGN UP [1]                 $\n"
			<< "\t\t\t\t\t   $ LOGIN IN [2]                $\n"
			<< "\t\t\t\t\t   $ EXIT [0]                    $\n\t\t\t\t\t   $                             $\n\t\t\t\t\t   %-%-%-%-%-%-%-%-%-%-%-%-%-%-%-%";
		try {
			cout << "\n\t\t\t\t  ------------------------------------------------\n" << "\t\t\t-->>>>";
			cin >> op;
			if (op == 1)//for the user choice 1 moving to signup
			{
				signup();  break; system("cls");
			}
			else if (op == 2)//for the user choice 2 moving to login
			{
				login(); break; system("cls");
			}
			else if (op == 0)//for the user choice 0 exiting the program
				system("pause");


			//**********************EXCEPTION HANDLING***********************//
			else throw  " You entered wrong choice kindly RETYPE ";//if the user enters wrong choice then throwing exception
		}
		catch (const char* s)
		{
			cout << "\n\t\t\t\t   ERROR : " << s << endl;
		}
	} while (op != 1 && op != 2);// again displaying the menu for wrong choice
}
//----------------------------------------------------------------------------------------------
void LoginSystem::signup()
{
	cout << "\n\t\t\t\t   <<<<< FIll IN THE FOLLOWING DETAILS >>>>> " << endl;
	mem.setname();//setting the username
	mem.setemail();//setting the email
	do {

		//*********************EXCEPTION HANDLING********************//
		try {
			mem.setpass();//setting the password
			mem.setrepass();//setting the retyped password
			if (mem.getpass() == mem.getrepass())//matching the password and retyped password
				cout << "\n\t\t\t\t   You have Successfully Signed up to the system " << endl;
			else throw " Wrong Password ! Recheck your Password  ";//throwing exception if the password and retyped password don't match
		}
		catch (const char* s)
		{
			cout << "\n\t\t\t\t   ERROR : " << s << endl;
		}
	} while (mem.getpass() != mem.getrepass());//again displaying to retype password if the password and retyped password don't match
	ofstream myfile;
	try
	{
		myfile.open("member.txt", ios::app);//opening a file in append mode for writing(sequential file)
		//*********************EXCEPTION HANDLING********************//
		if (!myfile)
			throw " File could not be opened ";//throwing exception if the file doesn't open
	}
	catch (const char* s)
	{
		cout << "\n\t\t\t\t   ERROR : " << s << endl; exit(1);
	}
	myfile << mem.getname() << "\t\t" << mem.getemail() << "\t\t" << mem.getpass() << endl;//saving member data to file
	myfile.close();//closing the file
	cout << "\n\t\t\t\t\t You can now login into your account " << endl;
	login();//moving to the login menu
}//----------------------------------------------------------------------------------------------


void LoginSystem::login()
{


	LMS b;
	//----------------------------------------------------------------------------------------------
	//using vectors for dynamic arrays to append the user records
	vector< string> arrayname;
	vector<string> arrayemail;
	vector<string> arraypass;
	string name, email, pass;
	bool check = false;//setting bool value to false

	//*********************EXCEPTION HANDLING********************//
	ifstream myfil;
	try {
		myfil.open("member.txt", ios::in);//opening file for reading
		if (!myfil)//throwing exception if the file doesn't open
			throw " File could not be opened ";
	}
	catch (const char* s)
	{
		cout << "\n\t\t\t\t ERROR : " << s << endl; exit(1);
	}
	while (myfil >> name >> email >> pass)//input data from a text file.(sequential file)
	{
		//using push_back to add more strings to the vector arrays simultaniously increasing the size dynamically.
		arrayname.push_back(name);
		arrayemail.push_back(email);
		arraypass.push_back(pass);
	}
	myfil.close();//closing the file
	cout << "\n\t\t\t\t <<<<< LOGIN >>>>>" << endl;
	mem.setname1();//setting the username
	mem.setpass1();//setting the password
	for (int index = 0; index < arrayname.size(); index++) {
		//using arrays to compare the username and password with each ofthe records stored in the array
		if ((mem.getpass1() == arraypass[index]) && (mem.getname1() == arrayname[index] || mem.getname1() == arrayemail[index])) {
			check = true;
			cout << "\n\t\t\t\t You have successuly loged in " << endl;
			b.menu();//moving to the main menu incase of successful login
			break;
		}
	}
	if (check == false) {
		//displaying error incase of unsuccessful login
		cout << "\n\t\t\t\t INVALID username or password . \n\t\t\t\t Please recheck your username or password . " << endl
			<< "\t\t\t\t If you are not registered to the system then SIGN UP ." << endl;
		system("pause");
		userChoice();//moving to user choice.
	}
}