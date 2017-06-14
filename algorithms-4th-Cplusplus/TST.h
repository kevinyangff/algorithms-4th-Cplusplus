#pragma once
#include "Queue.h"
#include <string>
#include "TNode.h"

using std::string;
template<typename T>
class TST
{
public:
	TST();
	void Put(string key, T value);
	T Get(string key);
	void Delete(string key);
	bool Contains(string key);
	bool IsEmpty();
	int Size();
	Queue<string> Keys();
	string LongestPrefixOf(string s);
	Queue<string> KeysWithPrefix(string s);
	Queue<string> KeysThatMatch(string s);
private:
	TNode<T>* Put(TNode<T>* node, string key, T value, int d);
	TNode<T>* Get(TNode<T>* node, string key, int d);
	TNode<T>* Delete(TNode<T>* node, string key, int d);
	void Collect(TNode<T>* node, string sTarget, Queue<string>& q);
	void KeysThatMatch(TNode<T>* node, string s, string sTarget, int d, Queue<string>& q);
	void LongestPrefixOf(TNode<T>* node, string s, int d, int& n);
private:
	TNode<T>* m_root;
	int m_nSize;
};

template<typename T>
TST<T>::TST() :m_nSize(0)
{
	m_root = 0;
}

template<typename T>
void TST<T>::Put(string key, T value)
{
	if (key.size() == 0)	return;
	m_root = Put(m_root, key, value, 0);
}

template<typename T>
TNode<T>* TST<T>::Put(TNode<T>* node, string key, T value, int d)
{
	if (node == 0)
	{
		node = new TNode<T>();
		node->m_c = key.at(d);
	}
	char c = key.at(d);
	if (node->m_c > c)
	{
		node->m_pLeftNode = Put(node->m_pLeftNode, key, value, d);
	}
	else if (node->m_c < c)
	{
		node->m_pRightNode = Put(node->m_pRightNode, key, value, d);
	}
	else
	{
		if (d == key.length() - 1)
		{
			if (node->m_pValue != 0)
			{
				delete node->m_pValue;
				node->m_pValue = 0;
			}
			else
			{
				m_nSize++;
			}
			node->m_pValue = new T(value);
			return node;
		}
		node->m_pMidNode = Put(node->m_pMidNode, key, value, d + 1);
	}
	return node;
}

template<typename T>
T TST<T>::Get(string key)
{
	if (key.size() == 0) throw 0;
	TNode<T>* node = Get(m_root, key, 0);
	if (node == 0) throw 0;
	if (node->m_pValue != 0)
	{
		return *(node->m_pValue);
	}
	else
	{
		throw 0;
	}
}

template<typename T>
TNode<T>* TST<T>::Get(TNode<T>* node, string key, int d)
{
	if (node == 0) return 0;
	char c = key.at(d);
	if (node->m_c > c)
	{
		return Get(node->m_pLeftNode, key, d);
	}
	else if (node->m_c < c)
	{
		return Get(node->m_pRightNode, key, d);
	}
	else
	{
		if (d == key.length() - 1)
		{
			return node;
		}
		return Get(node->m_pMidNode, key, d + 1);
	}
}

template<typename T>
void TST<T>::Delete(string key)
{
	if (key.size() == 0) return;
	m_root = Delete(m_root, key, 0);
}

template<typename T>
TNode<T>* TST<T>::Delete(TNode<T>* node, string key, int d)
{
	if (node == 0) return 0;
	char c = key.at(d);
	if (node->m_c > c)
	{
		node->m_pLeftNode = Delete(node->m_pLeftNode, key, d);
	}
	else if (node->m_c < c)
	{
		node->m_pRightNode = Delete(node->m_pRightNode, key, d);
	}
	else
	{
		if (d == key.length() - 1)
		{
			if (node->m_pValue != 0)
			{
				delete node->m_pValue;
				node->m_pValue = 0;
				m_nSize--;
			}
		}
		else
		{
			node->m_pMidNode = Delete(node->m_pMidNode, key, d+1);
		}
	}
	if (node->m_pValue != 0) return node;
	if (node->m_pLeftNode == 0 && node->m_pRightNode == 0 && node->m_pMidNode == 0)
	{
		delete node;
		node = 0;
	}
	return node;
}

