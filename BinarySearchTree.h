/*

Binary Search Tree Definition file

CISS 350 - Week 6 - Binary Search Tree

This program is uses a binary search tree to store employee information from
employee.txt using the employee class.


----------------------------------------------------
Author : Tom T. Tran
Created : October 5, 2017
Rev : 1
Class : CISS 350 - Professor Randall Hutton
----------------------------------------------------


*/


#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCTREE_H

#include <iostream>
#include "Employee.h"
using namespace std;

//enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class BinarySearchTree {

private:

	struct TreeNode {

		Employee info;						// holds employee info
		TreeNode *left;						// Pointer to tree node's left child
		TreeNode *right;					// Pointer to tree node's right child
	};

	TreeNode *root;							// Pointer to root node

	// Helper function prototypes

	int CountNodes(TreeNode *) const;						// Called by GetLength
	void Retrieve(TreeNode *, Employee &, bool &);			// Called by Retrieve Item
	void Insert(TreeNode *&, Employee);						// Called by Insert Item
	void Delete(TreeNode *&, Employee);						// Called by DeleteItem
	void DeleteNode(TreeNode *&);							// Called by Delete
	void GetPredecessor(TreeNode *, Employee &);				// Called by DeleteNode
	void PrintTree(TreeNode *, ofstream &) const;			// Called by Print
	void Destroy(TreeNode *&);								// Called by Destructor
	void Display(TreeNode *, ofstream &) const;				// called by PrintTree
	void CopyTree(TreeNode *&, const TreeNode *);			// called by copy constructor and overloaded =.



public:

	BinarySearchTree();										// Default Constructor
	~BinarySearchTree();									// Destructor

	// Copy operations

	BinarySearchTree(const BinarySearchTree &);
	void operator = (const BinarySearchTree &);

	// Accessor operations

	bool IsEmpty() const;
	bool IsFull() const;
	int getLength() const;

	// Mutator operations

	void MakeEmpty();
	void RetrieveItem(Employee &, bool &);
	void InsertItem(Employee);
	void DeleteItem(Employee);
	//void ResetTree(OrderType);
	//void GetNextItem(Employee &, OrderType, bool &);
	void Print(ofstream &) const;




};






#endif