#pragma once
#include "SP.h"
#include "Queue.h"
#include "EdgeWeightedDirectedDFCycle.h"
class BellmanFordSP :public SP
{
public:
	BellmanFordSP(EdgeWeightedDiGraph& G, int s);
	~BellmanFordSP();
	bool HasNegativeWeightCycle();
	Bag<DirectedEdge> NegativeWeightCycle(EdgeWeightedDiGraph& G);
private:
	void Relax(EdgeWeightedDiGraph& G, int v);
	void FindNegativeWeightCycle(EdgeWeightedDiGraph& G);
private:
	bool m_bHasNegativeWeightCycle;
	Bag<DirectedEdge> m_bagNegativeWeightCycle;
	Queue<int> m_q;
	bool* m_pOnQueue;
	int m_cost;
};

BellmanFordSP::BellmanFordSP(EdgeWeightedDiGraph& G, int s) :SP(G, s), m_cost(0)
{
	m_bHasNegativeWeightCycle = false;
	m_pOnQueue = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pOnQueue[i] = false;
	}
	m_pDistTo[s] = 0.0;
	m_pEdgeTo[s] = DirectedEdge(s, s, 0.0);
	m_pMarked[s] = true;
	m_q.Enqueue(s);
	m_pOnQueue[s] = true;
	while (!m_q.IsEmpty() && !HasNegativeWeightCycle())
	{
		Relax(G, m_q.Dequeue());
	}
}

BellmanFordSP::~BellmanFordSP()
{
	if (m_pOnQueue)
	{
		delete[] m_pOnQueue;
	}
}

bool BellmanFordSP::HasNegativeWeightCycle()
{
	return m_bHasNegativeWeightCycle;
}

Bag<DirectedEdge> BellmanFordSP::NegativeWeightCycle(EdgeWeightedDiGraph& G)
{
	return m_bagNegativeWeightCycle;
}

void BellmanFordSP::FindNegativeWeightCycle(EdgeWeightedDiGraph& G)
{
	for (int i = 0; i < G.V(); i++)
	{
		DirectedEdge e = m_pEdgeTo[i];
		if (e.From() != e.To())
		{
			m_bagNegativeWeightCycle.Add(e);
		}
	}
	EdgeWeightedDiGraph EDG(G.V());
	for (int i = 0; i < m_bagNegativeWeightCycle.Size(); i++)
	{
		EDG.AddEdge(m_bagNegativeWeightCycle.Peek(i));
	}
	if (EdgeWeightedDirectedDFCycle(EDG).HasCycle())
	{
		m_bHasNegativeWeightCycle = true;
	}
}

void BellmanFordSP::Relax(EdgeWeightedDiGraph& G, int v)
{
	m_pOnQueue[v] = false;
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
			if(!m_pOnQueue[w])
			{
				m_q.Enqueue(w);
				m_pOnQueue[w] = true;
			}
		}
		if (++m_cost%G.V() == 0)
		{
			this->FindNegativeWeightCycle(G);
		}
	}
}