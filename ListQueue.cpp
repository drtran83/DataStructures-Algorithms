/*
Implementation file for Queue

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

#include "ListQueue.h"
#include <iostream>
#include <cstddef>
#include <new>

using namespace std;

struct NodeType {

	agent info;					// agent object
	NodeType* next;					// next pointer

};

// default constructor

ListQueue::ListQueue() {

	front = NULL;
	rear = NULL;
	length = 0;
}

// Destructor

ListQueue::~ListQueue() {

	makeEmpty();

}

// Make Empty method


void ListQueue::makeEmpty() {

	NodeType *tempPtr;

	while (front != NULL) {

		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}

	rear = NULL;

}



bool ListQueue::isFull() const {
	NodeType *loc;

	try {
		loc = new NodeType;
		delete loc;
		return false;
	}

	catch (std::bad_alloc exception) {
		return true;
	}
}

// returns bool if the queue is empty, returns true

bool ListQueue::isEmpty() const {

	return (front == NULL);
}

// enqueue accepts an agent variable and adds it to the queue
void ListQueue::enqueue(agent newItem)
{

	if (isFull())
		throw FullQueue();

	else
	{
		NodeType *newNode;
		newNode = new NodeType;
		newNode->info = newItem;
		newNode->next = NULL;

		if (rear == NULL) {
			front = newNode;
		}

		else {
			rear->next = newNode;
		}

		rear = newNode;

		length++;			// increment length
	}
}

void ListQueue::dequeue(agent& item) {

	if (isEmpty())
		cout << "The Queue is Empty" << endl;

	else {

		NodeType *tempPtr;

		tempPtr = front;
		item = front->info;
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		delete tempPtr;
		length--;					// decrement length;
	}
}

int ListQueue::getLength() const {
	return length;
}