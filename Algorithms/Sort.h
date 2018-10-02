#pragma once
#include <vector>

using namespace std;

class Sort
{
private:
	vector<int> m_array;
	int m_size;

public :
	Sort(int size, int array1[]) 
	{
		m_size = size;
		m_array = vector<int>(array1, array1+size);
	}
	void PrintArray();
	void BubbleSort();
	void BubbleOptimizedSort();
	void SelectionSort();
	void SelectionStableSort();
	void SelectionStableSortGFG();
	void InsertionSort();
	void QuickSort();
	void StableQuickSort();
	void MergeSort();
};
