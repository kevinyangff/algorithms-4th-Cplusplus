#pragma once
template<typename T>
class TNode
{
public:
	TNode();
	~TNode();
	TNode* m_pLeftNode;
	TNode* m_pRightNode;
	TNode* m_pMidNode;
	T* m_pValue;
	char m_c;
};

template<typename T>
TNode<T>::TNode() :m_pLeftNode(0), m_pMidNode(0), m_pRightNode(0), m_pValue(0), m_c(0)
{
	
}

template<typename T>
TNode<T>::~TNode()
{
	if (m_pValue)
	{
		delete m_pValue;
		m_pValue = 0;
	}
}