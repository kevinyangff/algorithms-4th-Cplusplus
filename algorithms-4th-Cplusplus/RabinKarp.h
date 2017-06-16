#pragma once
#include <string>
using std::string;
//only Monte Carlo version
//no Las Vegas version
class RabinKarp
{
public:
	RabinKarp(int R, string pat);
	int Search(string txt);
private:
	unsigned long long Hash(string s, int M);
private:
	unsigned long long int m_q;
	int m_R;
	unsigned long long int m_patHash;
	unsigned long long int m_RM;
	string m_pat;
};

RabinKarp::RabinKarp(int R, string pat) :m_R(R), m_q(18446744073709551557), m_patHash(0), m_RM(1), m_pat(pat)
{
	int M = pat.size();
	for (int i = 1; i < M; i++)
	{
		m_RM = R*m_RM % m_q;
	}
	m_patHash = Hash(pat, M);
}

int RabinKarp::Search(string txt)
{
	int M = m_pat.size();
	int N = txt.size();
	if (N < M)	return N;
	unsigned long long txtHash = Hash(txt, M);
	if (txtHash == m_patHash)	return 0;
	for (int i = M; i < N; i++)
	{
		txtHash = (txtHash/* + m_q*/ - (txt.at(i - M)*m_RM) % m_q) % m_q;//because 18446744073709551557 is the biggest prime that is not overflowed, so,can't add a m_q
		txtHash = ((txtHash*m_R)%m_q + txt.at(i)) % m_q;
		if (txtHash == m_patHash)
		{
			return i - M + 1;
		}
	}
	return N;
}

unsigned long long RabinKarp::Hash(string s, int M)
{
	unsigned long long hash = 0;
	for (int i = 0; i < M; i++)
	{
		hash = (hash*m_R + s.at(i)) % m_q;
	}
	return hash;
}

