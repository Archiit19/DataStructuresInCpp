#pragma once
#include "stdafx.h"
#include "TreeNode.h"


class TreeHelper
{
public:

	void InOrderHelper(TreeNode* temp);
	void PreOrderHelper(TreeNode* temp);
	void PostOrderHelper(TreeNode* temp);
};