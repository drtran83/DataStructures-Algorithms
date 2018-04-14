/*

CISS 350 - Advanced Algorithms and Data Structures

Week 5 - Recursion

Programming Assignment 5
A toy that many children play with is a base with three pegs and five disks of different diameters. 
The disks begin on one peg, with the largest disk on the bottom and the other four disks added on in order of size. 
The idea is to move the disks from the peg they are on, to another peg by moving only one disk at a time and without ever putting a larger disk on top of a smaller one. 
This child's toy is actually an example of a classic mathematical puzzle called the Towers of Hanoi problem.

Write a recursive solution to this problem. It may take you a while to see the solution, but the program itself is quite short.

Input
The program should prompt for and input the number of Rings. For this program please use 3 pegs and 5 rings.
Output
The series of moves should be written to the screen, properly labeled.

Deliverables
•	A listing your program
•	A copy of your screen output
----------------------------------------------------
Author : Tom T. Tran
Created : September 29, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------

*/

#include <iostream>
using namespace std;

// Function prototype

void moveDisks(int, int, int, int);								// Recursive function

int main() {

	cout << "CISS 350 - Week 5 - Assignment 5 - Towers of Hanoi - Tom Tran" << endl;
	cout << "==============================================================\n" << endl;

	// variables

	int numDisks = 0;

	cout << "This is the Towers of Hanoi Game using Recursion\n" << endl;


	// get number of disks from user
	cout << "Enter in the number of disks to move: ";
	cin >> numDisks;

	cout << endl;

	// output
	moveDisks(numDisks, 1, 3, 2);


	return 0;


}

// Recursive Function

void moveDisks(int count, int tower1, int tower2, int tower3) {

	if (count > 0)
	{

		moveDisks(count - 1, tower1, tower2, tower3);
		cout << "Moving disk " << count << " from Tower " << tower1 << " to Tower " << tower3 << "." << endl << endl;
		moveDisks(count - 1, tower2, tower3, tower1);
	}

}