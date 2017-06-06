#pragma once
#include "EdgeWeightedDiGraph.h"
#include "Queue.h"
#include "Stack.h"
class EdgeWeightedDirectedDFOrder {
public:
	EdgeWeightedDirectedDFOrder(EdgeWeightedDiGraph& G);
	~EdgeWeightedDirectedDFOrder();
	Queue<int> Pre();
	Queue<int> Post();
	Stack<int> ReversePost();
private:
	void DFO(EdgeWeightedDiGraph& G, int s);
private:
	bool* m_pMarked;
	Queue<int> m_pre;
	Queue<int> m_post;
	Stack<int> m_reversePost;
};

EdgeWeightedDirectedDFOrder::EdgeWeightedDirectedDFOrder(EdgeWeightedDiGraph& G)
{
	m_pMarked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
	}
	for (int i = 0; i < G.V(); i++)
	{
		if (!m_pMarked[i])
		{
			DFO(G, i);
		}
	}
}

EdgeWeightedDirectedDFOrder::~EdgeWeightedDirectedDFOrder()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
}

Queue<int> EdgeWeightedDirectedDFOrder::Pre()
{
	return m_pre;
}

Queue<int> EdgeWeightedDirectedDFOrder::Post()
{
	return m_post;
}

Stack<int> EdgeWeightedDirectedDFOrder::ReversePost()
{
	return m_reversePost;
}

void EdgeWeightedDirectedDFOrder::DFO(EdgeWeightedDiGraph& G, int s)
{
	m_pMarked[s] = true;
	m_pre.Enqueue(s);
	Bag<DirectedEdge> b = G.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i).To();
		if (!m_pMarked[nV])
		{
			DFO(G, nV);
		}
	}
	m_post.Enqueue(s);
	m_reversePost.Push(s);
}