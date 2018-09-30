#pragma once
#include "Tree.h"

class BinaryTree : public Tree
{
public:
	BinaryTree() : Tree() {};
	BinaryTree(TreeNode * rootNode) : Tree(rootNode) {};

	void Insert(int data);
	
	int FindMaxElementIterative();
	int FindMaxHelper(TreeNode * temp);
	int FindMaxElementRecursive();

	int Size();
	int SizeRecursionHelper(TreeNode * temp);
	int SizeUsingRecursion();
};