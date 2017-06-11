#pragma once
#include <string>
using std::string;
class MSD
{
public:
	static void Sort(string* pData, int nSize);
private:
	static void Sort(string* pData, int lo, int hi, int d);
	static char GetChar(string& s, int d);
};

void MSD::Sort(string* pData, int nSize)
{
	Sort(pData, 0, nSize-1, 0);
}
void MSD::Sort(string* pData, int lo, int hi, int d)
{
	//should use insertion sort actually if hi-li==a fit number 
	if (lo >= hi)
	{
		return;
	}
	const int R = 256;
	int* pCount = new int[R + 2];
	string* pAux = new string[hi-lo+1];
	memset(pCount, 0, (R + 2) * sizeof(int));
	for (int i = lo; i <= hi; i++)
	{
		pCount[GetChar(pData[i], d) + 2]++;
	}
	for (int i = 0; i < R+1; i++)
	{
		pCount[i + 1] += pCount[i];
	}
	for (int i = lo; i <= hi; i++)
	{
		pAux[pCount[GetChar(pData[i],d)+1]++] = pData[i];
	}
	for (int i = lo; i <= hi; i++)
	{
		pData[i] = pAux[i - lo];
	}
	for (int i = 0; i < R; i++)
	{
		Sort(pData, lo+pCount[i], lo+pCount[i + 1] - 1, d+1);
	}
	if (pCount)
	{
		delete[] pCount;
	}
	if (pAux)
	{
		delete[] pAux;
	}
}
char MSD::GetChar(string& s, int d)
{
	if (s.size() <= d)
	{
		return (char)-1;
	}
	else
	{
		return s.at(d);
	}
}