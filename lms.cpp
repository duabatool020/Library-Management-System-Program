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
#include"LMS.h"

using namespace std;

void LMS::AddBookrecord()//overrided function
{

	LMS b;

	//**********************FILE HANDLING*****************************//
	ofstream add("Books.dat", ios::app);//opening file for writing in appened mode
	if (!add)
	{
		cerr << "File not found" << endl;
		exit(1);
	}
	char choice;
	do
	{
		system("cls");
		cin.ignore();
		cout << "Enter name of Book: ";gets_s(b.nameOfBook);
		cout << "Enter Author of Book: ";gets_s(b.authOfBook);
		cout << "Enter domain of Book: ";gets_s(b.domainOfBook);
		cout << "Enter Date of publish of Book[dd-mm-yy]";gets_s(b.publishDate);
		add.write(reinterpret_cast<char*>(&b), sizeof(b));//converting objects in streams/characters
		cout << "Do you want to add more book records[y/n]?";cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	add.close();//closing the file

}

void LMS::showBooks()//overrided function
{
	LMS b;
	//******************************FILE HANDLING***************************
	ifstream showBooks("Books.dat");//opening book for writing
	if (!showBooks)
	{
		cerr << "File not found " << endl;
		system("pause");
		exit(1);
	}
	while (!showBooks.eof())//it runs the loop until it reads the end of file marker
	{
		showBooks.read(reinterpret_cast<char*>(&b), sizeof(b));//converting the object in to streams/characters
		cout << b;//stream insertion operator is overloaded for LMS below
	}
	showBooks.clear();//because the file is in eof mode so to clear this we use this function
	showBooks.seekg(0);//the position pointer will move to the start of file
	showBooks.close();//closing the book
}

void LMS::search()//overrided function
{
	system("cls");
	LMS b;
	char name[40];
	int t = 0;
	int marker = 0;
	//******************************FILE HANDLING************************//
	ifstream search("Books.dat");//opening book for reading
	if (!search)
	{
		cerr << "file not found" << endl;
		exit(1);
	}

	system("cls");
	cin.ignore();
	cout << "Enter name of book you want to search: ";gets_s(name);

	while (search.read(reinterpret_cast<char*>(&b), sizeof(b)))//converts the object in streams/ charactrs
	{
		if (strcmp(name, b.nameOfBook) == 0)//comparing two character arrays and seeing that if they are equal
		{
			cout << "Book Found!" << endl;
			cout << "Here is the Record of the Book" << endl;
			//when the book will match the file pointer comes at the end of that book
			//to take it to start of that book we will do following steps
			marker = (marker - 1) * sizeof(b);//it will calculate the poistion of object in bytes

			search.seekg(marker);//it will place the file pointer at that byte
			cout << b;
			t = 1;

		}

	}
	if (t == 0)
	{
		cerr << "Book not found" << endl;
		exit(1);
	}
	search.close();
}
void LMS::DeleteBooks()//overrided function
{
	system("cls");
	LMS b;
	char name[40];
	int t = 0;
	//**************************FILE HANDLING**************************

	ifstream del("Books.dat");//opening a file for reading
	ofstream temp("newfile.dat");//opening a file for writing
	if (!del)
	{
		cerr << "File not found" << endl;
		exit(1);
	}
	cin.ignore();
	cout << "Enter name of book you want to delete: ";gets_s(name);
	while (del.read(reinterpret_cast<char*>(&b), sizeof(b)))//it will convert the object in streams/characters
	{
		if (strcmp(name, b.nameOfBook) == 0)//comparing two character arrays and checking if they are equal
		{
			cout << b;//stream insertion operator has been overloaded for LMS below
			t = 1;//this means book matches

		}
		if (strcmp(name, b.nameOfBook) != 0)//comparing two character arrays and checking if they are not equal
		{
			//writing all the object other than the matched one in the file newfile.dat
			temp.write(reinterpret_cast<char*>(&b), sizeof(b));//converting the objects in streams/characters
		}
	}
	if (t == 0)//this means book not matches
	{
		cerr << "Book not found" << endl;
		del.close();
		exit(1);
	}
	if (t == 1)//this means book matches
	{
		del.close();//closing book books.dat
		temp.close();//closing book temp.dat
		remove("Books.dat");//it will remove the file books.dat which have only matched object
		rename("newfile.dat", "Books.dat");//it will rename the file newfile.dat with books.dat
		cout << "Book record deleted successfully" << endl;

	}


}

void LMS::modifyRecord()//overrided function
{
	LMS b;

	//**********************FILE HANDLING************************//
	fstream modify("Books.dat", ios::in | ios::out);//opening file for reading and writing
	if (!modify)
	{
		cerr << "file not found" << endl;
		exit(1);
	}
	char name[40];
	int t = 0, marker = 0;


	system("cls");
	cin.ignore();
	cout << "Enter the name of Book you want to modify ";gets_s(name);

	while (modify.read(reinterpret_cast<char*>(&b), sizeof(b)))//converting the object into streams/charachter
	{
		if (strcmp(name, b.nameOfBook) == 0)//comparing the character arrays and seeing that if the array matches or not
		{
			marker = marker * sizeof(b);//when record is found the cursor is at the end of that object to to take the 
			//cursor at the starting of that object we will write this to calculate the bytes
			modify.seekg(marker);//it will take the cursor to calculated byte
			cout << "Enter Book name: ";
			gets_s(name);
			if (strlen(name) > 0)//checking if user enter something to modify previous record
			{
				strcpy_s(b.nameOfBook, name);//it will copy the previous name of the book with the new name
			}
			cin.ignore();
			cout << "Enter Name of author ";
			gets_s(name);
			if (strlen(name) > 0)//checking if user enter something to modify previous record
			{
				strcpy_s(b.authOfBook, name);//it will copy the previous author of the book with the new author
			}
			cin.ignore();
			cout << "Enter domain of book ";
			gets_s(name);
			if (strlen(name) > 0)//checking if user enter something to modify previous record
			{
				strcpy_s(b.domainOfBook, name);//it will copy the previous domain of the book with the new domain
			}
			cin.ignore();
			cout << "Enter date of publish of book ";
			gets_s(name);
			if (strlen(name) > 0)//checking if user enter something to modify previous record
			{
				strcpy_s(b.publishDate, name);//it will copy the previous date of the book with the new date
			}
			modify.write(reinterpret_cast<char*>(&b), sizeof(b));//convert the objects in streams/characters and
			//write the new updated record in the file
			modify.close();//closing the file
			t = 1;//it means record found

		}
		marker++;

	}
	if (t == 0)//it means record not found
	{
		cout << "Record not found" << endl << endl;
		exit(1);
		modify.close();
	}


}

void LMS::totalBooks()//overrided function
{
	LMS b;
	int count = 0;
	int marker = 0;
	//***********************FILE HANDLING**************************//
	ifstream books("Books.dat", ios::in);//opening file for reading
	while (books.read(reinterpret_cast<char*>(&b), sizeof(b)))//convert the object into streams/characters
	{
		if (marker == marker * sizeof(b))//it is calculating the size of object in bytes
			//after calculating 1 object byte(after reading 1 object) it will increment the count
		{
			count++;
		}
	}
	cout << "No of books in file are: " << count << endl;
	books.close();//closing book
}


void LMS::calcdomain()//overrided function
{
	system("cls");
	LMS b;
	//intializing and declaring different variables,objects and arrays
	char name[40];
	int count = 0;
	char choice; int number; vector<string> domain;
	int marker = 0;//setting the marker to zero
	do {
		system("cls");
		string copy;
		cout << " How many Books would you like to choose/issue : "; cin >> number;//asking the user to choose 
		for (int index = 1; index <= number; index++)
		{
			cin.ignore();
			cout << "Enter name of " << index << " book you want to choose : "; gets_s(name);
			ifstream caldo("Books.dat");//opening file for reading (data file)

			//**********************EXCEPTION HANDLING*********************//
			try {
				if (!caldo)
					throw " File could not be opened ";//throwing exception if the file doesn't open
			}
			catch (const char* s)
			{
				cout << "\n\t\t\t\t   ERROR : " << s << endl; exit(1);
			}//end of exception handling

			while (caldo.read(reinterpret_cast<char*>(&b), sizeof(b)))//input data from the file
			{
				if (strcmp(name, b.nameOfBook) == 0)//comparing the names of books
				{
					marker = (marker - 1) * sizeof(b);
					caldo.seekg(marker);//seeking the position where the marker is found
					copy = b.domainOfBook;
					domain.push_back(copy);//intializing the vector array with domains
				}
			}
			caldo.close();//closing the file
		}
		//computeing how many books of specific domain has been chosen by the applicant. 
		for (int j = 0; j < number; j++)//loop to choose the domains individually 
		{
			for (int index = 0; index < number; index++)//loop to compare the domains individually
			{
				if (domain[j] == domain[index])//comparing domains
					count++;
			}
			cout << " You chose " << count << " Books of " << domain[j] << endl;//output the result on screen
			count = 0;
		}
		cout << " Do you want to choose/issue the books again :[y/n]?"; cin >> choice;//asking if the again run the operation
	} while (choice == 'y');//loop to again run the operation on condition
}


void LMS::menu()
{
	CollectionOfBooks* b;//Pointer to base class
	LMS lms;
	b = &lms;//storing address of derived class in base class
	int choice;
	char op;
	cout << endl;
	cout << "      ***************************************************MAIN MENU**********************************************" << endl << endl;
	cout << "\n\t\t\t\t\t %-%-%-%-%-%-%-%-%-%-%-%-%-%-%-% \n\t\t\t\t\t $                             $"
		<< "\n\t\t\t\t\t $   MAIN MENU   [1]           $"
		<< "\n\t\t\t\t\t $   EXIT        [0]           $\n\t\t\t\t\t $                             $\n\t\t\t\t\t %-%-%-%-%-%-%-%-%-%-%-%-%-%-%-% \n";
	cout << "\t\t     _____________________________________________________________________________" << endl << endl;
	cout << "\n\t\t\t\t\t ---->Enter your choice :  "; cin >> choice;
	switch (choice)
	{
	case 0:
		exit(1);
	case 1:
		do
		{
			system("Color 4E");
			int ch;
			system("cls");
			cout << "\n\n\t\t\t\t\t =================LMS MENU==================="
				<< "\n\n\t\t\t\t\t ?   1-ADD BOOKD                            ?"
				<< "\n\n\t\t\t\t\t ?   2-SEARCH BOOKS                         ?"
				<< "\n\n\t\t\t\t\t ?   3-DELETE BOOKS                         ?"
				<< "\n\n\t\t\t\t\t ?   4-MODIFY BOOKS                         ?"
				<< "\n\n\t\t\t\t\t ?   5-TOTAL BOOKS                          ?"
				<< "\n\n\t\t\t\t\t ?   6-SHOW BOOKS                           ?"
				<< "\n\n\t\t\t\t\t ?   7-CALCULATE DOMAIN BOOKS / ISSUE BOOKS ?"
				<< "\n\n\t\t\t\t\t ?   8-EXIT                                 ?"
				<< "\n\n\t\t\t\t\t =================LMS MENU===================" << endl
				<< "\n\n\t\t\t\t----->>Enter your choice :  "; cin >> ch;
			system("cls");
			switch (ch)
			{
			case 1:
				b->AddBookrecord();//dynamic binding //calling virtual function with base class pointer
				break;
			case 2:
				b->search();//dynamic binding //calling virtual function with base class pointer
				break;

			case 3:
				b->DeleteBooks();//dynamic binding //calling virtual function with base class pointer
				break;
			case 4:
				b->modifyRecord();//dynamic binding //calling virtual function with base class pointer
				break;
			case 5:
				b->totalBooks();//dynamic binding //calling virtual function with base class pointer
				break;
			case 6:
				cout << endl << endl;
				b->showBooks();//dynamic binding //calling virtual function with base class pointer
				break;
			case 7:
				b->calcdomain();//dynamic binding //calling virtual function with base class pointer
				break;
			case 8:
				exit(1);
				system("pause");
				break;
			}

			cout << "Do you want to choose from main menu again[y/n]?"; cin >> op;
		} while (op == 'y' || op == 'Y');
	}
}


ostream& operator<<(ostream& output, LMS lms)//overloading operator for LMS
{
	output << "BOOK NAME: " << lms.nameOfBook << setw(20) << "AUTHOR NAME: " << lms.authOfBook << setw(20) << "BOOK DOMAIN: " << lms.domainOfBook << setw(20) << "PUBLISH DATE: " << lms.publishDate << endl;
	output << "__________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	output << endl;
	return output;
}