/*

CISS 350 - Week 7 - Assignment 7 - Priority Queue using Heaps

PQ heap class declaration file.

----------------------------------------------------
Author : Tom T. Tran
Created : October 13, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
------------------------------
*/

#pragma once

#ifndef PQHEAP_H
#define PQHEAP_H
#include <iostream>
#include "Heap.h"
using namespace std;

// Class forward delcaration

class FullPQ{};
class EmptyPQ{};

template <class PQ>
class PQHeap
{

private:

	int length;
	HeapType<PQ> items;
	int maxItems;


public:

	// Constructor

	PQHeap(int);

	// Destructor
	~PQHeap();

	// Methods

	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(PQ newItem);
	void dequeue(PQ& item);
	int getHeapLength() const;
	int getEnqueueOpCount() const;
	int getDequeueOpCount() const;
	int getTotalOpCount() const;
	void resetOpCounts();

};

//**********************
// PQ heap constructor *
//**********************

template <class PQ>
PQHeap<PQ>::PQHeap(int max)
{

	maxItems = max;
	items.elements = new PQ[max];
	length = 0;

	items.enqueueCount = 0;
	items.dequeueCount = 0;

}

//**********************
// PQ heap Destructor  *
//**********************

template <class PQ>
PQHeap<PQ>::~PQHeap()
{

	delete[] items.elements;

}


//**************************************************
// Dequeue removes the head object from this queue *
//**************************************************

template <class PQ>
void PQHeap<PQ>::dequeue(PQ& item) 
{

	if (length == 0)
	{
		throw EmptyPQ();

	}

	else
	{
		item = items.elements[0];
		items.elements[0] = items.elements[length - 1];
		length--;
		items.ReDown(0, length - 1);
	}

}

//*****************************************
// Enqueue adds an object onto the queue. *
//*****************************************

template <class PQ>
void PQHeap<PQ>::enqueue(PQ newItem)
{

	if (length == maxItems)
	{
		throw FullPQ();
	}

	else
	{
		length++;
		items.elements[length - 1] = newItem;
		items.ReUp(0, length - 1);

	}

}


//*******************************************************
// getDequeueOpCount:  gets the dequeue operation count *
//*******************************************************

template <class PQ>
int PQHeap<PQ>::getDequeueOpCount() const
{
	return items.dequeueCount;
}

//******************************************************
// getEnqueueOpCount: gets the enqueue operation count *
//******************************************************

template <class PQ>
int PQHeap<PQ>::getEnqueueOpCount() const
{
	return items.enqueueCount;
}

//*****************************************************************
// getHeapLength: gets the length of the heap - count of elements *
//*****************************************************************

template <class PQ>
int PQHeap<PQ>::getHeapLength() const
{
	return length;
}

//**********************************************************************
// getTotalOpCount: gets the operation counts for enqueue and dequeues *
//**********************************************************************

template <class PQ>
int PQHeap<PQ>::getTotalOpCount() const
{

	return (items.enqueueCount + items.dequeueCount);
}

//********************************************
// isFull will querey if the object is full. *
//********************************************

template <class PQ>
bool PQHeap<PQ>::isFull() const
{

	return length == maxItems;
}

//**********************************************
// isEmpty will querey if the object is empty. *
//**********************************************

template <class PQ>
bool PQHeap<PQ>::isEmpty() const
{
	return length == 0;
}


//*********************************
// MakeEmpty makes the heap empty *
//*********************************

template <class PQ>
void PQHeap<PQ>::makeEmpty()
{
	length 0;
}

//***********************************************************************
// ResetOpCount:  resets the operation counts for enqueues an dequeues. *
//***********************************************************************

template <class PQ>
void PQHeap<PQ>::resetOpCounts()
{
	items.dequeueCount = 0;
	items.enqueueCount = 0;
}



#endif

