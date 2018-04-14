/*

CISS 350 - Week 3 - Employee List Program using Queue

This program will load an employee list in to a queue.
The program will allow the user to add, remove, check list size
and quit.


----------------------------------------------------
Author : Tom T. Tran
Created : September 15, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------

*/

#include <iostream>
#include "ListQueue.h"


using namespace std;

struct Node {
	ListQueue nodeQueue;				// listqueue object
	agent aName;						// agent object
};

// function prototypes


int main() {

	cout << "\nCISS 350 - Week 3 - Employee List program using Queue - Tom Tran" << endl;
	cout << "==================================================================\n" << endl;

	Node node[10];							// Array of 10 positions
	int tempNode = 5;						// sets position we will be working with to the 4th node

	agent tempAgent;						// creates a agent struct as defined in our queue

	cout << "\nEnter the agent's Employee Number: ";
	cin >> tempAgent.empNumber;

	cout << "Enter the agent's last name: ";
	cin >> tempAgent.lname;

	cout << "Enter the agent's first name: ";
	cin >> tempAgent.fname;

	cout << "Enter years served by the agent: ";
	cin >> tempAgent.yearsServed;

	// add to queue

	node[tempNode].nodeQueue.enqueue(tempAgent);

	cout << "\nEnter the agent's Employee Number: ";
	cin >> tempAgent.empNumber;

	cout << "Enter the agent's last name: ";
	cin >> tempAgent.lname;

	cout << "Enter the agent's first name: ";
	cin >> tempAgent.fname;

	cout << "Enter years served by the agent: ";
	cin >> tempAgent.yearsServed;

	// add to queue

	node[tempNode].nodeQueue.enqueue(tempAgent);

	// output queue length

	cout << "\nThe queue length is: " << node[tempNode].nodeQueue.getLength() << endl;
	
	// dequeue

	node[tempNode].nodeQueue.dequeue(tempAgent);

	// output queue length again

	cout << "The queue length is: " << node[tempNode].nodeQueue.getLength() << endl;

	// dequeue again

	node[tempNode].nodeQueue.dequeue(tempAgent);

	// output queue length last time

	cout << "The queue length is: " << node[tempNode].nodeQueue.getLength() << endl;


	return 0;

}





