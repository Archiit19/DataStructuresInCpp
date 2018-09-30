#include "stdafx.h"
#include "BinarySearchTree.h"

using namespace std;

TreeNode* BinarySearchTree::InsertHelper(TreeNode * temp, int data)
{
	if (temp == NULL)
		temp = new TreeNode(data);
	else
	{
		if (data < temp->data)
			temp->left = InsertHelper(temp->left, data);
		else if(data > temp->data)
			temp->right = InsertHelper(temp->right, data);
	}
	return temp;
} 

void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}

TreeNode* BinarySearchTree::SearchHelper(TreeNode * temp, int key)
{
	if (temp == NULL || temp->data == key)
		return temp;
	else if (temp->data < key)
		return SearchHelper(temp->right, key);
	return SearchHelper(temp->left, key);
}

void BinarySearchTree::Search(int data)
{
	TreeNode * keyNode = SearchHelper(root, data);
	if (keyNode)
		cout << "Key is found in Tree "<<endl;
	else
		cout << "Key is not found in Tree " << endl;
}

TreeNode* BinarySearchTree::DeleteHelper(TreeNode * temp, int data)
{
	TreeNode * foundNode;

	if (temp->data < data)
		temp->right = DeleteHelper(temp->right, data);
	else if (temp->data > data)
		temp->left = DeleteHelper(temp->left, data);
	else
	{
		if (temp->left && temp->right)
		{
			foundNode = FindMaxHelper(temp->left);
			temp->data = foundNode->data;
			temp->left = DeleteHelper(temp->left, temp->data);
		}
		else
		{
			foundNode = temp;
			if (temp->left == NULL)
				temp = temp->right;
			else if (temp->right == NULL)
				temp = temp->left;
			delete(foundNode);
		}
	}
	return temp;
}

void BinarySearchTree::Delete(int data)
{
	if (root == NULL)
	{
		cout << "Element not found in tree" << endl;
		return;
	}
	DeleteHelper(root, data);
}


int BinarySearchTree::FindMaxElementIterative()
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
	cout << "Max Element is : " << max << endl;
	return max;
}

TreeNode * BinarySearchTree::FindMaxHelper(TreeNode * temp)
{
	if (temp == NULL)
		return NULL;
	
	while (temp->right != NULL)
		temp = temp->right;

	return temp;
}

int BinarySearchTree::FindMaxElementRecursive()
{
	TreeNode* maxNode = FindMaxHelper(root);
	cout << "Maximum element in BST using Recursive approach is : " << maxNode->data << endl;
	return maxNode->data;
}

TreeNode * FindMinHelper(TreeNode * temp)
{
	if (temp == NULL)
		return temp;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

int BinarySearchTree::FindMinElementRecursive()
{
	TreeNode * minNode = FindMinHelper(root);
	cout << "Minimum element in BST using Recursive approach is : " << minNode->data << endl;
	return minNode->data;
}

int BinarySearchTree::Size()
{
	cout << "Size of tree is : ";
	int size = 0;
	queue<TreeNode * > q;
	TreeNode * temp = root;
	if (!temp)
	{
		cout << size << endl;
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

int BinarySearchTree::SizeRecursionHelper(TreeNode *temp)
{
	if (!temp)
		return 0;
	else
		return SizeRecursionHelper(temp->left) + 1 + SizeRecursionHelper(temp->right);
}

int BinarySearchTree::SizeUsingRecursion()
{
	int size = SizeRecursionHelper(root);
	cout << "Tree Size using Recursion is  : " << size << endl;
	return size;
}