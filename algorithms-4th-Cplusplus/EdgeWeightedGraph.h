#pragma once
#include "Edge.h"
#include "Bag.h"
#include <assert.h>
class EdgeWeightedGraph
{
public:
	EdgeWeightedGraph(int V);
	~EdgeWeightedGraph();
	EdgeWeightedGraph(istream& ist);
	EdgeWeightedGraph(const EdgeWeightedGraph& EWG);
	int V() const;
	int E() const;
	void AddEdge(Edge e);
	Bag<Edge> Adj(int v) const;
	Bag<Edge> Edges() const;
	void Show();
private:
	Bag<Edge>* m_pBag;
	int m_nV;
	int m_nE;
};

EdgeWeightedGraph::EdgeWeightedGraph(int V) :m_pBag(0), m_nV(0), m_nE(0)
{
	m_nV = V;
	m_pBag = new Bag<Edge>[V];
}

EdgeWeightedGraph::~EdgeWeightedGraph() 
{
	if (m_pBag)
	{
		delete[] m_pBag;
	}
}

EdgeWeightedGraph::EdgeWeightedGraph(istream& ist) :m_pBag(0), m_nV(0), m_nE(0)
{
	ist >> m_nV >> m_nE;
	assert(m_nV > 0);
	m_pBag = new Bag<Edge>[m_nV];
	for (int i = 0; i < m_nE; i++)
	{
		int v, w;
		double dWeight;
		ist >> v;
		ist >> w;
		ist >> dWeight;
		this->AddEdge(Edge(v, w, dWeight));
		m_nE--;
	}
}

EdgeWeightedGraph::EdgeWeightedGraph(const EdgeWeightedGraph& EWG)
{
	this->m_nV = EWG.V();
	this->m_nE = EWG.E();
	Bag<Edge> b = EWG.Edges();
	for(int i=0; i<b.Size(); i++)
	{
		this->AddEdge(b.Peek(i));
		m_nE--;
	}
}

int EdgeWeightedGraph::V() const
{
	return m_nV;
}
int EdgeWeightedGraph::E() const
{
	return m_nE;
}
void EdgeWeightedGraph::AddEdge(Edge e)
{
	int v = e.Either();
	int w = e.Other(v);
	m_pBag[v].Add(e);
	m_pBag[w].Add(e);
	m_nE++;
}
Bag<Edge> EdgeWeightedGraph::Adj(int v) const
{
	return m_pBag[v];
}
Bag<Edge> EdgeWeightedGraph::Edges() const
{
	Bag<Edge> edges;
	for (int i = 0; i < m_nV; i++)
	{
		Bag<Edge> b = this->Adj(i);
		for (int j = 0; j < b.Size(); j++)
		{
			if (b.Peek(j).Other(i) < i)
			{
				edges.Add(b.Peek(j));
			}
		}
	}
	return edges;
}
void EdgeWeightedGraph::Show()
{
	cout << m_nV << " vertices, " << m_nE << " edges" << endl;
	for (int i = 0; i < m_nV; i++)
	{
		cout << i << ": ";
		Bag<Edge> b = this->Adj(i);
		for (int j = 0; j < b.Size(); j++)
		{
			b.Peek(j).Show();
		}
		cout << endl;
	}
}