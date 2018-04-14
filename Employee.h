/*
Definition file for Employee Class

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

#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;


class Employee {

private:

	int empNumber;							// stores Employee Number
	string firstName;						// stores First Name
	string lastName;						// stores Last Name
	int yearsServed;						// stores Years Served

public:

		// Default constructor

		Employee();

		// Constructor

		void setFields(int,string,string,int);

		// Setters

		void setEmployeeNumber(int eNum);
		void setFirstName(string fName);
		void setLastName(string lName);
		void setYearsServed(int yServed);

		void user();

		// Getters

		const int getEmployeeNumber();
		const string getfName();
		const string getlName();
		const int getYears();

		void print() const;

		// overload operators

		bool operator == (const Employee &);
		bool operator != (const Employee &);
};





#endif
