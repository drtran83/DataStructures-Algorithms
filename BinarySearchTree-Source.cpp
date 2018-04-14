/*

CISS 350 - Week 6 - Binary Search Tree

This program is uses a binary search tree to store employee information from
employee.txt using the employee class.


----------------------------------------------------
Author : Tom T. Tran
Created : October 5, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------


*/

#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include "Employee.h"

using namespace std;

// Function prototypes

void import(BinarySearchTree &);
void runCheck(BinarySearchTree &);
void displayEmployee(Employee &);

int main() {


	cout << "CISS 350 - Week 6 - Binary Search Tree - Tom Tran" << endl;
	cout << "===================================================" << endl;

	// Local variables

	BinarySearchTree binaryTree;
	Employee agent;
	bool found = false;

	import(binaryTree);

	runCheck(binaryTree);

	//displayEmployee(agent);


	return 0;
}

// Functions

void import(BinarySearchTree &db)
{
	// local variables
	int intInput;
	string strInput;
	char ch = NULL;

	// Temporary object of employee
	Employee tempAgent;

	// set and open input file
	ifstream inFile;
	inFile.open("Employee.txt");

	// Import records until at the end of file.

	while (!inFile.eof() && ch != '\n')
	{

		// Import the Employee iD

		inFile >> intInput;
		inFile.ignore();
		tempAgent.setEmployeeNumber(intInput);

		// Import the Employee's Last name

		inFile >> strInput;
		inFile.ignore();
		tempAgent.setLastName(strInput);

		// Import the Employee's First Name

		inFile >> strInput;
		inFile.ignore();
		tempAgent.setFirstName(strInput);

		// Imprt the Employees Year's served

		inFile >> intInput;
		inFile.ignore();
		tempAgent.setYearsServed(intInput);


		// Insert Agent into tree.
		db.InsertItem(tempAgent);
	}

	// Close file

	inFile.close();


}


// runCheck, prompts user for a Agent's name and displays Agent if on current list of Agents.

void runCheck(BinarySearchTree &db)
{

	// local variables

	Employee currentAgent;
	int intInput;
	bool found = false;

	// Prompt for Agent ID

	cout << "\nEnter the agent's ID to see if they are on the list: ";
	cin >> intInput;

	// Check current list of possible Agents.
	currentAgent.setEmployeeNumber(intInput);

	// Find the agent
	db.RetrieveItem(currentAgent, found);

	// Display status

	if (found)
	{

		// Display Agent.

		cout << "\nAgent Information: ";
		displayEmployee(currentAgent);
	}

	else
		cout << "\nAgent was not found on the list of possible Agents." << endl;

}

void displayEmployee(Employee & agent) {

	cout << "\nAgent Id: " << agent.getEmployeeNumber() << endl;
	cout << "Agent's Last Name: " << agent.getlName() << endl;
	cout << "Agent's First Name: " << agent.getfName() << endl;
	cout << "Years Served: " << agent.getYears() << endl;
}