/*



 Your assignment is to write and compare two implementations of a priority queue whose highest priority element is the one with the smallest key value. 
 The elements have the following declarations:
 1.	The first implementation uses a minimum heap. You need to modify the heap operations to keep the minimum, 
 rather than the maximum element in the root. The comparison function should compare key fields.

 2.	The second implementation uses a linear linked list, whose elements are ordered by key value.

 ----------------------------------------------------
 Author : Tom T. Tran
 Created : October 13, 2017
 Rev : 1
 Class : CISS 350 - Professor Randall Hutton
 ------------------------------


*/

#include <iostream>
#include "Heap.h"
#include "PQHeap.h"
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

int main() {

	cout << "CISS 350 - Week 7 - Priority Queue with Heaps - Tom Tran" << endl;
	cout << "=========================================================\n" << endl;

	// variables

	const int length = 50;															// 50 variables

	// 50 random values

	int values[] = { 1, 10, 30, 40, 33, 22, 55, 66, 99, 100,
					88, 34, 77, 60, 50, 42, 14, 16, 29, 80,
					98, 6, 3, 2, 7, 45, 59, 61, 28, 31, 83,
					91, 93, 97, 82, 84, 64, 75, 78, 71, 58,
					23, 24, 37, 9, 8, 5, 44, 49, 63, 89, 11 };		

	PQHeap<int> pqh(50);

	// now load each PQ with the random values

	for (int index = 0; index < length; index++)
	{
		pqh.enqueue(values[index]);

	}

	cout << "Here is the original order of the 50 values...\n" << endl;
	for (int index = 0; index < length; index++) 
	{
		cout << values[index] << " ";
	}

	cout << "\n\nThe Queue Length is: " << pqh.getHeapLength() << endl;


	// check order of heap queue

	int tempValue = -99;										// To hold dequeued int item
	int queueLength = pqh.getHeapLength();

	cout << "\n\nDeQueueing all PQ heap items to the Check Order:" << endl;

	for (int index = 0; index < queueLength; index++)
	{
		try
		{
			pqh.dequeue(tempValue);
			cout << tempValue << " ";
		}
		catch (EmptyPQ)
		{
			cout << "\n\nEmpty Queue Error!" << endl;
			break;
		}
	}

	cout << "\n\nPQ Heap DeQueued Length: " << pqh.getHeapLength() << endl;
	cout << endl;

	cout << "PQHeap EnQueue Operation Count: " << pqh.getEnqueueOpCount() << endl;
	cout << "PQHeap DeQueue Operation Count: " << pqh.getDequeueOpCount() << endl;
	cout << "PQHeap Total Operation Count: " << pqh.getTotalOpCount() << endl;
	cout << "PQ List DeQueued Length: " << pqh.getHeapLength() << endl;

	cout << "\nDone....." << endl;


	return 0;

}