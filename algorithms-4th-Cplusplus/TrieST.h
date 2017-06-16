#pragma once
#include "Queue.h"
#include <string>
#include "TrieNode.h"

using std::string;
template<typename T>
class TrieST
{
public:
	TrieST(int R);
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
	TrieNode<T>* Put(TrieNode<T>* node, string key, T value, int d);
	TrieNode<T>* Get(TrieNode<T>* node, string key, int d);
	TrieNode<T>* Delete(TrieNode<T>* node, string key, int d);
	void Collect(TrieNode<T>* node, string sTarget, Queue<string>& q);
	void KeysThatMatch(TrieNode<T>* node, string s, string sTarget, int d, Queue<string>& q);
	void LongestPrefixOf(TrieNode<T>* node, string s, int d, int& n);
private:
	TrieNode<T>* m_root;
	int m_R;
	int m_nSize;
};

template<typename T>
TrieST<T>::TrieST(int R) :m_R(R), m_nSize(0)
{
	m_root = 0;
}

template<typename T>
void TrieST<T>::Put(string key, T value)
{
	m_root = Put(m_root, key, value, 0);
}

template<typename T>
TrieNode<T>* TrieST<T>::Put(TrieNode<T>* node, string key, T value, int d)
{
	if (node == 0)
	{
		node = new TrieNode<T>(m_R);
	}
	if (d == key.length())
	{
		if(node->m_pValue != 0)
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
	char c = key.at(d);
	node->m_ppNode[c] = Put(node->m_ppNode[c], key, value, d + 1);
	return node;
}

template<typename T>
T TrieST<T>::Get(string key)
{
	TrieNode<T>* node = Get(m_root, key, 0);
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
TrieNode<T>* TrieST<T>::Get(TrieNode<T>* node, string key, int d)
{
	if (node == 0) return 0;
	if (d == key.length())
	{
		return node;
	}
	char c = key.at(d);
	return Get(node->m_ppNode[c], key, d+1);
}

template<typename T>
void TrieST<T>::Delete(string key)
{
	m_root = Delete(m_root, key, 0);
}

template<typename T>
TrieNode<T>* TrieST<T>::Delete(TrieNode<T>* node, string key, int d)
{
	if (node == 0) return 0;
	if (d == key.length())
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
		char c = key.at(d);
		node->m_ppNode[c] = Delete(node->m_ppNode[c], key, d + 1);
	}
	if (node->m_pValue != 0)
	{
		return node;
	}
	for (int i = 0; i < m_R; i++)
	{
		if (node->m_ppNode[i] != 0)
		{
			return node;
		}
	}
	delete node;
	return 0;
}

template<typename T>
bool TrieST<T>::Contains(string key)
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
bool TrieST<T>::IsEmpty()
{
	return m_root == 0;
}

template<typename T>
int TrieST<T>::Size()
{
	return m_nSize;
}

template<typename T>
Queue<string> TrieST<T>::Keys()
{
	return KeysWithPrefix("");
}

template<typename T>
string TrieST<T>::LongestPrefixOf(string s)
{
	int n = 0;
	LongestPrefixOf(m_root, s, 0, n);
	return s.substr(0, n);
}

template<typename T>
void TrieST<T>::LongestPrefixOf(TrieNode<T>* node, string s, int d, int& n)
{
	if (node == 0) return;
	if (node->m_pValue != 0)
	{
		n = d;
	}
	if (d != s.length())
	{
		char c = s.at(d);
		LongestPrefixOf(node->m_ppNode[c], s, d + 1, n);
	}
	return;
}

template<typename T>
Queue<string> TrieST<T>::KeysWithPrefix(string s)
{
	Queue<string> q;
	TrieNode<T>* node = Get(m_root, s, 0);
	Collect(node, s, q);
	return q;
}

template<typename T>
Queue<string> TrieST<T>::KeysThatMatch(string s)
{
	Queue<string> q;
	KeysThatMatch(m_root, s, "", 0, q);
	return q;
}

template<typename T>
void TrieST<T>::KeysThatMatch(TrieNode<T>* node, string s, string sTarget, int d, Queue<string>& q)
{
	if (node == 0)	return;
	if (d == s.length())
	{
		if (node->m_pValue != 0)
		{
			q.Enqueue(sTarget);
		}
		return;
	}
	char c = s.at(d);
	if(c == '.')
	{
		for (int i = 0; i < m_R; i++)
		{
			KeysThatMatch(node->m_ppNode[i], s, sTarget + (char)i, d + 1, q);
		}
	}
	else
	{
		KeysThatMatch(node->m_ppNode[c], s, sTarget + c, d + 1, q);
	}
	return;
}

template<typename T>
void TrieST<T>::Collect(TrieNode<T>* node, string sTarget, Queue<string>& q)
{
	if (node == 0)
	{
		return;
	}
	if (node->m_pValue != 0)
	{
		q.Enqueue(sTarget);
	}
	for (int i = 0; i < m_R; i++)
	{
		Collect(node->m_ppNode[i], sTarget +(char)i, q);
	}
	return;
}