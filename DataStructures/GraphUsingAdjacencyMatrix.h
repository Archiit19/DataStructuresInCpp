#pragma once

class GraphUsingAdjancencyMatrix
{
	// Graph is represented using Adjacency Matrix with weights. 
private:

	int m_vertices;
	int ** m_graph;
	
	//void DFSRecursiveHelper(int vertex, bool * visited);

public:
	GraphUsingAdjancencyMatrix(int vertices)
	{
		m_vertices = vertices;
		m_graph = new int * [m_vertices];
		for (int i = 0; i < m_vertices; i++)
			m_graph[i] = new int[m_vertices] ;
	}
	void AcceptInput();
	void SimpleDisplay();

	void ShortestPathWeighted();  // Using Djikstra's Algorithm

	//void DisplayBFSTraversal();

	//void DisplayDFSTraversal();
	//void DFSTraversalRecursive();

	//void ShortestPathUnWeightedPath();

};

