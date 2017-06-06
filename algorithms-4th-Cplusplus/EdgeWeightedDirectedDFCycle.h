#pragma once
#include "EdgeWeightedDiGraph.h"
#include "Stack.h"
class EdgeWeightedDirectedDFCycle
{
public:
	EdgeWeightedDirectedDFCycle(EdgeWeightedDiGraph& g);
	~EdgeWeightedDirectedDFCycle();
	bool HasCycle();
private:
	void DFCY(EdgeWeightedDiGraph& g, int s);
private:
	bool m_bHasCycle;
	bool* m_pMarked;
	bool* m_pOnStack;
};

EdgeWeightedDirectedDFCycle::EdgeWeightedDirectedDFCycle(EdgeWeightedDiGraph& g) :m_bHasCycle(false), m_pMarked(0), m_pOnStack(0)
{
	m_pMarked = new bool[g.V()];
	m_pOnStack = new bool[g.V()];
	for (int i = 0; i < g.V(); i++)
	{
		m_pMarked[i] = false;
		m_pOnStack[i] = false;
	}
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i] && !m_bHasCycle)
		{
			DFCY(g, i);
		}
	}
}
EdgeWeightedDirectedDFCycle::~EdgeWeightedDirectedDFCycle()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
	if (m_pOnStack)
	{
		delete[] m_pOnStack;
	}
}
bool EdgeWeightedDirectedDFCycle::HasCycle()
{
	return m_bHasCycle;
}
void EdgeWeightedDirectedDFCycle::DFCY(EdgeWeightedDiGraph& g, int s)
{
	m_pMarked[s] = true;
	m_pOnStack[s] = true;
	Bag<DirectedEdge> b = g.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i).To();
		if (!m_pMarked[nV])
		{
			DFCY(g, nV);
		}
		else if (m_pOnStack[nV])
		{
			m_bHasCycle = true;
			break;
		}
	}
	m_pOnStack[s] = false;
}