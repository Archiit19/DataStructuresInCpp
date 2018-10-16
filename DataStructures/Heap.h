#pragma once
#include <vector>

enum HeapType
{
		MinHeap = 1,
		MaxHeap = 2,
};

class Heap
{
	std::vector<int> m_heapArray;
	HeapType m_heapType;
	void Swap(int & a, int & b);

	void PercolateUp();
	void PercolateDown();

	int LeftChildIndex(int parentIndex);
	int RighthildIndex(int parentIndex);

	int ParentIndex(int childIndex);

public:
	Heap(HeapType type)
	{
		m_heapType = type;
		m_heapArray.push_back(-1);
	}

	void Insert(int data);
	int Delete();
	void PrintHeap();

};