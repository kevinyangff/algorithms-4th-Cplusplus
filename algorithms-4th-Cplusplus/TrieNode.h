#pragma once
template<typename T>
class TrieNode
{
public:
	TrieNode(int R);
	~TrieNode();
	TrieNode** m_ppNode;
	T* m_pValue;
};

template<typename T>
TrieNode<T>::TrieNode(int R) :m_ppNode(0), m_pValue(0)
{
	m_ppNode = new TrieNode*[R];
	for (int i = 0; i < R; i++)
	{
		m_ppNode[i] = 0;
	}
}

template<typename T>
TrieNode<T>::~TrieNode()
{
	if (m_ppNode)
	{
		delete[] m_ppNode;
		m_ppNode = 0;
	}
	if (m_pValue)
	{
		delete m_pValue;
		m_pValue = 0;
	}
}