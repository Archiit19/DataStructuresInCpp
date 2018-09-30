#include "stdafx.h"
#include "TreeHelper.h"

using namespace std;

void TreeHelper::InOrderHelper(TreeNode * temp)
{
	if (temp)
	{
		InOrderHelper(temp->left);
		cout << " " << temp->data;
		InOrderHelper(temp->right);
	}
}

void TreeHelper::PreOrderHelper(TreeNode* temp)
{
	if (temp)
	{
		cout << " " << temp->data;
		PreOrderHelper(temp->left);
		PreOrderHelper(temp->right);
	}
}

void TreeHelper::PostOrderHelper(TreeNode * temp)
{
	if (temp)
	{
		PostOrderHelper(temp->left);
		PostOrderHelper(temp->right);
		cout << " " << temp->data;
	}
}


