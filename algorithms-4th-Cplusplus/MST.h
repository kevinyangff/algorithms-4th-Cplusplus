#pragma once
#include "EdgeWeightedGraph.h"
#include "Queue.h"
class MST
{
public:
	MST(EdgeWeightedGraph& G);
	~MST();
	virtual Queue<Edge> Edges() = 0;
	virtual double Weight() = 0;
protected:
	bool* m_pMarked;
	Queue<Edge> m_qEdge;
};

MST::MST(EdgeWeightedGraph& G)
{
	m_pMarked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
	}
}

MST::~MST()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
}