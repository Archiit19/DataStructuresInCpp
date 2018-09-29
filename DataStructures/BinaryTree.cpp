#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

BinaryTree::BinaryTree()
{
	this->root = NULL;
}

BinaryTree::BinaryTree(TreeNode * rootNode)
{
	root = rootNode;
}

TreeNode* InsertHelper(TreeNode* temp, TreeNode* newNode)
{
	if (temp == NULL)
	{
		temp = newNode;
	}
	else if (temp->left == NULL)
	{
		temp->left = InsertHelper(temp->left, newNode);
	}
	else if (temp->right == NULL)
	{
		temp->right = InsertHelper(temp->right, newNode);
	}
	else
		InsertHelper(temp->left, newNode);
	return temp;
}


void BinaryTree::Insert(int data)
{
	TreeNode *newNode = new TreeNode(data);
	root = InsertHelper(root, newNode);
}

void InOrderHelper(TreeNode* temp)
{
	if (temp)
	{
		InOrderHelper(temp->left);
		cout<< " " << temp->data;
		InOrderHelper(temp->right);
	}
}

void BinaryTree::InOrderTraversal()
{
	cout << "Inorder Traversal is : ";
	InOrderHelper(root);
	cout << endl;
}

void BinaryTree::InOrderTraversalIterative()
{
	cout << "InOrder Iterative Traversal is : ";

	TreeNode * temp = root;
	stack<TreeNode *> s;
	while (1)
	{
		while (temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		if (s.empty())
			break;

		temp = s.top();
		s.pop();
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << endl;
}

void BinaryTree::PreOrderTraversalIterative()
{
	cout << "PreOrder Iterative Traversal is : ";

	TreeNode * temp = root;
	stack<TreeNode*> s;
	while(1)
	{
		while (temp)
		{
			cout << temp->data << " ";
			s.push(temp);
			temp = temp->left;
		}
		if (s.empty())
			break;
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
	cout << endl;
}

void BinaryTree::PostOrderTraversalIterativeDSBook()
{
	cout << "PostOrder Iterative Traversal is : ";
	TreeNode * temp = root;
	TreeNode * previous = NULL;

	stack<TreeNode *> s;
	s.push(temp);
	while (!s.empty())
	{
		TreeNode * current = s.top();
		if (!previous || previous->left == current || previous->right == current)
		{
			if (current->left)
				s.push(current->left);
			else if (current->right)
				s.push(current->right);
			else
			{
				cout << current->data; 
				current = s.top();s.pop();
				previous = current;
				continue;
			}
 		}
		else if (current->left == previous)
		{
			if (current->right)
				s.push(current->right);
		}
		else
		{
			cout << current->data; s.pop();
		}
		previous = current;
	}
	cout << endl;
}

void PostOrderHelper(TreeNode* temp)
{
	if (temp)
	{
		PostOrderHelper(temp->left);
		PostOrderHelper(temp->right);
		cout << " " << temp->data;
	}
}

void BinaryTree::PostOrderTraversal()
{
	cout << "Postorder Traversal is : ";
	PostOrderHelper(root);
	cout << endl;
}

void PreOrderHelper(TreeNode* temp)
{
	if (temp)
	{
		cout << " " << temp->data;
		PreOrderHelper(temp->left);
		PreOrderHelper(temp->right);
	}
}


void BinaryTree::PreOrderTraversal()
{
	cout << "Preorder Traversal is : ";
	PreOrderHelper(root);
	cout << endl;
}


void BinaryTree::LevelOrderTraversal()
{
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode * temp = q.front();
		q.pop();
		cout << " " << temp->data;
		if (temp->left != NULL)
			q.push(temp->left); 
		if (temp->right != NULL)
			q.push(temp->right);

	}
}

void BinaryTree::ReverseLevelOrderTraversal()
{
	queue<TreeNode *> q;
	stack<int> s;
	q.push(root);
	while (!q.empty())
	{
		TreeNode * temp = q.front();
		q.pop();
		s.push(temp->data);
		if (temp->right != NULL)
			q.push(temp->right);
		if (temp->left != NULL)
			q.push(temp->left);
	}
	while (!s.empty())
	{
		cout << "  " << s.top();
		s.pop();
	}
}


