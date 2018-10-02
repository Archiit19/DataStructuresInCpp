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

void Sort::QuickSort()
{
}

void Sort::StableQuickSort()
{
}

void Sort::MergeSort()
{
}

