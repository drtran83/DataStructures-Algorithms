/*

CISS 350 - Advanced Algorithms and Data Structures

This program will pull data from Employee.txt and store it to a linked list.
It will allow the user to add, remove, count and print the employees
from the list.


----------------------------------------------------
Author : Tom. T Tran
Created : September 8, 2017
Rev : 3
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------


*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class EmployeeList {

private:

	int employeeNumber;					// stores employee number
	string lName;						// stores last name
	string fName;						// stores first name
	int years;							// stores years served

	EmployeeList *next;					// next node

public:

	// default constructor
	EmployeeList();

	// Destructor

	~EmployeeList();

	// Constructor

	EmployeeList(int eN, string lN, string fN, int yr);

	EmployeeList (EmployeeList *node);

	// methods

	bool getData();
	void setNext(EmployeeList *next);
	void printData() const;
};

//*************
// Constructor*
//*************

EmployeeList::EmployeeList() {

	employeeNumber = 0;					// set Employee Number to 0
	lName = " ";						// set Last Name
	fName = " ";						// set First Name
	years = 0;							// set years

	next = NULL;						// set next to null
}

//********************
// Second constructor*
//********************

EmployeeList::EmployeeList(int eN, string lN, string fN, int yr) {

	employeeNumber = eN;
	lName = lN;
	fName = fN;
	years = yr;
}

//*************
// Destructor**
//*************

EmployeeList::~EmployeeList() {

}

//*******************
// Copy Constructor**
//*******************


EmployeeList::EmployeeList(EmployeeList *node)
{
	employeeNumber = node->employeeNumber;
	lName = node->lName;
	fName = node->fName;
	years = node->years;
}

// Methods

//************************************************************************************
// readData function will read file into linked list and print contents of the list.**
//************************************************************************************

bool EmployeeList::getData() {

	// local variables

	string firstName, lastName;
	int employeeNum, yearsServed, num;

	// Initialize variables

	firstName = " ";
	lastName = " ";
	employeeNum = 0;
	yearsServed = 0;

	//load and open file

	fstream inFile;
	inFile.open("Employee.txt");

	// Read data

	EmployeeList *head = NULL;

	while (!inFile.eof()) {

		inFile >> employeeNum >> lastName >> firstName >> yearsServed;

		EmployeeList *temp = new EmployeeList(employeeNum, lastName, firstName, yearsServed);
		temp->setNext(head);
		head = temp;
	}

	inFile.close();
	head->printData();

	return true;

}

//************************
// Recursive Print method*
//************************

void EmployeeList::printData() const {

	cout << employeeNumber << "   " << "\t" << lName << "   " << "\t\t" << fName << "  " << "\t\t" << years << endl << endl;

	if (next != NULL)
		next->printData();
}

//****************
// setNext method*
//****************

void EmployeeList::setNext(EmployeeList* nxt) {

	next = nxt;
}

// Function protypes

int menu();
void printList();
void addEmployee();
void removeEmployee();

int main() {

	cout << "CISS 350 - Programming Assignment 2: Employee List - Tom Tran" << endl;
	cout << "===============================================================\n" << endl;



	int menuChoice;

	do
	{
		menuChoice = menu();

		switch (menuChoice) {

			// 1. adds new employee

		case 1: 
			addEmployee();
			break;

			// 2. Removes employee

		case 2:
			removeEmployee();
			break;

			// 3. Counts employees
		case 3:
			break;


			// Prints List

		case 4: 
			printList();
			break;

		case 5:
			cout << "\nProgram ending... Good bye." << endl;
				break;

		}

	} while (menuChoice !=5);




	return 0;
}

//**************************************************************************
// menu function displays menu for the user to choose what they want to do.*
//**************************************************************************
int menu()
{
	int userChoice;

	cout << "\nEmployee List Menu" << endl;
	cout << "=====================" << endl;

	cout << "1. Add new Employee" << endl;
	cout << "2. Remove Employee" << endl;
	cout << "3. Count List" << endl;
	cout << "4. Print List" << endl;
	cout << "5. Quit." << endl;
	cout << "Enter your choice: ";
	cin >> userChoice;

	while (userChoice < 1 || userChoice > 5) {

		cout << "Invaid Choice, Re-enter (1-5): ";
		cin >> userChoice;
	}

	return userChoice;

}

//****************************************
// printList function prints out the list*
//****************************************

void printList() {

	EmployeeList list;								// nodes list object

	// output
	cout << endl;
	cout << "Age:" << "\tLast Name" << "\tFirst Name " << "\tYears Served: " << endl;

	if (list.getData())
		cout << "\nData has been read." << endl;

	else
		cout << "\nDoh! failed." << endl;


}

//*******************************************************
// add employee function should add employee to the list*
//*******************************************************

void addEmployee() {

	// local variables

	int employeeNumber, years;
	string lName, fName;

	employeeNumber = 0;
	years = 0;
	lName = " ";
	fName = " ";

	cout << endl;
	cout << "What is the employee's number?" << endl;
	cin >> employeeNumber;

	cout << "What is the employee's last name?" << endl;
	cin >> lName;

	cout << "What is the employee's first name?" << endl;
	cin >> fName;

	cout << "How many years did they serve? " << endl;
	cin >> years;

	//load and open file

	fstream inFile;
	inFile.open("Employee.txt");

	// Read data

	EmployeeList *head = NULL;

	while (!inFile.eof()) {

		inFile >> employeeNumber >> lName >> fName >> years;

		EmployeeList *temp = new EmployeeList(employeeNumber, lName, fName, years);
		temp->setNext(head);
		head = temp;
/*
		ofstream outFile;
		outFile.open("Employee.txt");

		outFile << employeeNumber << lName << fName << years << endl;
		outFile.close();
		*/
	}

	


	inFile.close();
	
}

//*****************************************************
// Remove employee function removes employee from list*
//*****************************************************

void removeEmployee() {


	// print list so that user can choose.

	printList();

	// new infile object and open the employee file.

	ifstream inFile;
	inFile.open("Employee.txt");

	int employeeNumber;

	cout << "\nWhich employee would you like to remove?" << endl;
	cin >> employeeNumber;

}
