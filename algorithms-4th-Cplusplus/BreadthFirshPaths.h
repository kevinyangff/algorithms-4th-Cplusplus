#pragma once
#include "Paths.h"
#include "Stack.h"
#include "Queue.h"

class BreadthFirstPaths :public Paths
{
public:
	BreadthFirstPaths(Graph& G, int s);
	bool Marked(int v) override;
	int Count() override;
	Stack<int> PathTo(int v) override;
private:
	void BFS(Graph& G, int s);
};

BreadthFirstPaths::BreadthFirstPaths(Graph& G, int s) :Paths(G, s)
{
	BFS(G, s);
}

bool BreadthFirstPaths::Marked(int v)
{
	return m_bMarked[v];
}

int BreadthFirstPaths::Count()
{
	return m_nCount;
}

Stack<int> BreadthFirstPaths::PathTo(int v)
{
	assert(m_bMarked[v]);
	Stack<int> s;
	while (v != m_edgeTo[v])
	{
		s.Push(v);
		v = m_edgeTo[v];
	}
	s.Push(v);
	return s;
}

void BreadthFirstPaths::BFS(Graph& G, int s)
{
	Queue<int> q;
	q.Enqueue(s);
	while (!q.IsEmpty())
	{
		int s = q.Dequeue();
		if(!m_bMarked[s])
		{
			m_bMarked[s] = true;
			m_nCount++;
			Bag<int> bagTemp = G.Adj(s);
			for (int i = 0; i < bagTemp.Size(); i++)
			{
				int v = bagTemp.Peek(i);
				if (!m_bMarked[v])
				{
					m_edgeTo[v] = s;
					q.Enqueue(v);
				}
			}
		}
	}
}