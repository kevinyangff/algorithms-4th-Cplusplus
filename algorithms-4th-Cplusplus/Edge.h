#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Edge
{
public:
	Edge();
	Edge(int v, int w, double dWeight);
	Edge(const Edge& e);
	Edge operator=(const Edge& e);

	double Weight() const;
	int Either() const;
	int Other(int v) const;
	void Show() const;
private:
	int m_V;
	int m_W;
	double m_dWeight;

	friend bool operator>(const Edge& e1, const Edge& e2);
	friend bool operator<(const Edge& e1, const Edge& e2);
	friend bool operator==(const Edge& e1, const Edge& e2);
};

Edge::Edge():m_V(0), m_W(0), m_dWeight(0.0)
{}

Edge::Edge(int v, int w, double dWeight):m_V(v), m_W(w), m_dWeight(dWeight)
{}

Edge::Edge(const Edge& e)
{
	this->m_V = e.Either();
	this->m_W = e.Other(m_V);
	this->m_dWeight = e.Weight();
}

Edge Edge::operator=(const Edge& e)
{
	this->m_V = e.Either();
	this->m_W = e.Other(m_V);
	this->m_dWeight = e.Weight();
	return *this;
}

double Edge::Weight() const 
{
	return m_dWeight;
}

int Edge::Either() const
{
	return m_V;
}

int Edge::Other(int v) const
{
	if (v == m_V) return m_W;
	if (v == m_W) return m_V;
	assert(false);
}

void Edge::Show() const
{
	cout << m_V << " - " << m_W << " : " << m_dWeight << endl;
}

bool operator>(const Edge& e1, const Edge& e2)
{
	return e1.Weight() > e2.Weight();
}
bool operator<(const Edge& e1, const Edge& e2)
{
	return e1.Weight() < e2.Weight();
}
bool operator==(const Edge& e1, const Edge& e2)
{
	return e1.Weight() == e2.Weight();
}