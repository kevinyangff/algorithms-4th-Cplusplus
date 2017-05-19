#pragma once
#pragma once
#include "DoubleLinkNode.h"
#include "Queue.h"
#include <assert.h>

template<typename KEY, typename VALUE>
class BST
{
public:
	BST();
	~BST();
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
	DoubleLinkNode<KEY, VALUE>* Put(DoubleLinkNode<KEY, VALUE>* root, KEY k, VALUE v);
	VALUE Get(DoubleLinkNode<KEY, VALUE>* root, KEY k);
	DoubleLinkNode<KEY, VALUE>* Delete(DoubleLinkNode<KEY, VALUE>* root, KEY k, VALUE& v);

	DoubleLinkNode<KEY, VALUE>* Max(DoubleLinkNode<KEY, VALUE>* root);
	DoubleLinkNode<KEY, VALUE>* Min(DoubleLinkNode<KEY, VALUE>* root);
	DoubleLinkNode<KEY, VALUE>* DelMax(DoubleLinkNode<KEY, VALUE>* root);
	DoubleLinkNode<KEY, VALUE>* DelMin(DoubleLinkNode<KEY, VALUE>* root);
	DoubleLinkNode<KEY, VALUE>* Floor(DoubleLinkNode<KEY, VALUE>* root, KEY k);
	DoubleLinkNode<KEY, VALUE>* Ceiling(DoubleLinkNode<KEY, VALUE>* root, KEY k);
	int Rank(DoubleLinkNode<KEY, VALUE>* root, KEY k);
	KEY Select(DoubleLinkNode<KEY, VALUE>* root, int i);
	void Keys(DoubleLinkNode<KEY, VALUE>* root, KEY min, KEY max, Queue<VALUE>& q);
	int Size(DoubleLinkNode<KEY, VALUE>* root);
private:
	DoubleLinkNode<KEY, VALUE>* m_root;
};

template<typename KEY, typename VALUE>
BST<KEY, VALUE>::BST() :m_root(0)
{
	
}

template<typename KEY, typename VALUE>
BST<KEY, VALUE>::~BST()
{
	while (m_root!=0)
	{
		DelMin();
	}
}

