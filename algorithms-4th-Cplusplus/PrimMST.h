#pragma once
#include "MST.h"
#include "BinaryHeapIndexMinPQ.h"
class PrimMST :public MST
{
public:
	PrimMST(EdgeWeightedGraph& G);
	~PrimMST();
	Queue<Edge> Edges() override;
	double Weight() override;
private:
	void Visit(EdgeWeightedGraph& G, int v);
private:
	BinaryHeapIndexMinPQ<Edge>* m_pPQ;
	double* m_pDist;
};

PrimMST::PrimMST(EdgeWeightedGraph& G) :MST(G)
{
	m_pDist = new double[G.V()];
	m_pPQ = new BinaryHeapIndexMinPQ<Edge>(G.V());
	this->Visit(G, 0);
	while (!m_pPQ->IsEmpty())
	{
		m_qEdge.Enqueue(m_pPQ->Min());
		Visit(G, m_pPQ->DelMin());
	}
}

PrimMST::~PrimMST()
{
	if (m_pDist)
	{
		delete[] m_pDist;
	}
	if (m_pPQ)
	{
		delete m_pPQ;
	}
}

Queue<Edge> PrimMST::Edges()
{
	return m_qEdge;
}

double PrimMST::Weight()
{
	double dWeight = 0.0;
	for (int i = 0; i < m_qEdge.Size(); i++)
	{
		dWeight += m_qEdge.Peek(i).Weight();
	}
	return dWeight;
}

void PrimMST::Visit(EdgeWeightedGraph& G, int v)
{
	m_pMarked[v] = true;
	Bag<Edge> b = G.Adj(v);
	for (int i = 0; i < b.Size(); i++)
	{
		Edge e = b.Peek(i);
		int w = e.Other(v);
		if (!m_pMarked[w])
		{
			if (m_pPQ->Contain(w))
			{
				if (m_pDist[w] > e.Weight())
				{
					m_pPQ->Change(w, e);
					m_pDist[w] = e.Weight();
				}
			}
			else
			{
				m_pPQ->Insert(w, e);
				m_pDist[w] = e.Weight();
			}
		}
	}
}