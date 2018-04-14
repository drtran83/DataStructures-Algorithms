/*
Definition file for Employee class

CISS 350 - Week 3 - Employee List Program using Queue

This program will load an employee list in to a queue.
The program will allow the user to add, remove, check list size
and quit.


----------------------------------------------------
Author : Tom T. Tran
Created : October 5, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------
*/

#include <iostream>
#include "Employee.h"
using namespace std;


// Default constructor

Employee::Employee() {

	empNumber = 0;
	lastName = " ";
	firstName = " ";
	yearsServed = 0;
}

// Constructor

void Employee::setFields(int eN, string lN, string fN, int yS){

	empNumber = eN;
	lastName = lN;
	firstName = fN;
	yearsServed = yS;
}

// Setters

void Employee::setEmployeeNumber(int eNum) {

	empNumber = eNum;
}

void Employee::setLastName(string lName) {

	lastName = lName;
}

void Employee::setFirstName(string fName) {

	firstName = fName;
}

void Employee::setYearsServed(int yServed) {

	yearsServed = yServed;
}

// Getters

const int Employee::getEmployeeNumber(){

	return empNumber;
}

const string Employee::getlName(){

	return lastName;
}

const string Employee::getfName(){

	return firstName;
}

const int Employee::getYears(){

	return yearsServed;
}

// Print function 

void Employee::print() const {

	cout << "Employee Number: ";
	cout << empNumber << endl;
	cout << "Name: ";
	cout << firstName << " " << lastName << endl;
	cout << "Years of Service: " << yearsServed << endl << endl;
}

// Overloaded Operators

bool Employee::operator == (const Employee &right)
{
	bool status;
	if (empNumber == right.empNumber)
		status = true;
	else
		status = false;
	return status;
}

bool Employee::operator != (const Employee &right)
{
	bool status;

	if (empNumber != right.empNumber)
		status = true;
	else
		status = false;
	return status;
}

void Employee::user()
{
	string iString;
	int iNumber;

	cout << "Employee Number ";
	cin >> iNumber;
	while (iNumber <= 0)
	{
		cout << "Employee Number ";
		cin >> iNumber;
	}
	empNumber = iNumber;

	cout << "Last Name: ";
	cin >> iString;
	lastName = iString;

	cout << " First Name: ";
	cin >> iString;
	firstName = iString;

	cout << "Years Served: ";
	cin >> iNumber;
	while (iNumber < 0)
	{
		cout << "Years Served ";
		cin >> iNumber;

	}
	cout << endl;
	yearsServed = iNumber;

}