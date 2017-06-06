#pragma once
#include "SP.h"
#include "BinaryHeapIndexMinPQ.h"
class DijkstraSP :public SP
{
public:
	DijkstraSP(EdgeWeightedDiGraph& G, int s);
	~DijkstraSP();
	bool HasNegativeWeightEdge();
private:
	void Relax(EdgeWeightedDiGraph& G, int v) override;
private:
	BinaryHeapIndexMinPQ<double>* m_pqIndex;
	bool m_bHasNegativeWeightEdge;
};

DijkstraSP::DijkstraSP(EdgeWeightedDiGraph& G, int s) :SP(G, s)
{
	m_pqIndex = 0;
	Bag<DirectedEdge> b = G.Edges();
	for (int i = 0; i < b.Size(); i++)
	{
		if (b.Peek(i).Weight() < 0)
		{
			m_bHasNegativeWeightEdge = true;
			return;
		}
	}
	m_bHasNegativeWeightEdge = false;
	m_pqIndex = new BinaryHeapIndexMinPQ<double>(G.V());
	m_pDistTo[s] = 0.0;
	m_pEdgeTo[s] = DirectedEdge(s, s, 0.0);
	m_pMarked[s] = true;
	m_pqIndex->Insert(s, 0.0);
	while (!m_pqIndex->IsEmpty())
	{
		int v = m_pqIndex->DelMin();
		Relax(G, v);
	}
}

DijkstraSP::~DijkstraSP()
{
	if (m_pqIndex)
	{
		delete m_pqIndex;
	}
}

bool DijkstraSP::HasNegativeWeightEdge()
{
	return m_bHasNegativeWeightEdge;
}

void DijkstraSP::Relax(EdgeWeightedDiGraph& G, int v)
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
			m_pMarked[w] = true;//not necessary actually
			if (m_pqIndex->Contain(w))
			{
				m_pqIndex->Change(w, m_pDistTo[w]);
			}
			else
			{
				m_pqIndex->Insert(w, m_pDistTo[w]);
			}
		}
	}
}