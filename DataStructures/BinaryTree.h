#pragma once
#include "stdafx.h"
#include "TreeNode.h"

class BinaryTree
{
public:
	TreeNode * root;

	BinaryTree(); 
	BinaryTree(TreeNode * rootNode);

	void Insert(int data);
	

	void InOrderTraversalIterative();
	void PreOrderTraversalIterative();
	void PostOrderTraversalIterativeDSBook();
	void PostOrderTraversalIterativeGFGOneStsack();
	void PostOrderTraversalIterativeGFGTwoStsacks();

	void InOrderTraversal();
	void PostOrderTraversal();
	void PreOrderTraversal();

	void LevelOrderTraversal();
	void ReverseLevelOrderTraversal();

	int FindMaxElementIterative();
	int FindMaxElementRecursive();

	int Size();
	int SizeUsingRecursion();
};