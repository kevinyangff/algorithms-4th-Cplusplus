#pragma once
#include "SingleLinkNode.h"
#include "Queue.h"
#include <assert.h>

template<typename KEY, typename VALUE>
class SequentialSearchST
{
public:
	SequentialSearchST();
	~SequentialSearchST();
	void Put(KEY k, VALUE v);
	VALUE Get(KEY k);
	VALUE Delete(KEY k);
	int Size();
	bool Contains(KEY k);
	bool IsEmpty();
	Queue<VALUE> Keys();
private:
	int m_nSize;
	SingleLinkNode<KEY, VALUE>* m_head;
};

template<typename KEY, typename VALUE>
SequentialSearchST<KEY, VALUE>::SequentialSearchST():m_nSize(0), m_head(0)
{}

template<typename KEY, typename VALUE>
SequentialSearchST<KEY, VALUE>::~SequentialSearchST()
{
	if (m_head != 0)
	{
		SingleLinkNode<KEY, VALUE>* pTemp = m_head->next;
		delete m_head;
		m_head = pTemp;
	}
}

template<typename KEY, typename VALUE>
void SequentialSearchST<KEY, VALUE>::Put(KEY k, VALUE v)
{
	SingleLinkNode<KEY, VALUE>* pTemp = m_head;
	while (pTemp != 0)
	{
		if (pTemp->k == k)
		{
			pTemp->v = v;
			break;
		}
		pTemp = pTemp->next;
	}
	if (pTemp == 0)
	{
		pTemp = m_head;
		m_head = new SingleLinkNode<KEY, VALUE>(k, v);
		m_head->next = pTemp;
		m_nSize++;
	}
}

template<typename KEY, typename VALUE>
VALUE SequentialSearchST<KEY, VALUE>::Get(KEY k)
{
	SingleLinkNode<KEY, VALUE>* pTemp = m_head;
	while (pTemp != 0)
	{
		if (pTemp->k == k)
		{
			return pTemp->v;
		}
		pTemp = pTemp->next;
	}
	if (pTemp == 0)
	{
		throw 0;
	}
}

template<typename KEY, typename VALUE>
VALUE SequentialSearchST<KEY, VALUE>::Delete(KEY k)
{
	SingleLinkNode<KEY, VALUE>* pTemp = m_head;
	SingleLinkNode<KEY, VALUE>* pTempLast = m_head;
	while (pTemp != 0)
	{
		if (pTemp->k == k)
		{
			pTempLast->next = pTemp->next;
			VALUE v = pTemp->v;
			delete pTemp;
			m_nSize--;
			if (m_nSize == 0)
			{
				m_head = 0;
			}
			return v;
		}
		pTempLast = pTemp;
		pTemp = pTemp->next;
	}
	if (pTemp == 0)
	{
		throw 0;
	}
}

template<typename KEY, typename VALUE>
int SequentialSearchST<KEY, VALUE>::Size()
{
	return m_nSize;
}

template<typename KEY, typename VALUE>
bool SequentialSearchST<KEY, VALUE>::Contains(KEY k)
{
	try
	{
		this->Get(k)
	}
	catch (int)
	{
		return false;
	}
	return true;
}

template<typename KEY, typename VALUE>
bool SequentialSearchST<KEY, VALUE>::IsEmpty()
{
	return !m_nSize;
}

template<typename KEY, typename VALUE>
Queue<VALUE> SequentialSearchST<KEY, VALUE>::Keys()
{
	Queue<VALUE> q;
	SingleLinkNode<KEY, VALUE>* pTemp = m_head;
	while (pTemp != 0)
	{
		q.Enqueue(pTemp->v);
		pTemp = pTemp->next;
	}
	return q;
}