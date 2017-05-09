#pragma once
#include <assert.h>

template <typename ITEM>
class Queue {
public:
	Queue();
	~Queue();
	bool IsEmpty();
	int Size();
	void Enqueue(ITEM item);
	ITEM Dequeue();
	const ITEM& Peek(int nDeep) const;
public:
	template <typename T>
	struct Node
	{
		Node* pNext;
		T item;
	};
private:
	int m_nSize;
	Node<ITEM>* m_head;
	Node<ITEM>* m_tail;
};

template <typename ITEM>
Queue<ITEM>::Queue() :m_nSize(0), m_head(0), m_tail(0)
{

}

template <typename ITEM>
Queue<ITEM>::~Queue()
{
	while (m_head)
	{
		Node<ITEM>* pTemp = m_head;
		m_head = pTemp->pNext;
		delete pTemp;
	}
}

template <typename ITEM>
bool Queue<ITEM>::IsEmpty()
{
	return !m_head;
}

template <typename ITEM>
int Queue<ITEM>::Size()
{
	return m_nSize;
}

template <typename ITEM>
void Queue<ITEM>::Enqueue(ITEM item)
{
	Node<ITEM>* pNode = new Node<ITEM>();
	pNode->item = item;
	if (m_head == 0)
	{
		m_head = pNode;
		m_tail = pNode;
	}
	else
	{
		m_tail->pNext = pNode;
		m_tail = pNode;
	}
	m_nSize++;
}

template <typename ITEM>
ITEM Queue<ITEM>::Dequeue()
{
	assert(!this->IsEmpty());
	Node<ITEM>* pTemp = m_head;
	ITEM item = pTemp->item;
	m_head = m_head->pNext;
	m_nSize--;
	if (m_head == 0)
	{
		m_tail = 0;
	}
	return item;
}

template <typename ITEM>
const ITEM& Queue<ITEM>::Peek(int nDeep) const
{
	assert(m_nSize>nDeep);
	Node<ITEM>* pTemp = m_head;
	for (int i = 0; i < nDeep; i++)
	{
		pTemp = pTemp->pNext;
	}
	return pTemp->item;
}