#pragma once
#include <vector>

class DisjointSet
{
protected:
	std::vector<int> m_arr;
public:
	DisjointSet(int size)
	{
		m_arr.resize(size);
	}
	virtual void Union(int a, int b) =0;
	virtual bool Find(int a, int b) =0;

};

class DisjointSetQuickFind : public DisjointSet
{
public:
	DisjointSetQuickFind(int size) : DisjointSet(size)
	{
		for (int i = 0; i < size; i++)
		{
			m_arr[i] = i;
		}
	}
	void Union(int a, int b);
	bool Find(int a, int b);
};


class DisjointSetQuickUnionSlowFind : public DisjointSet
{
public:
	DisjointSetQuickUnionSlowFind(int size) : DisjointSet(size)
	{
		for (int i = 0; i < size; i++)
		{
			m_arr[i] = i;
		}
	}

	void Union(int a, int b);
	int Root(int a);
	bool Find(int a, int b);
};

/*
class DisjointSetQuickUnionBySizeQuickFind : public DisjointSet
{
public:
	DisjointSetQuickUnionBySizeQuickFind(int size) : DisjointSet(size)
	{

	}

	void Union(int a, int b);
	bool Find(int a, int b);
}; 

class DisjointSetQuickUnionByWeightQuickFind : public DisjointSet
{
public:
	DisjointSetQuickUnionByWeightQuickFind(int size) : DisjointSet(size)
	{

	}

	void Union(int a, int b);
	bool Find(int a, int b);
};

class DisjointSetQuickUnionQuickFindShortestPath : public DisjointSet
{
public:
	DisjointSetQuickUnionQuickFindShortestPath(int size) : DisjointSet(size)
	{

	}

	void Union(int a, int b);
	bool Find(int a, int b);
};
*/