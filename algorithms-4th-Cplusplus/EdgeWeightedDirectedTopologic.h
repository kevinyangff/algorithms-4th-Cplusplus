#pragma once
#include "Stack.h"
#include "EdgeWeightedDiGraph.h"
#include "EdgeWeightedDirectedDFCycle.h"
#include "EdgeWeightedDirectedDFOrder.h"
#include <assert.h>
class EdgeWeightedDirectedDFTopologic
{
public:
	EdgeWeightedDirectedDFTopologic(EdgeWeightedDiGraph& g);
	bool HasOrder();
	Stack<int> Order();
private:
	bool m_bHasOrder;
	EdgeWeightedDiGraph& m_G;
};

EdgeWeightedDirectedDFTopologic::EdgeWeightedDirectedDFTopologic(EdgeWeightedDiGraph& g) :m_G(g)
{
	m_bHasOrder = !EdgeWeightedDirectedDFCycle(g).HasCycle();
}
bool EdgeWeightedDirectedDFTopologic::HasOrder()
{
	return m_bHasOrder;
}

Stack<int> EdgeWeightedDirectedDFTopologic::Order()
{
	assert(m_bHasOrder);
	return EdgeWeightedDirectedDFOrder(m_G).ReversePost();
}