// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of Elements in array : ";
	cin >> n;
	vector<int> array;
	int temp;
	cout << "\nEnter the Array elements : ";
	for (int i =0; i < n; i++)
	{
		cin >> temp;
		array.push_back(temp);
	}
	Sort s1(n, array);
	s1.BubbleSort();
	s1.PrintArray();

	Sort s2(n, array);
	s2.BubbleOptimizedSort();
	s2.PrintArray();

	Sort s3(n, array);
	s3.SelectionSort();
	s3.PrintArray();

	Sort s4(n, array);
	s4.SelectionStableSort();
	s4.PrintArray();

	Sort s5(n, array);
	s5.SelectionStableSortGFG();
	s5.PrintArray();

	vector<int> array6 = { 4, 3, 2, 10 ,12 ,1, 5, 6 };
	int n6 = 8;
	Sort s6(n6, array6);
	s6.InsertionSort();
	s6.PrintArray();

    return 0;
}

