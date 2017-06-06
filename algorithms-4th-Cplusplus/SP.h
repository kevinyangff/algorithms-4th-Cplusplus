#pragma once
#include "EdgeWeightedDiGraph.h"
#include <limits>
#include "Stack.h"
class SP
{
public:
	SP(EdgeWeightedDiGraph& G, int s);
	~SP();
	double DistTo(int v);
	double HasPathTo(int v);
	Stack<DirectedEdge> PathTo(int v);
protected:
	virtual void Relax(EdgeWeightedDiGraph& G, int v) = 0;
protected:
	bool* m_pMarked;//not necessary actually
	double* m_pDistTo;
	DirectedEdge* m_pEdgeTo;
};

SP::SP(EdgeWeightedDiGraph& G, int s)
{
	m_pMarked = new bool[G.V()];
	m_pDistTo = new double[G.V()];
	m_pEdgeTo = new DirectedEdge[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
		m_pDistTo[i] = numeric_limits<double>::infinity();
	}
}

SP::~SP()
{
	if (m_pEdgeTo)
	{
		delete[] m_pEdgeTo;
	}
	if (m_pDistTo)
	{
		delete[] m_pDistTo;
	}
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
}
double SP::DistTo(int v)
{
	return m_pDistTo[v];
}
double SP::HasPathTo(int v)
{
	//return m_pMarked[v];		//alternative
	return m_pDistTo[v] != numeric_limits<double>::infinity();
}
Stack<DirectedEdge> SP::PathTo(int v)
{
	assert(HasPathTo(v));
	Stack<DirectedEdge> s;
	while (m_pEdgeTo[v].From() != v)
	{
		s.Push(m_pEdgeTo[v]);
		v = m_pEdgeTo[v].From();
	}
	return s;
}