#pragma once
#include "MST.h"
#include "BinaryHeapMinPQ.h"
#include "WeightQuickUnion.h"
class KruskalMST :public MST
{
public:
	KruskalMST(EdgeWeightedGraph& G);
	~KruskalMST();
	Queue<Edge> Edges() override;
	double Weight() override;
private:
	BinaryHeapMinPQ<Edge> m_PQ;
	WeightQuickUnionUF* m_pUF;
};

KruskalMST::KruskalMST(EdgeWeightedGraph& G) :MST(G)
{
	m_pUF = new WeightQuickUnionUF(G.V());
	Bag<Edge> bagTotal = G.Edges();
	for (int i = 0; i < bagTotal.Size(); i++)
	{
		m_PQ.Insert(bagTotal.Peek(i));
	}
	while (!m_PQ.IsEmpty())
	{
		Edge e = m_PQ.DelMin();
		int v = e.Either();
		int w = e.Other(v);
		if (!m_pUF->IsConnect(v, w))
		{
			m_qEdge.Enqueue(e);
			m_pUF->Union(v, w);
		}
	}
}

KruskalMST::~KruskalMST()
{
	if (m_pUF)
	{
		delete m_pUF;
	}
}

Queue<Edge> KruskalMST::Edges()
{
	return m_qEdge;
}

double KruskalMST::Weight()
{
	double dWeight = 0.0;
	for (int i = 0; i < m_qEdge.Size(); i++)
	{
		dWeight += m_qEdge.Peek(i).Weight();
	}
	return dWeight;
}
