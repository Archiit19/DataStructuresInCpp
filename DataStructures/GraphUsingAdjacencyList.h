#pragma once
#include "ListNode.h"

class GraphUsingAdjancencyList
{
// Graph is represented using Adjacency List. 
private:

	int m_vertices;
	//int * weights;
	ListNode<int> ** m_graphNode;
	void DFSRecursiveHelper(int vertex, bool * visited);

public:
	GraphUsingAdjancencyList(int vertices)
	{
		m_vertices = vertices;
		m_graphNode = new ListNode<int> * [m_vertices];
		for (int i = 0; i < vertices; i++)
			m_graphNode[i] = NULL;
	}
	void AcceptInput();
	void SimpleDisplay();
	void AddEdge(int src, int dest);

	void DisplayBFSTraversal();

	void DisplayDFSTraversal();
	void DFSTraversalRecursive();

	void ShortestPathUnWeightedPath();

};