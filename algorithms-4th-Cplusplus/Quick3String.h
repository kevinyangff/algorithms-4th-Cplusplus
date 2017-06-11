#pragma once
#include <assert.h>
#include <iostream>
#include "InsertionSort.h"
using namespace std;

class Quick3String
{
public:
	static void Sort(string* pData, int nSize);
private:
	static void Sort(string* pData, int lo, int hi, int d);
	static char GetChar(string& s, int d);
	static void Exch(string* pData, int i, int j);
};



void Quick3String::Sort(string* pData, int nSize)
{
	Sort(pData, 0, nSize - 1, 0);
}


void Quick3String::Sort(string* pData, int lo, int hi, int d)
{
	if (lo >= hi)
	{
		return;
	}
	int lt = lo;
	int i = lo + 1;
	int gt = hi;
	char temp = GetChar(pData[lo], d);
	while (i <= gt)
	{
		if (GetChar(pData[i], d) < temp)
		{
			Exch(pData, lt++, i++);
		}
		else
		{
			if (GetChar(pData[i], d) > temp)
			{
				Exch(pData, i, gt--);
			}
			else
			{
				i++;
			}
		}
	}
	Sort(pData, lo, lt - 1, d);
	if(temp>0)	Sort(pData, lt, gt, d+1);
	Sort(pData, gt + 1, hi, d);
}

char Quick3String::GetChar(string& s, int d)
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

void Quick3String::Exch(string* pData, int i, int j)
{
	string s = pData[i];
	pData[i] = pData[j];
	pData[j] = s;
}