template<typename KEY, typename VALUE>
void BST<KEY, VALUE>::Put(KEY k, VALUE v)
{
	m_root = Put(m_root, k, v);
	return;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Put(DoubleLinkNode<KEY, VALUE>* root, KEY k, VALUE v)
{
	if (root == 0)
	{
		DoubleLinkNode<KEY, VALUE>* pTemp = new DoubleLinkNode<KEY, VALUE>(k, v);
		pTemp->N = 1;
		root = pTemp;
	}else if (root->k == k)
	{
		root->v = v;
	}else if (root->k < k)
	{
		root->right = Put(root->right, k, v);
	}else
	{
		root->left = Put(root->left, k, v);
	}
	root->N = Size(root->left) + Size(root->right) + 1;
	return root;
}

template<typename KEY, typename VALUE>
VALUE BST<KEY, VALUE>::Get(KEY k)
{
	assert(!IsEmpty());
	return Get(m_root, k);
}

template<typename KEY, typename VALUE>
VALUE BST<KEY, VALUE>::Get(DoubleLinkNode<KEY, VALUE>* root, KEY k)
{
	if (root == 0)
	{
		throw 0;
	}
	if (root->k == k)
	{
		return root->v;
	}
	else if (root->k < k)
	{
		return Get(root->right, k);
	}
	else
	{
		return Get(root->left, k);
	}
}

template<typename KEY, typename VALUE>
VALUE BST<KEY, VALUE>::Delete(KEY k)
{
	assert(!IsEmpty());
	VALUE v;
	m_root = Delete(m_root, k, v);
	return v;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Delete(DoubleLinkNode<KEY, VALUE>* root, KEY k, VALUE& v)
{
	if (root == 0)
	{
		throw 0;
	}
	if (root->k == k)
	{
		v = root->v;
		if(root->left != 0)
		{
			DoubleLinkNode<KEY, VALUE>* pLeftMax = Max(root->left);
			DoubleLinkNode<KEY, VALUE>* pTemp = new DoubleLinkNode<KEY, VALUE>(pLeftMax->k, pLeftMax->v);
			pTemp->left = DelMax(root->left);
			pTemp->right = root->right;
			delete root;
			root = pTemp;
		}
		else
		{
			DoubleLinkNode<KEY, VALUE>* pTemp = root->right;
			delete root;
			root = pTemp;
		}
	}
	else if (root->k < k)
	{
		root->right = Delete(root->right, k, v);
	}
	else
	{
		root->left = Delete(root->left, k, v);
	}
	Size(root);
	return root;
}

template<typename KEY, typename VALUE>
int BST<KEY, VALUE>::Size()
{
	return Size(m_root);
}

template<typename KEY, typename VALUE>
bool BST<KEY, VALUE>::Contains(KEY k)
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
bool BST<KEY, VALUE>::IsEmpty()
{
	return !m_root;
}

template<typename KEY, typename VALUE>
Queue<VALUE> BST<KEY, VALUE>::Keys()
{
	Queue<VALUE> q;
	Keys(m_root, Min(), Max(), q);
	return q;
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Max()
{
	assert(!IsEmpty());
	return Max(m_root)->k;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Max(DoubleLinkNode<KEY, VALUE>* root)
{
	if (root->right != 0)
	{
		return Max(root->right);
	}
	else
	{
		return root;
	}
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Min()
{
	assert(!IsEmpty());
	return Min(m_root)->k;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Min(DoubleLinkNode<KEY, VALUE>* root)
{
	if (root->left != 0)
	{
		return Min(root->left);
	}
	else
	{
		return root;
	}
}

template<typename KEY, typename VALUE>
void BST<KEY, VALUE>::DelMax()
{
	assert(!IsEmpty());
	m_root = DelMax(m_root);
	return;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::DelMax(DoubleLinkNode<KEY, VALUE>* root)
{
	if (root->right != 0)
	{
		root->right = DelMax(root->right);
	}
	else
	{
		DoubleLinkNode<KEY, VALUE>* pTemp = root->left;
		delete root;
		root = pTemp;
	}
	Size(root);
	return root;
}

template<typename KEY, typename VALUE>
void BST<KEY, VALUE>::DelMin()
{
	assert(!IsEmpty());
	m_root = DelMin(m_root);
	return;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::DelMin(DoubleLinkNode<KEY, VALUE>* root)
{
	if (root->left != 0)
	{
		root->left = DelMin(root->left);
	}
	else
	{
		DoubleLinkNode<KEY, VALUE>* pTemp = root->right;
		delete root;
		root = pTemp;
	}
	Size(root);
	return root;
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Floor(KEY k)
{
	assert(!IsEmpty());
	DoubleLinkNode<KEY, VALUE>* pTemp = Floor(m_root, k);
	if (pTemp == 0)
	{
		throw 0;
	}
	return pTemp->k;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Floor(DoubleLinkNode<KEY, VALUE>* root, KEY k)
{
	if (root == 0) return 0;
	if (root->k == k)
	{
		return root;
	}
	else if (root->k > k)
	{
		return Floor(root->left, k);
	}
	else
	{
		DoubleLinkNode<KEY, VALUE>* pTemp = Floor(root->right, k);
		if(pTemp == 0)
		{
			return root;
		}
		return pTemp;
	}
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Ceiling(KEY k)
{
	assert(!IsEmpty());
	DoubleLinkNode<KEY, VALUE>* pTemp = Ceiling(m_root, k);
	if (pTemp == 0)
	{
		throw 0;
	}
	return pTemp->k;
}

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>* BST<KEY, VALUE>::Ceiling(DoubleLinkNode<KEY, VALUE>* root, KEY k)
{
	if (root == 0) return 0;
	if (root->k == k)
	{
		return root;
	}
	else if (root->k < k)
	{
		return Ceiling(root->right, k);
	}
	else
	{
		DoubleLinkNode<KEY, VALUE>* pTemp = Ceiling(root->left, k);
		if (pTemp == 0)
		{
			return root;
		}
		return pTemp;
	}
}

template<typename KEY, typename VALUE>
int BST<KEY, VALUE>::Rank(KEY k)
{
	return Rank(m_root, k);
}

template<typename KEY, typename VALUE>
int BST<KEY, VALUE>::Rank(DoubleLinkNode<KEY, VALUE>* root, KEY k)
{
	if (root == 0)
	{
		return 0;
	}
	if (root->k == k)
	{
		return Size(root->left);
	}
	else if(root->k > k)
	{
		return Rank(root->left, k);
	}
	else
	{
		return Rank(root->right, k) + Size(root->left) + 1;
	}
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Select(int i)
{
	assert(i>=0);
	assert(!IsEmpty());
	assert(i < m_root->N);
	return Select(m_root, i);
}

template<typename KEY, typename VALUE>
KEY BST<KEY, VALUE>::Select(DoubleLinkNode<KEY, VALUE>* root, int i)
{
	if (root == 0)
	{
		throw 0;
	}
	if (Size(root->left) == i)
	{
		return root->k;
	}
	else if (Size(root->left) > i)
	{
		return Select(root->left, i);
	}
	else
	{
		return Select(root->right, i - Size(root->left) - 1);
	}
}

template<typename KEY, typename VALUE>
int BST<KEY, VALUE>::Size(KEY lo, KEY hi)
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
int BST<KEY, VALUE>::Size(DoubleLinkNode<KEY, VALUE>* root)
{
	int nSize = 0;
	if(root == 0)
	{
		return 0;
	}
	if (root->left != 0)
	{
		nSize += root->left->N;
	}
	if (root->right != 0)
	{
		nSize += root->right->N;
	}
	nSize += 1;
	root->N = nSize;
	return nSize;
}

template<typename KEY, typename VALUE>
Queue<VALUE> BST<KEY, VALUE>::Keys(KEY lo, KEY hi)
{
	Queue<VALUE> q;
	Keys(m_root, lo, hi, q);
	return q;
}
template<typename KEY, typename VALUE>
void BST<KEY, VALUE>::Keys(DoubleLinkNode<KEY, VALUE>* root, KEY min, KEY max, Queue<VALUE>& q)
{
	if (root == 0) return;
	if (root->k > min)
	{
		Keys(root->left, min, max, q);
	}
	if (root->k >= min && root->k <= max)
	{
		q.Enqueue(root->v);
	}
	if (root->k < max)
	{
		Keys(root->right, min, max, q);
	}
	return;
}