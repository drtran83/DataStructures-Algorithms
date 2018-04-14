/*

BinarySearchTree implementation file

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


#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
using namespace std;

//*************
// Constructor*
//*************

BinarySearchTree::BinarySearchTree() 
{
	
	root = NULL;				// set root to null
}

//*************
// Destructor**
//*************

BinarySearchTree::~BinarySearchTree()
{

	Destroy(root);				// Calls destroy passing root of binary search tree
}

//*******************************************
// MakeEmpty removes all nodes from the tree*
//*******************************************


void BinarySearchTree::MakeEmpty()
{

	Destroy(root);				// calls destroy passing root of binary search tree

	root = NULL;				// set root to NULL
}

//***************************************************************
// Copy Constructor calls CopyTree to copy a binary search tree**
//***************************************************************

BinarySearchTree::BinarySearchTree(const BinarySearchTree &originalTree)
{

	CopyTree(root, originalTree.root);			// Call to CopyTree passing root and originalTree.root
}

//*********************************************************************
// Overloaded = operator, calls CopyTree to copy a binary search tree**
//*********************************************************************

void BinarySearchTree::operator=(const BinarySearchTree &originalTree) 
{

	if (&originalTree == this)					// Ignore assigning tree to itself
		return;

	Destroy(root);								// Deallocate any existing tree nodes.

	CopyTree(root, originalTree.root);			// Call to copyTree passing root and originalTree.root
	
}

//******************************************
// IsEmpty determines if the tree is empty**
//******************************************

bool BinarySearchTree::IsEmpty() const 
{

	return root == NULL;							// if root node is NULL, equation returns true
}

//*****************************************
// IsFull determines if the tree is full***
//*****************************************

bool BinarySearchTree::IsFull() const 
{

	TreeNode *nodePtr;								// TreeNode pointer

	// Try to allocate a new Treenode.  exception is thrown if memory does not exist for new node

	try
	{

	nodePtr = new TreeNode;						// exception thrown based on this statement
	delete nodePtr;								// will not execute if exception is thrown.
	return false;								// will not execute if exception is thrown.

	}

	catch(bad_alloc exception)
	{
		return true;							// executes if exception is caught

	}

}

//***************************************************************************************************
// getLength determines the number of elements in the tree and calls the countNodes helper function**
//***************************************************************************************************

int BinarySearchTree::getLength() const
{

	return CountNodes(root);					// Call to countNodes passing the root pointer
}

//*************************************************************************************************
// Retrieve Item retreives item whose key matches item's key.  Calls the Retrieve helper function**
//*************************************************************************************************

void BinarySearchTree::RetrieveItem(Employee &item, bool &found) 
{

	Retrieve(root, item, found);
}

//**********************************************************************
// InsertItem, adds an item to the tree.  Calls insert helper function**
//**********************************************************************

void BinarySearchTree::InsertItem(Employee item) 
{

	Insert(root, item);							// Call to insert passing root and item
}

//*********************************************
// Delete item removes an item from the tree.**
//*********************************************

void BinarySearchTree::DeleteItem(Employee item) 
{

	Delete(root, item);							// Call to delete item from tree
}

//******************************************************
// Print prints items in tree using inOrder traversal***
//******************************************************

void BinarySearchTree::Print(ofstream &outFile) const
{


	PrintTree(root, outFile);					// Call to printTree helper function
}

//******************
// Helper Functions*
//******************

//*****************************************************************************
// Helper Function: CountNodes counts the number of nodes in a tree			  *
// Base Case: if tree is null return 0.									      *
// General Case: Return CountNodes (left(tree)) + CountNodes(right(tree)) + 1 *
//*****************************************************************************

int BinarySearchTree::CountNodes(TreeNode *tree) const 
{

	if (tree == NULL)
		return 0;									// return 0 if no nodes exist.

	else {

		return ((CountNodes(tree->left) + CountNodes(tree->right)) + 1);					// recursive call

	}
}

//********************************************************************************************
// Helper Function: Retrieve, searches for an element with the same key as item's key        *
//					if found, store it into item.											 *
// Base Case: (1) If item's key matches key in info(tree), item is set to info(tree)		 *
//					and found is set to true.												 *
//			  (2)  If tree = NULL, found is set to false.								     *
//																							 *
// General Case:  If the item's key is less than key in info(tree), call Retrieve(left(tree) *
//				item, found); else call Retreive (right(tree), item, found).				 *
//********************************************************************************************

void BinarySearchTree::Retrieve(TreeNode *tree, Employee &item, bool &found)
{

	if (tree == NULL)
		found = false;

	else if (item.getEmployeeNumber() < tree->info.getEmployeeNumber())
		Retrieve(tree->left, item, found);
	else if (item.getEmployeeNumber() > tree->info.getEmployeeNumber())
		Retrieve(tree->right, item, found);

	else {

		item = tree->info;
		found = true;
	}
}

//**********************************************************************************
// Helper Function: Insert, inserts item into a binary search tree using recursion.*
// Base Case:  If tree is NULL, then allocate a new leafe to contain item.		   *
// General Case: (1) if item < info (tree), then insert(left(tree), item).		   *
//				 (2) if item > info (tree), then insert(right(tree), item).		   *
//**********************************************************************************

void BinarySearchTree::Insert(TreeNode *&tree, Employee item) 
{


		// base case

	if (tree == NULL)
	{
		tree = new TreeNode;							// declare a new tree node

		// set child pointers of new treenode to null
		tree->left = NULL;
		tree->right = NULL;

		tree->info = item;								// copy item to node.

	}

	else if (item.getEmployeeNumber() < tree->info.getEmployeeNumber())
	{
		Insert(tree->left, item);						// Recursive call passing TreeNode's left pointer and item
	}

	else 
	{
		Insert(tree->right, item);						// Recursive call passing Treenode's right pionter and item.

	}

}

//***************************************************************************************
// Helper Function: Delete removes an element from a tree whose key matches item's key	*
//																						*
// Base Case: if item's key matches key in info(tree), delete node pointed to by tree.	*
// General Case: If item < info(tree), delete(left(tree), item)							*
//				else delete(right(tree), item).											*
//***************************************************************************************


void BinarySearchTree::Delete(TreeNode *&tree, Employee item) 
{
	
	// using recursion to search for th eitem

	if (item.getEmployeeNumber() < tree->info.getEmployeeNumber())
		Delete(tree->left, item);

	else if (item.getEmployeeNumber() > tree->info.getEmployeeNumber())
		Delete(tree->right, item);

	else
	{
		// base case - call deleteNode helper function.

		DeleteNode(tree);
	}
}


//****************************************************************
// Helper Function: DeleteNode, deletes node pointed to by tree. *
//****************************************************************

void BinarySearchTree::DeleteNode(TreeNode *& tree) 
{

	// create a temp person
	Employee data;

	// create temp pointer
	TreeNode *tempPtr;

	// set tempPtr to tree
	tempPtr = tree;

	// Check to see if any of the node's children point to NULL

	if (tree->left == NULL) 
	{
		tree = tree->right;
		delete tempPtr;
	}

	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}

	else
	{
		// get the predecessor node.

		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

//**********************************************************************************************
// Helper Function: GetPredecessor, sets data to the info member of the rightmost node in tree.*
//**********************************************************************************************

void BinarySearchTree::GetPredecessor(TreeNode *tree, Employee &item) 
{

	// While pointer isn't NULL, set tree pointer to right (tree)

	while (tree->right != NULL)
		tree = tree->right;

	// Copy info(tree) to data

	item = tree->info;

}

//*****************************************************************************************
// Helper Function:  PrintTree, prints the items in the binary earch tree in order from	  *
//					 smallest to largest.												  *
// Base Case:  If tree = NULL do nothing												  *
// General Case: Traverse the left subtree in order.  The print info(tree)				  *
//*****************************************************************************************

void BinarySearchTree::PrintTree(TreeNode *tree, ofstream &outFile) const
{
	// As long as tree contains elements

	if (tree != NULL)
	{
		// Print the left subtree.
		PrintTree(tree->left, outFile);

		// Print current node.
		Display(tree, outFile);

		// Print the right subtree
		PrintTree(tree->right, outFile);

	}
}

//*************************************************************
// Helper Function: Destroy, removes all nodes from the tree. *
// Base Case: tree= NULL									  *
// General Case: tree !=NULL								  *
//*************************************************************

void BinarySearchTree::Destroy(TreeNode *& tree)
{

	if (tree != NULL)
	{

		// Recursive call to destroy subtrees
		Destroy(tree->right);
		Destroy(tree->left);
		delete tree;

	}

}

//****************************************************************************************
// Helper Function: CopyTree, creates a new node and copies data from original tree to   *
//					new node.  Copies all nodes using recursive calls.					 *
// Base Case: originalTree = NULL.														 *
// General Case: Left subtree is copied then right subtree.								 *
//****************************************************************************************

void BinarySearchTree::CopyTree(TreeNode *& copy, const TreeNode *originalTree)
{
	// base case

	if (originalTree == NULL)
	{
		// Set copy to NULL
		copy = NULL;
	}

	else
	{
		// General case

		copy = new TreeNode;							// set copy to a new node
		copy->info = originalTree->info;				// copy data to new node
		CopyTree(copy->left, originalTree->left);		// Recursive call for left subtree
		CopyTree(copy->right, originalTree->right);		// Recursive call for right subtree

	}

}

//***************************************************
// Helper Function:  Display, displays info in node *
//***************************************************

void BinarySearchTree::Display(TreeNode *tree, ofstream &outFile) const
{
	outFile << "\n Employee iD: " << tree->info.getEmployeeNumber() << endl;
	outFile << "Agent's Last Name" << tree->info.getlName() << endl;
	outFile << "Agent's First Name" << tree->info.getfName() << endl;
	outFile << "Year's Served" << tree->info.getYears() << endl;

}


