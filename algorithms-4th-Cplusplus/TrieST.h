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
	TrieNode* Put(TrieNode* node, string key, T value, int d);
	TrieNode* Get(TrieNode* node, string key, int d);
	TrieNode* Delete(TrieNode* node, string key, int d);
	void Collect(TrieNode* node, Queue<string>& q);
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
TrieNode* TrieST<T>::Put(TrieNode* node, string key, T value, int d)
{
	if (node == 0)
	{
		node = new TrieNode(m_R);
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
	return Put(node->m_ppNode[c], key, value, d + 1);
}

template<typename T>
T TrieST<T>::Get(string key)
{
	TrieNode* node = Get(m_root, key, 0);
	if (node == 0) throw 0;
	if (node.m_pValue != 0)
	{
		return *(node->m_pValue);
	}
	else
	{
		throw 0;
	}
}

template<typename T>
TrieNode* TrieST<T>::Get(TrieNode* node, string key, int d)
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
TrieNode* TrieST<T>::Delete(TrieNode* node, string key, int d)
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
		node = Delete(node->m_ppNode[c], key, d + 1);
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
		this->Get(key)
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
	Queue<string> q;
	Collect(m_root, q);
	return q;
}

template<typename T>
string TrieST<T>::LongestPrefixOf(string s);

template<typename T>
Queue<string> TrieST<T>::KeysWithPrefix(string s)
{
	Queue<string> q;
	TrieNode* node = Get(m_root, s, 0);
	if (node != 0 && node->m_pValue != 0)
	{
		Collect(node, q);
	}
	return q;
}

template<typename T>
Queue<string> TrieST<T>::KeysThatMatch(string s);

template<typename T>
void TrieST<T>::Collect(TrieNode* node, Queue<string>& q);