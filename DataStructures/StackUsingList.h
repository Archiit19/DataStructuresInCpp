#pragma once
#include "stdafx.h"
#include "Stack.h"
#include "ListNode.h"

//Stack implementation using Linked list.
class StackUsingList : public Stack
{
private:
	ListNode *top;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	bool IsEmptyStack();
	void Push(int data);
	int Pop();
	void PrintStack();
	void DeleteStack();
};