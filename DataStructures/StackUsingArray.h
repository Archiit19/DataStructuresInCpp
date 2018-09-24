#pragma once
#include "stdafx.h"
#include "Stack.h"
#include <vector>

//Stack implementation using Vector.
class StackUsingArray : public Stack
{
private:
	std::vector<int> stack_a;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	bool IsEmptyStack();
	void Push(int data);
	int Pop();
	void PrintStack();
	void DeleteStack();
};