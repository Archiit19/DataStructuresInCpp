#pragma once
#include "stdafx.h"
#include "Stack.h"
#include "ListNode.h"

//Stack implementation using Linked list.
template <typename T>
class StackUsingList : public Stack
{
private:
	ListNode<T> *top;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	bool IsEmptyStack();
	void Push(T data);
	T Pop();
	void PrintStack();
	void DeleteStack();
	T Top();
};