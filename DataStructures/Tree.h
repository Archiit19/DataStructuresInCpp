#pragma once
#include "TreeNode.h"

class Tree {

public:
	TreeNode * root;

	Tree(){	root = NULL;	}
	Tree(TreeNode * rootNode){	this->root = rootNode;	}
		
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void LevelOrderTraversal();
	void ReverseLevelOrderTraversal();

	void InOrderTraversalIterative();
	void PreOrderTraversalIterative();
	void PostOrderTraversalIterativeDSBook();
	void PostOrderTraversalIterativeGFGOneStsack();
	void PostOrderTraversalIterativeGFGTwoStsacks();

};