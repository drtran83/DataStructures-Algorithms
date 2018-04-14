/*

CISS 350 - Week 4 - Circular Linked List Assignment 4 - Driver

The program will test and ensure that the circular linked list template class 
in UnsortedType.h works as it should.


----------------------------------------------------
Author : Tom T. Tran
Created : September 22, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------

*/

#include <iostream>
#include "UnsortedType.h"
using namespace std;

// Funciton prototypes

void displayList(UnsortedType<int> *, int);

int main() {
	

	cout << "\nCISS 350 - Week 4 - Assignment 4 - Circular Linked List - Tom Tran" << endl;
	cout << "==================================================================\n" << endl;

	// create a new list with Int type
	UnsortedType<int> *list = new UnsortedType<int>();

	cout << "\nFilling list with ints 1 through 20 " << endl;

	// Fill the list using a loop.

	int itm = 1;

	for (int i = 0; i < 20; i++) {

		list->InsertItem(itm);				// insert itm into the list
			itm++;							// increment itm
	}

	cout << "\nDisplaying List" << endl;

	// Display the list to prove that they have been inserted
	displayList(list, itm);

	cout << "\nResetting List" << endl;
	list->ResetList();

	cout << "\nNow deleting 10 from the list..." << endl;
	list->DeleteItem(10);

	// Redisplay list to prove that 10 was removed
	cout << "\nRedisplaying list" << endl;
	displayList(list, itm);

	// Reset the list again
	cout << "\nResetting List" << endl;
	list->ResetList();

	cout << "\nNow deleting 15 from the list..." << endl;
	list->DeleteItem(15);

	// Display the list again to prove that 15 was removed
	cout << "\nDisplaying list...." << endl;
	displayList(list, itm);

	cout << "\nNow reinserting 10 back into the list..." << endl;
	list->InsertItem(10);

	// Display the list again to prove that 10 was added.
	cout << "\nDisplaying list...." << endl;
	displayList(list, itm);

	cout << "\nResetting list...." << endl;

	// Reset the list for the last time.
	list->ResetList();

	cout << "\nDisplaying List...." << endl;
	// Display the list to prove it was reset.
	displayList(list, itm);

	cout << "\nbye bye!\n" << endl;
	return 0;
}

// Functions

void displayList(UnsortedType<int> *t, int i) {

	for (int index = 0; index < t->GetLength(); index++) {
		t->GetNextItem(i);
		cout << i << " ";
	}
	cout << endl;
}