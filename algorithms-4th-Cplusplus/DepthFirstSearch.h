#pragma once
#include "Search.h"
class DepthFirstSearch:public Search
{
public:
	DepthFirstSearch(Graph& G, int s);
	bool Marked(int v) override;
	int Count() override;
private:
	void DFS(Graph& G, int s);
};

DepthFirstSearch::DepthFirstSearch(Graph& G, int s):Search(G, s)
{
	DFS(G, s);
}

bool DepthFirstSearch::Marked(int v)
{
	return m_bMarked[v];
}

int DepthFirstSearch::Count()
{
	return m_nCount;
}

void DepthFirstSearch::DFS(Graph& G, int s)
{
	m_nCount++;
	m_bMarked[s] = true;
	Bag<int> bagTemp = G.Adj(s);
	for (int i = 0; i < bagTemp.Size(); i++)
	{
		if (!m_bMarked[bagTemp.Peek(i)])
		{
			DFS(G, bagTemp.Peek(i));
		}
	}
}