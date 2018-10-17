#include "stdafx.h"
#include "Heap.h"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void Heap::Swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heap::PercolateUp()
{
	if (m_heapType == MaxHeap)
	{
		size_t i = m_heapArray.size()-1;
		while (i > 1 && m_heapArray[i] > m_heapArray[ParentIndex(i)])
		{
			Swap(m_heapArray[i], m_heapArray[ParentIndex(i)]);
			i = i / 2;
		}
	}
	else
	{
		size_t i = m_heapArray.size() - 1;
		
		while (i > 1 && m_heapArray[i] < m_heapArray[ParentIndex(i)])
		{
			Swap(m_heapArray[i], m_heapArray[ParentIndex(i)]);
			i = i / 2;
		}
	}
}

void Heap::PercolateDown()
{
	if (m_heapType == MaxHeap)
	{
		unsigned int i = 1;
		while ( 2*i < m_heapArray.size())
		{
			if (m_heapArray[LeftChildIndex(i)] > m_heapArray[RighthildIndex(i)])
			{
				if (m_heapArray[i] < m_heapArray[LeftChildIndex(i)])
				{
					Swap(m_heapArray[i], m_heapArray[LeftChildIndex(i)]);
					i = 2 * i;
				}
			}
			else if (m_heapArray[LeftChildIndex(i)] < m_heapArray[RighthildIndex(i)])
			{
				if (m_heapArray[i] < m_heapArray[RighthildIndex(i)])
				{
					Swap(m_heapArray[i], m_heapArray[RighthildIndex(i)]);
					i = 2 * i + 1;
				}
			}
		}
	}
	else
	{
		unsigned int i = 1;
		while ( 2*i < m_heapArray.size())
		{
			if (m_heapArray[LeftChildIndex(i)] < m_heapArray[RighthildIndex(i)])
			{
				if (m_heapArray[i] > m_heapArray[LeftChildIndex(i)])
				{
					Swap(m_heapArray[i], m_heapArray[LeftChildIndex(i)]);
					i = 2 * i;
				}
			}
			else if (m_heapArray[LeftChildIndex(i)] > m_heapArray[RighthildIndex(i)])
			{
				if (m_heapArray[i] > m_heapArray[RighthildIndex(i)])
				{
					Swap(m_heapArray[i], m_heapArray[RighthildIndex(i)]);
					i = 2*i + 1;
				}
			}
		}
	}
}

int Heap::LeftChildIndex(int parentIndex)
{
	return parentIndex * 2;
}

int Heap::RighthildIndex(int parentIndex)
{
	return parentIndex * 2 + 1;
}

int Heap::ParentIndex(int childIndex)
{
	return childIndex / 2;
}

void Heap::Insert(int data)
{
	m_heapArray.push_back(data);
	PercolateUp();
}

int Heap::Delete()
{
	if (m_heapArray.size() > 2)
	{
		Swap(m_heapArray[1], m_heapArray[m_heapArray.size() - 1]);
		int temp = m_heapArray.back();
		m_heapArray.pop_back();
		PercolateDown();
		return temp;
	}
	else if (m_heapArray.size() == 2)
	{
		int temp = m_heapArray.back();
		m_heapArray.pop_back();
		return temp;
	}
	else
		cout << "Heap is Empty!!";
	return -1;
}

void Heap::PrintHeap()
{
	vector<int> ::iterator it;
	for (it = m_heapArray.begin()+1 ; it!=m_heapArray.end(); it++)
		cout << *it << " ";
	cout << endl;
}
