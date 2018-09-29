#pragma once
#include "ListNode.h"

//Stacks parent Class - All Stack implementations will be derived from this file.
class Stack {

protected:
	int size;

public:
	Stack() : size(0) {};
	
	inline bool IsEmptyStack()
	{
		if (size == 0)
			return true;
		return false;
	}
	virtual void PrintStack() = 0;
	virtual void DeleteStack() = 0;
	inline int Size()
	{
		return size;
	}

};