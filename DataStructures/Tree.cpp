#include "stdafx.h"
#include "Tree.h"
#include "TreeHelper.h"

using namespace std;

void Tree::InOrderTraversal()
{
	TreeHelper treeHelperObj;
	cout << "Inorder Traversal is : ";
	treeHelperObj.InOrderHelper(root);
	cout << endl;
}

void Tree::PreOrderTraversal()
{
	TreeHelper treeHelperObj;
	cout << "Preorder Traversal is : ";
	treeHelperObj.PreOrderHelper(root);
	cout << endl;
}

void Tree::PostOrderTraversal()
{
	TreeHelper treeHelperObj;
	cout << "Postorder Traversal is : ";
	treeHelperObj.PostOrderHelper(root);
	cout << endl;
}

void Tree::LevelOrderTraversal()
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

void Tree::ReverseLevelOrderTraversal()
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

void Tree::InOrderTraversalIterative()
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

void Tree::PreOrderTraversalIterative()
{
	cout << "PreOrder Iterative Traversal is : ";

	TreeNode * temp = root;
	stack<TreeNode*> s;
	while (1)
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

void Tree::PostOrderTraversalIterativeDSBook()
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
			cout << current->data << " "; s.pop();
		}
		previous = current;
	}
	cout << endl;
}

void Tree::PostOrderTraversalIterativeGFGOneStsack()
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

void Tree::PostOrderTraversalIterativeGFGTwoStsacks()
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




