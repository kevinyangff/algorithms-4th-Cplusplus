#pragma once
#pragma once
#include "SingleLinkNode.h"
#include "Queue.h"
#include <assert.h>

template<typename KEY, typename VALUE>
class BinarySearchST
{
public:
	BinarySearchST(int nCapacity);
	~BinarySearchST();
	void Put(KEY k, VALUE v);
	VALUE Get(KEY k);
	VALUE Delete(KEY k);
	int Size();
	bool Contains(KEY k);
	bool IsEmpty();
	Queue<VALUE> Keys();

	KEY Max();
	KEY Min();
	void DelMax();
	void DelMin();
	KEY Floor(KEY k);
	KEY Ceiling(KEY k);
	int Rank(KEY k);
	KEY Select(int i);
	int Size(KEY lo, KEY hi);
	Queue<VALUE> Keys(KEY lo, KEY hi);
private:
	int Rank(KEY k, int lo, int hi);
	int m_nSize;
	int m_nValidLength;
	KEY* m_pK;
	VALUE* m_pV;
};

template<typename KEY, typename VALUE>
BinarySearchST<KEY, VALUE>::BinarySearchST(int nCapacity) :m_nSize(nCapacity), m_nValidLength(0)
{
	m_pK = new KEY[nCapacity];
	m_pV = new VALUE[nCapacity];
}

template<typename KEY, typename VALUE>
BinarySearchST<KEY, VALUE>::~BinarySearchST()
{
	delete m_pK;
	delete m_pV;
}

template<typename KEY, typename VALUE>
void BinarySearchST<KEY, VALUE>::Put(KEY k, VALUE v)
{
	int nRank = Rank(k);
	if (m_pK[nRank] == k)
	{
		m_pK[nRank] = v;
	}
	else
	{
		for (int i = m_nValidLength-1; i >= nRank; i--)
		{
			m_pK[i + 1] = m_pK[i];
			m_pV[i + 1] = m_pV[i];
		}
		m_pK[nRank] = k;
		m_pV[nRank] = v;
		m_nValidLength++;
	}
}

template<typename KEY, typename VALUE>
VALUE BinarySearchST<KEY, VALUE>::Get(KEY k)
{
	int nRank = Rank(k);
	if (m_pK[nRank] == k)
	{
		return m_pV[nRank];
	}
	else
	{
		throw 0;
	}
}

template<typename KEY, typename VALUE>
VALUE BinarySearchST<KEY, VALUE>::Delete(KEY k)
{
	int nRank = Rank(k);
	if (m_pK[nRank] == k)
	{
		for (int i = nRank; i < m_nValidLength; i++)
		{
			m_pK[i] = m_pK[i + 1];
			m_pV[i] = m_pV[i + 1];
			m_nValidLength--;
		}
	}
	else
	{
		throw 0;
	}
}

template<typename KEY, typename VALUE>
int BinarySearchST<KEY, VALUE>::Size()
{
	return m_nValidLength;
}

template<typename KEY, typename VALUE>
bool BinarySearchST<KEY, VALUE>::Contains(KEY k)
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
bool BinarySearchST<KEY, VALUE>::IsEmpty()
{
	return !m_nValidLength;
}

template<typename KEY, typename VALUE>
Queue<VALUE> BinarySearchST<KEY, VALUE>::Keys()
{
	Queue<VALUE> q;
	for (int i = 0; i < m_nValidLength; i++)
	{
		q.Enqueue(m_pK[i]);
	}
	return q;
}

template<typename KEY, typename VALUE>
KEY BinarySearchST<KEY, VALUE>::Max()
{
	assert(!IsEmpty());
	m_pK[m_nValidLength - 1];
}

template<typename KEY, typename VALUE>
KEY BinarySearchST<KEY, VALUE>::Min()
{
	assert(!IsEmpty());
	m_pK[0];
}

template<typename KEY, typename VALUE>
void BinarySearchST<KEY, VALUE>::DelMax()
{
	assert(!IsEmpty());
	m_nValidLength--;
}

template<typename KEY, typename VALUE>
void BinarySearchST<KEY, VALUE>::DelMin()
{
	for (i = 1; i < m_nValidLength; i++)
	{
		m_pK[i] = m_pK[i++];
		m_pV[i] = m_pV[i++];
	}
}

template<typename KEY, typename VALUE>
KEY BinarySearchST<KEY, VALUE>::Floor(KEY k)
{
	assert(!IsEmpty());
	if (Contains(k))
	{
		return k;
	}
	else
	{
		return m_pK[Rank(k) - 1];
	}
}

template<typename KEY, typename VALUE>
KEY BinarySearchST<KEY, VALUE>::Ceiling(KEY k)
{
	assert(!IsEmpty());
	return m_pK[Rank(k)];
}

template<typename KEY, typename VALUE>
int BinarySearchST<KEY, VALUE>::Rank(KEY k)
{
	return Rank(k, 0, m_nValidLength - 1);
}

template<typename KEY, typename VALUE>
int BinarySearchST<KEY, VALUE>::Rank(KEY k, int lo, int hi)
{
	if (hi < lo) return lo;
	int nMid = lo + (hi-lo) / 2;
	if (m_pK[nMid] == k)
	{
		return nMid;
	}
	if (m_pK[nMid] > k)
	{
		return Rank(k, lo, nMid - 1);
	}
	else
	{
		return Rank(k, nMid + 1, hi);
	}
}

template<typename KEY, typename VALUE>
KEY BinarySearchST<KEY, VALUE>::Select(int i)
{
	assert(!IsEmpty());
	if (m_nValidLength <= i)
	{
		throw 1;
	}
	return m_pK[i];
}

template<typename KEY, typename VALUE>
int BinarySearchST<KEY, VALUE>::Size(KEY lo, KEY hi)
{
	int nLo = Rank(lo);
	int nHi = Rank(hi);
	if (nLo > nHi)
	{
		return 0;
	}
	if (Contains(hi))
	{
		return nHi - nLo + 1;
	}
	else
	{
		return nHi - nLo;
	}
}

template<typename KEY, typename VALUE>
Queue<VALUE> BinarySearchST<KEY, VALUE>::Keys(KEY lo, KEY hi)
{
	Queue<VALUE> q;
	int nLo = Rank(lo);
	int nHi = Rank(hi);
	if(nLo > nHi)
	{
		return q;
	}
	if (Contains(hi))
	{
		for (int i = lo; i <= hi; i++)
		{
			q.Enqueue(m_pV[i]);
		}
	}
	else
	{
		for (int i = lo; i < hi; i++)
		{
			q.Enqueue(m_pV[i]);
		}
	}
	return q;
}