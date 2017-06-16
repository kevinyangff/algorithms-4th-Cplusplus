#pragma once
#include <string>
using std::string;
class BoyerMoore
{
public:
	BoyerMoore(int R, string pat);
	~BoyerMoore();
	int Search(string txt);
private:
	int m_R;
	string m_pat;
	int* m_pRight;
};

BoyerMoore::BoyerMoore(int R, string pat) :m_R(R), m_pat(pat), m_pRight(0)
{
	int nSize = pat.size();
	m_pRight = new int[R];
	for (int c = 0; c < R; c++)
	{
		m_pRight[c] = -1;
	}
	for (int i = 0; i < nSize; i++)
	{
		m_pRight[m_pat.at(i)] = i;
	}
}
BoyerMoore::~BoyerMoore()
{
	if (m_pRight)
	{
		delete[] m_pRight;
		m_pRight = 0;
	}
}
int BoyerMoore::Search(string txt)
{
	int M = m_pat.size();
	int N = txt.size();
	for (int i = M - 1; i < N; )
	{
		int nTemp = i;
		for (int j = M - 1; j >= 0; j--)
		{
			if (m_pat.at(j) == txt.at(nTemp))
			{
				nTemp--;
			}
			else
			{
				if (m_pRight[txt.at(nTemp)] == -1)
				{
					i += M-(i-nTemp);
				}
				else if (m_pRight[m_pat.at(j)] - m_pRight[txt.at(nTemp)] < 0)
				{
					i++;
				}
				else
				{
					i += m_pRight[m_pat.at(j)] - m_pRight[txt.at(nTemp)];
				}
				break;
			}
			if (j == 0)
			{
				return i - M + 1;
			}
		}
	}
	return N;
}