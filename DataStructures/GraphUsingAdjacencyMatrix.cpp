#pragma once
#include "stdafx.h"
#include "GraphUsingAdjacencyMatrix.h"
#include <queue>
using namespace std;

void GraphUsingAdjancencyMatrix::AcceptInput()
{
	cout << "\nEnter the Adjacency Matrix of Graph: " <<endl;
	for (int i = 0; i < m_vertices; i++)
		for(int j =0; j< m_vertices; j++)
			cin >> m_graph[i][j];
}

void GraphUsingAdjancencyMatrix::SimpleDisplay()
{
	cout << "\nThe Adjacency Matrix of Graph is : " << endl;
	for (int i = 0; i < m_vertices; i++)
	{
		for (int j = 0; j < m_vertices; j++)
			cout << m_graph[i][j] << " ";
		cout << endl;
	}

}
void GraphUsingAdjancencyMatrix::ShortestPathWeighted()
{
	int v;
	cout << "Enter the source node : " << endl;
	cin >> v;

	int * distance = new int[m_vertices];
	for (int i = 0; i < m_vertices; i++)
		distance[i] = -1;
	distance[v] = 0;

	priority_queue<int> pq;
	pq.push(v);
	while (!pq.empty())
	{
		int dest = pq.top(); pq.pop();
		for (int j = 0; j < m_vertices; j++)
		{
			int d = distance[dest] + m_graph[dest][j];
			if ( m_graph[dest][j]>0 && (distance[j] == -1 || distance[j] > d) )
			{
				distance[j] = d;
				pq.push(j);
			}
		}
	}

	cout << "Distance of all vertices from " << v << " is : " << endl;
	for (int i = 0; i < m_vertices; i++)
		cout << v << "->" << i << "  =  " << distance[i] << endl;


}
