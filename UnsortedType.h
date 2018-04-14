/*
CISS 350 - Week 4 - Circular Linked List Assignment 4

----------------------------------------------------
Author : Tom T. Tran
Created : September 22, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------

*/

#pragma once
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H



template <class ItemType>
class UnsortedType
{

private:

	template <class ItemType>
	struct NodeType {

		ItemType info;
		struct NodeType *next;
	};


	int length;
	NodeType<ItemType> *currentPos;
	NodeType<ItemType> *listData;
	


public:
	// Class constructor, destructor, and copy constructor
	UnsortedType();
	~UnsortedType();
	UnsortedType(const UnsortedType<ItemType>&);

	
	// Methods

	void DeleteItem(ItemType item);
	int  GetLength() const;
	void GetNextItem(ItemType&);
	void InsertItem(ItemType item);
	bool IsFull() const;
	void ResetList();
	void RetrieveItem(ItemType& item, bool& found);
	

	// = overload operator
	void operator=(UnsortedType<ItemType>);

};




//****************
// Implementation*
//****************

//*************
// Constructor*
//*************

template <class ItemType>
UnsortedType<ItemType>::UnsortedType() {

	length = 0;
	currentPos = nullptr;
	listData = nullptr;
}


//**********
//Destuctor*
//**********

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType() {

	NodeType<ItemType> *tmpPtr;					// temporary pointer
	NodeType<ItemType> *delPtr;					// delete pointer

	tmpPtr = listData;

	for (int i = 0; i <= length - 1; i++) {

		delPtr = tmpPtr;
		delete delPtr;
		tempPtr = tempPtr->next;
	}

	tmpPtr = currentPos;

	for (int i = 0; i <= length - 1; i++) {

		delPtr = tmpPtr;
		delete delPtr;
		tempPtr = tempPtr->next;
	}

	length =  0;
}

//******************
// Copy Constructor*
//******************


template <class ItemType>
UnsortedType<ItemType>::UnsortedType(const UnsortedType<ItemType> &item) {

	*this = item;
}



//***************************************************************
// DeleteItem: Deletes the element whose key matches item's key.*
// Pre:  Key member of item is initialized.						*
//       One and only one element in list has a key matching	*
//       item's key.											*
// Post: No element in list has a key matching item's key.		*
//***************************************************************

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {


	NodeType<ItemType> *tmpPtr;
	NodeType<ItemType> *currPtr;
	NodeType<ItemType> *behindCurrent;
	bool found;

	// let user know list is empty
	if (length == 0)
	{
		cout << "Sorry the ist is empty." << endl;
		return;
	}

	RetrieveItem(item, found);

	// let user know that item hasn't been found

	if (!found)
	{
		cout << "Sorry that item is not in the list." << endl;
		return;
	}

	currPtr = listData;
	behindCurrent = currPtr;

	if (listData == currPtr->next)
	{
		if (currPtr->info == item)
		{
			listData = nullptr;
			delete behindCurrent;
			return;
		}
	}

	for (int i = 0; i <= length - 1; i++)
	{
		if (currPtr->next->info == item)
		{
			tmpPtr = currPtr->next;
			currPtr->next = currPtr->next->next;
			delete tmpPtr;
		}
		else
			currPtr = currPtr->next;
	}

	length--;									// decrement length

}

//********************************************************
// GetLength() Determines the number of elements in list.*		
// Post: Function value = number of elements in list.    *
//********************************************************

template <class ItemType>
int UnsortedType<ItemType>::GetLength() const {

	return length;
}

//********************************************************
// GetNextItem: Gets the next element in list.			 *
// Pre:  Current position is defined.					 *
//       Element at current position is not last in list.*
// Post: Current position is updated to next position.	 *
//       item is a copy of element at current position.	 *
//********************************************************

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item) {

	NodeType<ItemType> *tmpPtr;
	tmpPtr = currentPos;
	item = tmpPtr->next->info;
	currentPos = currentPos->next;
}


//*********************************
//Insert Item:  Adds item to list.*
// Pre:  List is not full.		  *
//       item is not in list.	  *
// Post: item is in list.		  *
//*********************************


template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {


	NodeType<ItemType> *tmpPtr = new NodeType <ItemType>;
	NodeType<ItemType> *currPtr;
	ItemType newItem = item;
	bool found;

	RetrieveItem(newItem, found);						// call retrieve item method

	if (found)
		return;

	currPtr = listData;									// set current pointer to list data
	tmpPtr->info = item;

	if (listData == nullptr)
	{
		listData = tmpPtr;
		tmpPtr->next = listData;
	}
	else
	{
		while (currPtr->next != listData)
		{
			currPtr = currPtr->next;
		}
		currPtr->next = tmpPtr;
		tmpPtr->next = listData;
	}

	currentPos = listData;

	length++;											// increment length

}



//********************************************
// IsFull()  Determines whether list is full.*
// Post: Function value = (list is full)     *
//********************************************

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const {

	NodeType<ItemType> *tmpPtr = new NodeType <ItemType>;

	if (tmpPtr == =nullptr)
		return true;

	else {

		delete tmpPtr;
		return false;
	}

}

//**********************************************************************
// ResetList: Initializes current position for an iteration through the*
// list.															   *
// Post: Current position is prior to list.							   *
//**********************************************************************

template <class ItemType>
void UnsortedType<ItemType>::ResetList() {

	NodeType<ItemType> *tmpPtr;

	tmpPtr = listData;

	if (length <= 1)
		return;

	for (int i = 0; i < length - 1; i++)
	{
		tmpPtr = tmpPtr->next;
		currentPos = tmpPtr;
	}
}

//*********************************************************************
// RetrieveItem:  Retrieves list element whose key matches item's key *
// (if present).													  *	
// Pre:  Key member of item is initialized.							  *
// Post: If there is an element someItem whose key matches            *
//     item's key, then found = true and item is a copy of            *
//     someItem; otherwise found = false and item is                  *
//     unchanged.													  *
//     List is unchanged.											  *
//*********************************************************************

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {


	NodeType<ItemType> *tmpPtr;									// temporary pointer

	tmpPtr = listData;											// assign temp pointer to listData

	for (int i = 1; i <= length; i++)
	{
		if (tmpPtr->info == item)
		{
			found = true;
			return;
		}
		tmpPtr = tmpPtr->next;
	}
	found = false;

}

//***********************
// Overloaded = operator* 
//***********************

template <class ItemType>
void UnsortedType<ItemType>::operator=(UnsortedType<ItemType> item) {

	listData = item.listData;
	length = item.length;
	currentPos = item.currentPos;
}



#endif