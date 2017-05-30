#pragma once
template <typename ITEM>
class Bag
{
public:
	Bag();
	Bag(Bag<ITEM>& b);
	~Bag();
	int Size();
	bool IsEmpty();
	void Add(ITEM);
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
	Node<ITEM>* m_pFirst;
};

template <typename ITEM>
Bag<ITEM>::Bag():m_nSize(0), m_pFirst(0)
{}

template<typename ITEM>
Bag<ITEM>::Bag(Bag<ITEM>& b): m_nSize(0), m_pFirst(0)
{
	for (int i = 0; i < b.Size(); i++)
	{
		this->Add(b.Peek(i));
	}
}

template <typename ITEM>
Bag<ITEM>::~Bag()
{
	while (m_pFirst)
	{
		Node<ITEM>* pTemp = m_pFirst;
		m_pFirst = m_pFirst->pNext;
		delete pTemp;
	}
}

template <typename ITEM>
int Bag<ITEM>::Size()
{
	return m_nSize;
}

template <typename ITEM>
bool Bag<ITEM>::IsEmpty()
{
	return !m_pFirst;
}

template <typename ITEM>
void Bag<ITEM>::Add(ITEM item)
{
	Node<ITEM>* pNode = new Node<ITEM>();
	pNode->item = item;
	pNode->pNext = m_pFirst;
	m_pFirst = pNode;
	m_nSize++;
}

template <typename ITEM>
const ITEM& Bag<ITEM>::Peek(int nDeep) const
{
	assert(m_nSize > nDeep);
	Node<ITEM>* pTemp = m_pFirst;
	for (int i = 0; i < nDeep; i++)
	{
		pTemp = pTemp->pNext;
	}
	return pTemp->item;
}