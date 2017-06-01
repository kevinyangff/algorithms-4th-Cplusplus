#pragma once
#include "Stack.h"
#include "DiGraph.h"
#include "DirectedDFCycle.h"
#include "DirectedDFOrder.h"
#include <assert.h>
class DirectedDFTopologic
{
public:
	DirectedDFTopologic(DiGraph& g);
	bool HasOrder();
	Stack<int> Order();
private:
	bool m_bHasOrder;
	DiGraph& m_G;
};

DirectedDFTopologic::DirectedDFTopologic(DiGraph& g):m_G(g)
{
	m_bHasOrder = !DirectedDFCycle(g).HasCycle();
}
bool DirectedDFTopologic::HasOrder()
{
	return m_bHasOrder;
}

Stack<int> DirectedDFTopologic::Order()
{
	assert(m_bHasOrder);
	return DirectedDFOrder(m_G).ReversePost();
}