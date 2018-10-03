#pragma once

#include "stdafx.h"
#include "Sort.h"
#include <iostream>

using namespace std;


void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort::PrintArray()
{
	cout << "Sorted Array is :";
	for (int i = 0; i < m_size; i++)
	{
		cout << " " << m_array[i];
	}
	cout << endl;
}


void Sort::BubbleSort()
{
	for (int i = 0; i < m_size-1; i++)
	{
		for (int j = 0; j < m_size-i-1; j++)
		{
			if (m_array[j] > m_array[j + 1])
				Swap(m_array[j], m_array[j + 1]);
		}
	}
}

void Sort::BubbleOptimizedSort()
{
	int swapped = 1;
	for (int i = 0; (i < m_size - 1) && swapped; i++)
	{
		swapped = 0;
		for (int j = 0; (j < m_size -1) ; j++)
		{ 
			if (m_array[j] > m_array[j + 1])
			{
				Swap(m_array[j], m_array[j + 1]);
				swapped = 1;
			}
		}
	}
}

void Sort::SelectionSort()
{
	int min = 0;
	for (int i = 0; i < m_size-1; i++)
	{
		min = i;
		for (int j = i+1; j < m_size-1; j++)
		{
			if (m_array[j] < m_array[min])
				min = j;
		}
		Swap(m_array[min], m_array[i]);
	}
}

void Sort::SelectionStableSort()
{
	int min = 0;
	for (int i = 0; i < m_size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < m_size - 1; j++)
		{
			if (m_array[j] < m_array[min])
				min = j;
		}
		int j = i + 1;
		int k = j + 1;

		while (k<min)
		{
			if (m_array[k] >= m_array[j])
			{
				Swap(m_array[k], m_array[j]);
				j++;
			}
			k++;
		}
		Swap(m_array[min], m_array[i]);
	}
}

void Sort::SelectionStableSortGFG()
{
	int min = 0;
	for (int i = 0; i < m_size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < m_size - 1; j++)
			if (m_array[j] < m_array[min])
				min = j;
		
		int temp = m_array[min];
		while (i<min)
		{
			m_array[min] = m_array[min - 1];
			min--;
		}
		m_array[min] = temp;
		
	}
}


void Sort::InsertionSort()
{
	for (int i = 1; i < m_size; i++)
		for (int j = i; j > 0; j--)
			if (m_array[j-1] > m_array[j])
				Swap(m_array[j-1], m_array[j]);
}

int Sort::Partition(int * a, int low, int high)
{
	int pivot = a[low];
	int i=low, j= high;
	while (i < j)
	{
		while (a[i] <= pivot)
			i++;
		while (pivot < a[j])
			j--;
		if (i < j)
			Swap(a[i], a[j]);
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}

void Sort::QuickSortHelper(int* a,int low, int high)
{
	int pi;
	if (low < high)
	{
		pi = Partition(a, low, high);
		QuickSortHelper(a, low, pi - 1);
		QuickSortHelper(a, pi+1, high);
	}
}

void Sort::QuickSort()
{
	QuickSortHelper(&m_array[0], 0, m_size - 1);
}



void Sort::Merge(int *a, int low, int mid, int high)
{
	int i, j, k;
	int n1 = low + mid - 1;
	int n2 = high - mid;

	int * T1 = new int[n1];
	int * T2 = new int[n2];

	for (int i = 0; i < n1; i++)
		T1[i] = a[low+i];
	for (int i = 0; i < n2; i++)
		T2[i] = a[mid+1+i];
	
	i = 0; j = 0; k = 0;

	while (i < n1 && j < n2)
	{
		if (T1[i] <= T2[j])
		{
			a[k] = a[i];
			i++;
		}
		else 
		{
			a[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = T1[n1];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = T2[j];
		j++;
		k++;
	}
}

void Sort::MergeSortHelper(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSortHelper(a, low, mid);
		MergeSortHelper(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}

void Sort::MergeSort()
{
	MergeSortHelper(&m_array[0], 0, m_size - 1);
}

void Sort::StableQuickSort()
{
}

void Sort::MergeSortIterative()
{
}
