#include "stdafx.h"
#include "DisjointSet.h"
#include <vector>

using namespace std;

void DisjointSetQuickFind::Union(int a, int b)
{
	int temp = m_arr[a];
	for (int i = 0; i < m_arr.size(); i++)
	{
		if (m_arr[i] == temp)
			m_arr[i] = m_arr[b];
	}
}

bool DisjointSetQuickFind::Find(int a, int b)
{
	return (m_arr[a] == m_arr[b]);
}

void DisjointSetQuickUnionSlowFind::Union(int a, int b)
{
	if (Find(a, b))
		return;
	int i = Root(a);
	int j = Root(b);
	m_arr[i] = j;
}

int DisjointSetQuickUnionSlowFind::Root(int a)
{
	while (m_arr[a] != a)
		a = m_arr[a];
	return a;
}
bool DisjointSetQuickUnionSlowFind::Find(int a, int b)
{
	return (Root(a) == Root(b));
}
