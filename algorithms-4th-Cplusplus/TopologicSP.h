#pragma once
#include "SP.h"
#include "EdgeWeightedDirectedTopologic.h"
class TopologicSP :public SP
{
public:
	TopologicSP(EdgeWeightedDiGraph& G, int s);
	bool HasCycle();
private:
	void Relax(EdgeWeightedDiGraph& G, int v) override;
private:
	bool m_bHasCycle;
};

TopologicSP::TopologicSP(EdgeWeightedDiGraph& G, int s) :SP(G, s)
{
	EdgeWeightedDirectedDFTopologic tp(G);
	m_bHasCycle = !tp.HasOrder();
	if(m_bHasCycle)
	{
		return;
	}
	Stack<int> stack = tp.Order();
	m_pDistTo[s] = 0.0;
	m_pEdgeTo[s] = DirectedEdge(s, s, 0.0);
	m_pMarked[s] = true;
	while (!stack.IsEmpty())
	{
		Relax(G, stack.Pop());
	}
}

void TopologicSP::Relax(EdgeWeightedDiGraph& G, int v)
{
	Bag<DirectedEdge> b = G.Adj(v);
	for (int i = 0; i < b.Size(); i++)
	{
		DirectedEdge e = b.Peek(i);
		int w = e.To();
		if (m_pDistTo[w] > m_pDistTo[v] + e.Weight())
		{
			m_pDistTo[w] = m_pDistTo[v] + e.Weight();
			m_pEdgeTo[w] = e;
			m_pMarked[w] = true;
		}
	}
}

bool TopologicSP::HasCycle()
{
	return m_bHasCycle;
}