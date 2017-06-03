#pragma once
#include "MST.h"
#include "BinaryHeapMinPQ.h"
class LazyPrimMST:public MST
{
public:
	LazyPrimMST(EdgeWeightedGraph& G);
	Queue<Edge> Edges() override;
	double Weight() override;
private:
	void Visit(EdgeWeightedGraph& G, int v);
private:
	BinaryHeapMinPQ<Edge> m_pq;
};

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph& G):MST(G)
{
	Visit(G, 0);
	int n = 1;
	while (!m_pq.IsEmpty())
	{
		Edge e = m_pq.DelMin();
		int v = e.Either();
		int w = e.Other(v);
		if (!(m_pMarked[v] && m_pMarked[w]))
		{
			m_qEdge.Enqueue(e);
			if (!m_pMarked[v])
			{
				Visit(G, v);
			}
			if (!m_pMarked[w])
			{
				Visit(G, w);
			}
		}
	}
}

Queue<Edge> LazyPrimMST::Edges()
{
	return m_qEdge;
}

double LazyPrimMST::Weight()
{
	double dWeight = 0.0;
	for (int i = 0; i < m_qEdge.Size(); i++)
	{
		dWeight += m_qEdge.Peek(i).Weight();
	}
	return dWeight;
}

void LazyPrimMST::Visit(EdgeWeightedGraph& G, int v)
{
	m_pMarked[v] = true;
	Bag<Edge> b = G.Adj(v);
	for (int i = 0; i < b.Size(); i++)
	{
		m_pq.Insert(b.Peek(i));
	}
}