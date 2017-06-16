#pragma once
#include <string>
using std::string;
class KMP
{
public:
	KMP(int R, string pat);
	~KMP();
	int Search(string txt);
private:
	int m_R;
	int** m_dfa;
	string m_pat;
};

KMP::KMP(int R, string pat) :m_R(R), m_pat(pat), m_dfa(0)
{
	int nSize = pat.size();
	if (R != 0 && nSize != 0)
	{
		m_dfa = new int*[R];
		for (int i = 0; i < R; i++)
		{
			m_dfa[i] = new int[nSize]();
		}
	}
	m_dfa[m_pat.at(0)][0] = 1;
	int X = 0;
	for (int i = 1; i < nSize; i++)
	{
		for (int c = 0; c < R; c++)
		{
			m_dfa[c][i] = m_dfa[c][X];
		}
		m_dfa[m_pat[i]][i] = i + 1;
		X = m_dfa[m_pat[i]][X];
	}
}

KMP::~KMP()
{
	if (m_dfa != 0)
	{
		for (int i = 0; i < m_R; i++)
		{
			delete [] m_dfa[i];
		}
		delete [] m_dfa;
		m_dfa = 0;
	}
}

int KMP::Search(string txt)
{
	int N = txt.size();
	int M = m_pat.size();
	int j = 0;
	int i = 0;
	for (i = 0, j = 0; i < N, j < M; i++)
	{
		j = m_dfa[txt.at(i)][j];
	}
	if (j == M)
	{
		return i - M;
	}
	return N;
}