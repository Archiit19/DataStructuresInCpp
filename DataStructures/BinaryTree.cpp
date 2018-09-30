#include "stdafx.h"
#include "BinaryTree.h"

using namespace std;

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

int BinaryTree::FindMaxHelper(TreeNode * temp)
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

int BinaryTree::SizeRecursionHelper(TreeNode *temp)
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