#pragma once
#include "Tree.h"


class BinarySearchTree : public Tree
{
public:
	BinarySearchTree() : Tree() {};
	BinarySearchTree(TreeNode * rootNode) : Tree(rootNode) {};

	TreeNode * InsertHelper(TreeNode * temp, int data);
	void Insert(int data);

	TreeNode * SearchHelper(TreeNode * temp, int key);
	void Search(int data);

	TreeNode * DeleteHelper(TreeNode * temp, int data);
	void Delete(int data);

	int FindMaxElementIterative();
	TreeNode * FindMaxHelper(TreeNode * temp);
	int FindMaxElementRecursive();


	int FindMinElementRecursive();

	int Size();
	int SizeRecursionHelper(TreeNode *temp);
	int SizeUsingRecursion();
};