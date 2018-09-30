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

// Insertion in a binary tree can be done using Iterative approach as it should follow Level Order Insertion.
void BinaryTree::Insert(int data)
{
	queue<TreeNode *> q;
	TreeNode *newNode = new TreeNode(data);
	if (!root)
		root = newNode;
	else
	{
		TreeNode * temp = root;
		q.push(temp);
		while (!q.empty())
		{
			temp = q.front(); q.pop();
			if (temp->left)
				q.push(temp->left);
			else
			{
				temp->left = newNode;
				break;
			}
			if (temp->right)
				q.push(temp->right);
			else
			{
				temp->right = newNode;
				break;
			}
		}
	}

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
				cout << current->data << " ";
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
			cout << current->data <<" "; s.pop();
		}
		previous = current;
	}
	cout << endl;
}

void BinaryTree::PostOrderTraversalIterativeGFGOneStsack()
{
	cout << "PostOrder (GFG One Stack) Iterative Traversal is : ";
	TreeNode * temp = root;
	TreeNode * previous = NULL;

	if (temp == NULL)
		return;

	stack<TreeNode *> s;
	
	do
	{
		while (temp)
		{
			if (temp->right)
				s.push(temp->right);
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();	s.pop();
		if (temp->right && !s.empty() && temp->right == s.top())
		{
			s.pop();
			s.push(temp);
			temp = temp->right;
		}
		else 
		{
			cout << temp->data << " ";
			temp = NULL;
		}
	} while (!s.empty());
	cout << endl;
}

void BinaryTree::PostOrderTraversalIterativeGFGTwoStsacks()
{
	cout << "PostOrder ( GFG Two stacks) Iterative Traversal is : ";
	stack<TreeNode * > s1;
	stack<TreeNode * > s2;
	if (root == NULL)
		return;

	TreeNode * temp = root;
	s1.push(temp);
	while (!s1.empty())
	{
		temp = s1.top(); s1.pop();
		s2.push(temp);

		if (temp->left)
			s1.push(temp->left);
		if (temp->right)
			s1.push(temp->right);
	}
	while (!s2.empty())
	{
		temp = s2.top(); s2.pop();
		cout << temp->data << " ";
	}
	cout << endl;
}

void BinaryTree::LevelOrderTraversal()
{
	cout << "Level Order Traversal is : ";
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode * temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left != NULL)
			q.push(temp->left); 
		if (temp->right != NULL)
			q.push(temp->right);
	}
	cout << endl;
}

void BinaryTree::ReverseLevelOrderTraversal()
{
	cout << "Reverse Level Order Traversal is : ";
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
	cout << "\n";
}

int BinaryTree::FindMaxElementIterative()
{
	TreeNode * temp = root;
	int max = INT_MIN;

	queue<TreeNode *> q;
	if (!temp)
		return -1;
	q.push(temp);
	while (!q.empty())
	{
		temp = q.front(); q.pop();
		if (max < temp->data)
			max = temp->data;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	cout << "Max Element is : " << max <<endl;
	return max;
}

int FindMaxHelper(TreeNode * temp)
{
	int root_val, left, right, max = INT_MIN;
	if (temp != NULL)
	{
		root_val = temp->data;
		left = FindMaxHelper(temp->left);
		right = FindMaxHelper(temp->right);
		if (left > right)
			max = left;
		else
			max = right;
		if (root_val > max)
			max = root_val;
	}
	return max;
}

int BinaryTree::FindMaxElementRecursive()
{
	int max = FindMaxHelper(root);
	cout << "Max Element using Recursive approach is : " << max << endl;
	return max;
}

int BinaryTree::Size()
{
	cout << "Size of tree is : ";
	int size = 0;
	queue<TreeNode * > q;
	TreeNode * temp = root;
	if (!temp)
	{
		cout << size <<endl;
		return 0;
	}
	q.push(temp);
	while (!q.empty())
	{
		size++;
		temp = q.front();  q.pop();
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	cout << size << endl;
	return size;
}

int SizeRecursionHelper(TreeNode *temp)
{
	if (!temp)
		return 0;
	else
		return SizeRecursionHelper(temp->left) + 1 + SizeRecursionHelper(temp->right);
}

int  BinaryTree::SizeUsingRecursion()
{
	int size = SizeRecursionHelper(root);
	cout << "Tree Size using Recursion is  : " << size << endl;
	return size;
}