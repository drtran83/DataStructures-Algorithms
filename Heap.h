#pragma once
/*

CISS 350 - Week 7 - Assignment 7 - Priority Queue using Heaps

Heap class declaration file.

----------------------------------------------------
Author : Tom T. Tran
Created : October 13, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
------------------------------
*/

#ifndef HEAPTYPE_H
#define HEAPTYPE_H

#include <iostream>
using namespace std;

template <class H>
void swapDown(H &one, H& two, int& count);

template <class H>
void swapUp(H& one, H& two, int& count);

//*************************************
// Heap type implemented as an array  *
//*************************************

template <class H>

struct HeapType
{
	void ReDown(int root, int bottom);
	void ReUp(int root, int bottom);

	H* elements;

	int enqueueCount;
	int dequeueCount;
};

//***********************************************************************************
// SwapDown swaps the itmes in the heap array during heap down oerpation - dequeues.*
//***********************************************************************************

template <class H>
void swapDown(H& first, H& second, int& count)
{
	H temp;											// temporary object

	// first swap
	count++;										// increment count					
	temp = first;									// set tempt to first

	// second swap

	count++;										// increment swap
	first = second;									// now set first to second

	 // third swap
	count++;										// increment swap
	second = temp;									// then set second to temp
}

//*****************************************************************************
// SwapUp swaps items in the heap array during a heap up operation - enqueues.*
//*****************************************************************************

template <class H>
void swapUp(H& first, H& second, int& count)
{
	H temp;											// temporary object

													// first swap
	count++;										// increment count					
	temp = first;									// set tempt to first

													// second swap

	count++;										// increment swap
	first = second;									// now set first to second

													// third swap
	count++;										// increment swap
	second = temp;									// then set second to temp

}

//***********************************************
// Reheap up to be implemented as a minimum heap*
//***********************************************

template <class H>
void HeapType<H>::ReUp(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{

		parent = (bottom - 1) / 2;

		enqueueCount++;								// to compart against parent and bottom.

			if (elements[parent] > elements[bottom])
			{

				swapUp(elements[parent], elements[bottom], enqueueCount);
				ReUp(root, parent);
			}
	}

}

//***************************************
// ReDown, impelemented as maximum heap *
//***************************************

template <class H>
void HeapType<H>::ReDown(int root, int bottom)
{

	int mChild;									// minimum Child
	int rChild;									// right child
	int lChild;									// left child

	lChild = root * 2 + 1;
	rChild = root * 2 + 2;

	if (lChild <= bottom)
	{
		if (lChild == bottom)
		{
			mChild = lChild;
		}

		else
		{
			dequeueCount++;							// to compare children

			if (elements[lChild] >= elements[rChild])
			{
				mChild = rChild;
			}

			else
			{
				mChild = lChild;
			}
		}

		if (elements[root] > elements[mChild])
		{

			swapDown(elements[root], elements[mChild], dequeueCount);
			ReDown(mChild, bottom);
		}

	}

}

#endif