template<typename T>
bool TST<T>::Contains(string key)
{
	try
	{
		this->Get(key);
	}
	catch (int)
	{
		return false;
	}
	return true;
}

template<typename T>
bool TST<T>::IsEmpty()
{
	return m_root == 0;
}

template<typename T>
int TST<T>::Size()
{
	return m_nSize;
}

template<typename T>
Queue<string> TST<T>::Keys()
{
	return KeysWithPrefix("");
}

template<typename T>
string TST<T>::LongestPrefixOf(string s)
{
	int n = 0;
	if (s.size() == 0) return "";
	LongestPrefixOf(m_root, s, 0, n);
	return s.substr(0, n+1);
}

template<typename T>
void TST<T>::LongestPrefixOf(TNode<T>* node, string s, int d, int& n)
{
	if (node == 0) return;
	char c = s.at(d);
	if (node->m_c > c)
	{
		LongestPrefixOf(node->m_pLeftNode, s, d, n);
	}
	else if (node->m_c < c)
	{
		LongestPrefixOf(node->m_pRightNode, s, d, n);
	}
	else
	{
		if (node->m_pValue != 0)
		{
			n = d;
		}
		if (d != s.length()-1)
		{
			LongestPrefixOf(node->m_pMidNode, s, d + 1, n);
		}
	}
	return;
}

template<typename T>
Queue<string> TST<T>::KeysWithPrefix(string s)
{
	Queue<string> q;
	TNode<T>* node = 0;
	if (s.size() == 0)
	{
		Collect(m_root, s, q);
	}
	else
	{
		node = Get(m_root, s, 0);
		if (node == 0) return q;
		if (node->m_pValue != 0)
		{
			q.Enqueue(s);
		}
		Collect(node->m_pMidNode, s, q);
	}
	return q;
}

template<typename T>
Queue<string> TST<T>::KeysThatMatch(string s)
{
	Queue<string> q;
	if (s.size() == 0) return q;
	KeysThatMatch(m_root, s, "", 0, q);
	return q;
}

template<typename T>
void TST<T>::KeysThatMatch(TNode<T>* node, string s, string sTarget, int d, Queue<string>& q)
{
	if (node == 0)	return;
	char c = s.at(d);
	if (c == '.')
	{
		KeysThatMatch(node->m_pLeftNode, s, sTarget, d, q);
		KeysThatMatch(node->m_pRightNode, s, sTarget, d, q);
		sTarget += node->m_c;
		if (d == s.length() - 1)
		{
			if (node->m_pValue != 0)
			{
				q.Enqueue(sTarget);
			}
		}
		else
		{
			KeysThatMatch(node->m_pMidNode, s, sTarget, d + 1, q);
		}
	}
	else
	{
		if (node->m_c > c)
		{
			KeysThatMatch(node->m_pLeftNode, s, sTarget, d, q);
		}
		else if (node->m_c < c)
		{
			KeysThatMatch(node->m_pRightNode, s, sTarget, d, q);
		}
		else
		{
			sTarget += node->m_c;
			if (d == s.length() - 1)
			{
				if (node->m_pValue != 0)
				{
					q.Enqueue(sTarget);
				}
			}
			else
			{
				KeysThatMatch(node->m_pMidNode, s, sTarget, d + 1, q);
			}
		}
	}
	return;
}

template<typename T>
void TST<T>::Collect(TNode<T>* node, string sTarget, Queue<string>& q)
{
	if (node == 0)
	{
		return;
	}
	Collect(node->m_pLeftNode, sTarget, q);
	Collect(node->m_pRightNode, sTarget, q);
	sTarget += node->m_c;
	if (node->m_pValue != 0)
	{
		q.Enqueue(sTarget);
	}
	Collect(node->m_pMidNode, sTarget, q);
	return;
}