#pragma once
#include <iostream>
using namespace std;
class DirectedEdge
{
public:
	DirectedEdge();
	DirectedEdge(int from, int to, double weight);
	DirectedEdge(const DirectedEdge& e);
	DirectedEdge operator=(const DirectedEdge& e);
	int From() const;
	int To() const;
	double Weight() const;
	void Show() const;
private:
	int m_from;
	int m_to;
	double m_weight;

	friend bool operator>(const DirectedEdge& e1, const DirectedEdge& e2);
	friend bool operator<(const DirectedEdge& e1, const DirectedEdge& e2);
	friend bool operator==(const DirectedEdge& e1, const DirectedEdge& e2);
};

DirectedEdge::DirectedEdge() :m_from(0), m_to(0), m_weight(0.0)
{}

DirectedEdge::DirectedEdge(int from, int to, double weight):m_from(from), m_to(to), m_weight(weight)
{}

DirectedEdge::DirectedEdge(const DirectedEdge& e):m_from(e.From()), m_to(e.To()), m_weight(e.Weight())
{}

DirectedEdge DirectedEdge::operator=(const DirectedEdge& e)
{
	this->m_from = e.From();
	this->m_to = e.To();
	this->m_weight = e.Weight();
	return *this;
}

int DirectedEdge::From() const
{
	return m_from;
}
int DirectedEdge::To() const
{
	return m_to;
}
double DirectedEdge::Weight() const
{
	return m_weight;
}
void DirectedEdge::Show() const
{
	cout << m_from << " -> " << m_to << ": " << m_weight << endl;
}
bool operator>(const DirectedEdge& e1, const DirectedEdge& e2)
{
	return e1.Weight() > e2.Weight();
}
bool operator<(const DirectedEdge& e1, const DirectedEdge& e2)
{
	return e1.Weight() < e2.Weight();
}
bool operator==(const DirectedEdge& e1, const DirectedEdge& e2)
{
	return e1.Weight() == e2.Weight();
}