#pragma once
#include <vector>

using namespace std;

class Sort
{
private:
	vector<int> m_array;
	int m_size;

public :
	Sort(int size, vector<int> array) 
	{
		m_size = size;
		m_array = array;
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
