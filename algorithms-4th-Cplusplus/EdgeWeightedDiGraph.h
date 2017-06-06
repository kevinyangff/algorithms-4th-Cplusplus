#pragma once
#include "DirectedEdge.h"
#include "Bag.h"
#include <assert.h>
class EdgeWeightedDiGraph
{
public:
	EdgeWeightedDiGraph(int V);
	EdgeWeightedDiGraph(istream& ist);
	~EdgeWeightedDiGraph();
	int V();
	int E();
	void AddEdge(const DirectedEdge& e);
	Bag<DirectedEdge> Adj(int v);
	Bag<DirectedEdge> Edges();
	void Show();
private:
	int m_nV;
	int m_nE;
	Bag<DirectedEdge>* m_pBag;
};

EdgeWeightedDiGraph::EdgeWeightedDiGraph(int V):m_nV(0), m_nE(0), m_pBag(0)
{
	m_nV = V;
	m_pBag = new Bag<DirectedEdge>[V];
}

EdgeWeightedDiGraph::EdgeWeightedDiGraph(istream& ist) :m_nV(0), m_nE(0), m_pBag(0)
{
	ist >> m_nV >> m_nE;
	assert(m_nV > 0);
	m_pBag = new Bag<DirectedEdge>[m_nV];
	for (int i = 0; i < m_nE; i++)
	{
		int v, w;
		double dWeight;
		ist >> v;
		ist >> w;
		ist >> dWeight;
		this->AddEdge(DirectedEdge(v, w, dWeight));
		m_nE--;
	}
}
EdgeWeightedDiGraph::~EdgeWeightedDiGraph()
{
	if (!m_pBag)
	{
		delete[] m_pBag;
	}
}
int EdgeWeightedDiGraph::V()
{
	return m_nV;
}
int EdgeWeightedDiGraph::E()
{
	return m_nE;
}
void EdgeWeightedDiGraph::AddEdge(const DirectedEdge& e)
{
	int f = e.From();
	m_pBag[f].Add(e);
	m_nE++;
}
Bag<DirectedEdge> EdgeWeightedDiGraph::Adj(int v)
{
	return m_pBag[v];
}
Bag<DirectedEdge> EdgeWeightedDiGraph::Edges()
{
	Bag<DirectedEdge> ret;
	for (int i = 0; i < m_nV; i++)
	{
		Bag<DirectedEdge> b = m_pBag[i];
		for (int j = 0; j < b.Size(); j++)
		{
			ret.Add(b.Peek(j));
		}
	}
	return ret;
}
void EdgeWeightedDiGraph::Show()
{
	cout << m_nV << " vertices, " << m_nE << " edges" << endl;
	for (int i = 0; i < m_nV; i++)
	{
		cout << i << ": ";
		Bag<DirectedEdge> b = this->Adj(i);
		for (int j = 0; j < b.Size(); j++)
		{
			b.Peek(j).Show();
		}
		cout << endl;
	}
}