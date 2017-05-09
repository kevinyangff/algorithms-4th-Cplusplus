#pragma once
#include "assert.h"
template<typename ITEM>
class Stack
{
public:
	Stack();
	virtual ~Stack();
	void Push(ITEM);
	ITEM Pop();
	const ITEM& Peek(int nDeep);
	bool IsEmpty();
	int Size();
public:
	template <typename N>
	struct Node
	{
		Node<N>* pNext;
		N item;
	};
private:
	Node<ITEM>* m_top;
	int m_nSize;
};


template<typename ITEM>
Stack<ITEM>::Stack() :m_top(0), m_nSize(0)
{
}

template<typename ITEM>
Stack<ITEM>::~Stack()
{
	while (m_top)
	{
		Node<ITEM>* pTemp = m_top;
		m_top = m_top->pNext;
		delete pTemp;
	}
}

template<typename ITEM>
void Stack<ITEM>::Push(ITEM item)
{
	Node<ITEM>* pNode = new Node<ITEM>();
	pNode->item = item;
	pNode->pNext = m_top;
	m_top = pNode;
	m_nSize++;
}

template<typename ITEM>
ITEM Stack<ITEM>::Pop()
{
	assert(m_nSize > 0);
	ITEM item = m_top->item;
	Node<ITEM>* pTemp = m_top;
	m_top = m_top->pNext;
	m_nSize--;
	delete pTemp;
	return item;
}

template<typename ITEM>
const ITEM& Stack<ITEM>::Peek(int nDeep)
{
	assert(m_nSize > nDeep);
	Node<ITEM>* pTemp = m_top;
	for (int i = 0; i < nDeep; i++)
	{
		pTemp = pTemp->pNext;
	}
	return pTemp->item;
}

template<typename ITEM>
bool Stack<ITEM>::IsEmpty()
{
	return !m_top;
}

template<typename ITEM>
int Stack<ITEM>::Size()
{
	return m_nSize;
}
