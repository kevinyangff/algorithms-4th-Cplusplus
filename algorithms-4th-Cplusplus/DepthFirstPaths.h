#pragma once
#include "Paths.h"
#include "Stack.h"
class DepthFirstPaths :public Paths
{
public:
	DepthFirstPaths(Graph& G, int s);
	bool Marked(int v) override;
	int Count() override;
	Stack<int> PathTo(int v) override;
private:
	void DFS(Graph& G, int s);
};

DepthFirstPaths::DepthFirstPaths(Graph& G, int s):Paths(G, s)
{
	DFS(G, s);
}

bool DepthFirstPaths::Marked(int v)
{
	return m_bMarked[v];
}

int DepthFirstPaths::Count()
{
	return m_nCount;
}

Stack<int> DepthFirstPaths::PathTo(int v)
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

void DepthFirstPaths::DFS(Graph& G, int s)
{
	m_nCount++;
	m_bMarked[s] = true;
	Bag<int> bagTemp = G.Adj(s);
	for (int i = 0; i < bagTemp.Size(); i++)
	{
		int v = bagTemp.Peek(i);
		if (!m_bMarked[v])
		{
			m_edgeTo[v] = s;
			DFS(G, v);
		}
	}
}