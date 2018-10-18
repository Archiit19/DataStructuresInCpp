#pragma once
#include "Heap.h"
#include <vector>

enum PriorityType
{
	ChhotaElementBadiPriority = 1,
	BadaElementBadiPriority = 2,
};

class PQueue
{
	PriorityType m_PriorityType;
	Heap * m_ptr_MyHeap;

public:
	PQueue(PriorityType type)
	{
		if (type == ChhotaElementBadiPriority)
		{
			m_PriorityType = type;
			m_ptr_MyHeap = new Heap(MinHeap);
		}
		else
		{
			m_PriorityType = type;
			m_ptr_MyHeap = new Heap(MaxHeap);
		}
	}

	void Insert(int data);
	int Delete();
	void PrintPQueue();

};