#pragma once
#include "DiGraph.h"
#include "Queue.h"
#include "Stack.h"
class DirectedDFOrder {
public:
	DirectedDFOrder(DiGraph& G);
	~DirectedDFOrder();
	Queue<int> Pre();
	Queue<int> Post();
	Stack<int> ReversePost();
private:
	void DFO(DiGraph& G, int s);
private:
	bool* m_pMarked;
	Queue<int> m_pre;
	Queue<int> m_post;
	Stack<int> m_reversePost;
};

DirectedDFOrder::DirectedDFOrder(DiGraph& G)
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

DirectedDFOrder::~DirectedDFOrder()
{
	if (m_pMarked)
	{
		delete [] m_pMarked;
	}
}

Queue<int> DirectedDFOrder::Pre()
{
	return m_pre;
}

Queue<int> DirectedDFOrder::Post()
{
	return m_post;
}

Stack<int> DirectedDFOrder::ReversePost()
{
	return m_reversePost;
}

void DirectedDFOrder::DFO(DiGraph& G, int s)
{
	m_pMarked[s] = true;
	m_pre.Enqueue(s);
	Bag<int> b = G.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i);
		if (!m_pMarked[nV])
		{
			DFO(G, nV);
		}
	}
	m_post.Enqueue(s);
	m_reversePost.Push(s);
}