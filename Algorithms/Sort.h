#pragma once
#include <vector>

using namespace std;

class Sort
{
private:
	vector<int> m_array;
	int m_size;

	int Partition(int * a, int low, int high);
	void QuickSortHelper(int * a, int low, int high);

	void Merge(int * a, int low, int mid, int high);
	void MergeSortHelper(int * a, int low, int high);

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
	void MergeSort();
	
	void StableQuickSort();
	void MergeSortIterative();

};

