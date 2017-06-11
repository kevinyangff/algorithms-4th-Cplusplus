#pragma once
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
using std::wstring;
using std::vector;

#define MAX_CHAR_VALUE (65536)
class Alphabet
{
public:
	Alphabet(wstring& s);
	unsigned short ToChar(int index);
	int ToIndex(unsigned short c);
	bool Contains(unsigned short c);
	int R();
	int LgR();
	vector<int> ToIndices(wstring& s);
	wstring ToChars(vector<int>& indices);
private:
	int m_nSize;
	unsigned short* m_pChar;
	int* m_pIndex;
};

Alphabet::Alphabet(wstring& s)
{
	m_nSize = s.size();
	m_pChar = new unsigned short[m_nSize];
	m_pIndex = new int[MAX_CHAR_VALUE];
	for (int i = 0; i < MAX_CHAR_VALUE; i++)
	{
		m_pIndex[i] = -1;
	}
	for (int i = 0; i < m_nSize; i++)
	{
		m_pChar[i] = s.at(i);
		m_pIndex[m_pChar[i]] = i;
	}
}

unsigned short Alphabet::ToChar(int index)
{
	assert(index >= 0 && index < m_nSize);
	return m_pChar[index];
}

int Alphabet::ToIndex(unsigned short c)
{
	return m_pIndex[c];
}
bool Alphabet::Contains(unsigned short c)
{
	return m_pIndex[c] != -1;
}
int Alphabet::R()
{
	return m_nSize;
}
int Alphabet::LgR()
{
	return ceil(log2(m_nSize));
}
vector<int> Alphabet::ToIndices(wstring& s)
{
	vector<int> vRet;
	for (int i = 0; i < s.size(); i++)
	{
		vRet.push_back(m_pIndex[s.at(i)]);
	}
	return vRet;
}
wstring Alphabet::ToChars(vector<int>& indices)
{
	wstring sRet;
	for (int i = 0; i < indices.size(); i++)
	{
		sRet.append(1, (wchar_t)m_pChar[indices.at(i)]);
	}
	return sRet;
}