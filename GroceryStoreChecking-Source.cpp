/*
CISS 350 - Advanced Algorithms and Data Structures

Week 1
DropBox Assignment 1

Grocery Store Checkout System

This program will simulate a grocery store checkout system.
It will use a struct to hold the products in the store's inventory stored in an array.

The inventory is uploaded through a file Invent.txt and
Reciepts will be printed out to a file Reciepts.txt.

The program will have a search function to search through Invent.txt to check
to see if cashier entered item number is found in inventory.


----------------------------------------------------
Author : Tam T.Tran
Created : September 2, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>					// For time addition to reciept

using namespace std;

int main() {

	cout << "CISS 350 - Week 1 - Grocery Store Checkout System - Tom Tran" << endl;
	cout << "============================================================" << endl;

	cout << "\nHere is a reference of the item numbers, description and price." << endl;
	cout << "=================================================================" << endl;

	cout << "Item Number \t Description \t Price \t Tax" << endl;
	cout << "11012 \t\t gallon-milk \t $1.99 \t N" << endl;
	cout << "11014 \t\t butter \t $2.59 \t N" << endl;
	cout << "11110 \t\t pie-shells \t $0.99 \t N" << endl;
	cout << "20115 \t\t laundry-soap \t $3.60 \t T" << endl;
	cout << "30005 \t\t homestyle-br \t $0.99 \t N" << endl;

	// Structure that holds the product information

	struct Inventory {

		int inventoryNumber;							// stores inventory number
		string productDescritption;						// stores description of the product
		double priceofItem;								// stores price of product
		char tax;										// stores char of the tax N or T

	};


	// Variables

	int inventoryNumber = 0;								// for cashier search of inventory number
	int quantity = 0;										// to hold how many items customer purchased

	char doContinue;										// continue y or n?
	bool found;												// bool to store found
	bool isTaxed;											// bool to if item is taxed

	double customerNum = 0.0;								// stores customer number
	const double TAX = 0.075;								// stores tax rate
	double itemPrice = 0.0;									// stores item price
	double quantityPrice = 0.0;								// stores quantity times item price
	double subTotal = 0.0;									// stores subtotal
	double total = 0.0;										// stores total

	Inventory inventoryRecords[50];						// Struct Array of max 50 inventory records.

	// Open input file and read from it.

	ifstream inputFile;									// inputfile object
	inputFile.open("Invent.txt");						// opens and reads invent.txt

	//**************************************************
	// populate the array using inputfile using for loop
	//**************************************************

	for (int i = 0; i < 50; i++) {

		inputFile >> inventoryRecords[i].inventoryNumber;
		inputFile >> inventoryRecords[i].productDescritption;
		inputFile >> inventoryRecords[i].priceofItem;
		inputFile >> inventoryRecords[i].tax;
	}

	inputFile.close();										// close the inputfile

	// Define the Output file and open it

	ofstream outputFile;
	outputFile.open("Reciept.txt");


	// for loop to populate the reciept.txt file to echo input file.
	for (int i = 0; i < 50; i++) {

		outputFile << setw(6) << left << inventoryRecords[i].inventoryNumber << setw(14)
			<< inventoryRecords[i].productDescritption << setw(5)
			<< setprecision(2) << fixed << showpoint
			<< inventoryRecords[i].priceofItem
			<< setw(2) << inventoryRecords[i].tax << endl << endl;
	}

	//*******************************************
	// do loop for reciept as cashier enters and searches for inventoryNumber
	//*******************************************

	do {

		customerNum++;												// increment customer number

		outputFile << "\nWelcome to Tom's Grocery" << endl;
		outputFile << "===========================" << endl;

		// addition of time and date to reciept
		time_t now = time(0);
		char* datetime = ctime(&now);
		outputFile << endl << datetime << "Customer " << customerNum;

		cout << "\nEnter the item number hit enter, then quantity and hit enter." << endl;
		cin >> inventoryNumber;
		cin >> quantity;

		if (quantity < 0 || quantity > 100) {

			cout << "\nThe Quantity you have chosen is not in range try again." << endl;
			outputFile << "\nThe Quantity you have chosen is not in range.\n" << endl;
			cin >> quantity;
		}

		found = false;
		isTaxed = false;

		// loop through the array to find the inventory number.

		for (int i = 0; i < 50; i++) {
			if (inventoryNumber == inventoryRecords[i].inventoryNumber) {

				found = true;

				itemPrice = inventoryRecords[i].priceofItem;
				quantityPrice = itemPrice * quantity;

				// If the item is taxed, add taxes

				if (inventoryRecords[i].tax == 'T') {
					isTaxed = true;
					subTotal = TAX * quantityPrice;
				}
	
				
				total = quantityPrice;

				// print the information to the reciept

				outputFile << endl;
				outputFile << setw(14) << left << inventoryRecords[i].productDescritption << quantity << " @ " << itemPrice;
			}
		}

			if (found == false) {
				outputFile << endl << "***item  " << inventoryNumber << " is not in inventory ***";
				cout << "Item was not found, try again re enter inventory number and quantity" << endl;
			
				cin >> inventoryNumber;
				cin >> quantity;
			}

			// populate the reciepts.txt with what the customer wants to purchase.

			outputFile << endl;
			outputFile << "\nSubtotal: " << "\t$" <<  quantityPrice << endl
				<< "Tax: " <<"\t\t$" << subTotal << endl
				<< "Total: " <<"\t\t$"<< total  << endl;

			cout << "Continue With another Customer? (Y/N): ";
			cin >> doContinue;

	} while (doContinue == 'Y' || doContinue == 'y');

		
		// Friendly ending message on reciept and close output file.
		outputFile << "\nThank you for shopping at Tom's Grocery, please come back again!" << endl;
		outputFile.close();

		// Friendly ending message.

		cout << "\nThank you for shopping at Tom's Grocery, please come back again!" << endl;

	return 0;
}

