/*

Definition file for Queue

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

#pragma once
#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <string>

using namespace std;

class FullQueue{};

class EmptyQueue{};

// struct to hold agent information

struct agent {

	string fname;
	string lname;
	int yearsServed;
	int empNumber;

};

struct NodeType;

class ListQueue {

private:

	NodeType* front;					// pointer to front
	NodeType* rear;						// pointer to rear
	int length;							// hold size of the queue

public:

	// Constructor
	ListQueue();

	// Destructor

	~ListQueue();

	// Methods

	void makeEmpty();					// To make the queue empty
	void enqueue(agent);				// Enqueue an agent
	void dequeue(agent&);				// dequeue an agent
	bool isFull()const;					// check to see if queue is full
	bool isEmpty()const;				// check to see if queue is empty
	int getLength()const;				// get length of queue
};



#endif

