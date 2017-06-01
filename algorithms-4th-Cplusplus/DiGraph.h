#pragma once
#include "Bag.h"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
class DiGraph
{
public:
	DiGraph(int V);
	DiGraph(istream& ist);
	DiGraph(DiGraph& DG);
	~DiGraph();
	int V();
	int E();
	void AddEdge(int v, int w);
	Bag<int> Adj(int v);
	DiGraph reverse();
	void Show();
private:
	Bag<int>* m_pBag;
	int m_nV;
	int m_nE;
};

DiGraph::DiGraph(int V) :m_pBag(0), m_nV(0), m_nE(0)
{
	assert(V > 0);
	m_pBag = new Bag<int>[V];
	m_nV = V;
}

DiGraph::DiGraph(istream& ist) :m_pBag(0), m_nV(0), m_nE(0)
{
	ist >> m_nV >> m_nE;
	assert(m_nV > 0);
	m_pBag = new Bag<int>[m_nV];
	for (int i = 0; i < m_nE; i++)
	{
		int v, w;
		ist >> v;
		ist >> w;
		this->AddEdge(v, w);
		m_nE--;
	}
}

DiGraph::DiGraph(DiGraph& DG)
{
	this->m_nV = DG.V();
	this->m_nE = DG.E();
	m_pBag = new Bag<int>[m_nV];
	for (int i = 0; i < m_nV; i++)
	{
		//m_pBag[i] = DG.Adj(i);//no custom operator = constructor
		for (int j = 0; j < DG.Adj(i).Size(); j++)
		{
			m_pBag->Add(DG.Adj(i).Peek(j));
		}
	}
}

DiGraph::~DiGraph()
{
	if (m_pBag != 0)
	{
		delete[] m_pBag;
	}
}

int DiGraph::V()
{
	return m_nV;
}

int DiGraph::E()
{
	return m_nE;
}

void DiGraph::AddEdge(int v, int w)
{
	assert(v < m_nV && w < m_nV);
	m_pBag[v].Add(w);
	m_nE++;
}

Bag<int> DiGraph::Adj(int v)
{
	assert(v < m_nV);
	return m_pBag[v];
}

DiGraph DiGraph::reverse()
{
	DiGraph DG(this->V());
	for (int i = 0; i < this->V(); i++)
	{
		Bag<int> b = this->Adj(i);
		for (int j = 0; j < b.Size(); j++)
		{
			int nV = b.Peek(j);
			DG.AddEdge(nV, i);
		}
	}
	return DG;
}

void DiGraph::Show()
{
	cout << m_nV << " vertices, " << m_nE << " edges" << endl;
	for (int i = 0; i < m_nV; i++)
	{
		cout << i << ": ";
		Bag<int> bagTemp = this->Adj(i);
		for (int j = 0; j < bagTemp.Size(); j++)
		{
			cout << bagTemp.Peek(j) << " ";
		}
		cout << endl;
	}
}