#pragma once
#include <string>
using std::string;
class LSD
{
public:
	static void Sort(string* pData, int nSize, int nLength);
};

void LSD::Sort(string* pData, int nSize, int nLength)
{
	const int R = 256;
	int* pCount = new int[R+1];
	string* pAux = new string[nSize];
	for (int i = nLength - 1; i >= 0; i--)
	{
		memset(pCount, 0, (R+1) * sizeof(int));
		for (int j = 0; j < nSize; j++)
		{
			pCount[pData[j].at(i) + 1]++;
		}
		for (int j = 0; j < R; j++)
		{
			pCount[j + 1] += pCount[j];
		}
		for (int j = 0; j < nSize; j++)
		{
			pAux[pCount[pData[j].at(i)]++] = pData[j];
		}
		for (int j = 0; j < nSize; j++)
		{
			pData[j] = pAux[j];
		}
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