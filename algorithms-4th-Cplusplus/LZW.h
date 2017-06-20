#pragma once
#include "TrieST.h"
#include "bitstream.h"
#include <string>
using std::string;
class LZW
{
public:
	static string Compress(string);
	static string Expand(string);
private:
	static void WriteWbit(ostringbitstream& obits, unsigned short n);
	static void ReadWbit(istringbitstream& ibits, unsigned short& n);
private:
	static const int R;
	static const int W;
	static const int L;
};

const int LZW::R = 256;
const int LZW::W = 12;
const int LZW::L = 4096;

string LZW::Compress(string s)
{
	string result;
	TrieST<int> trie(R);
	int i = 0;
	for (i = 0; i < R; i++)
	{
		trie.Put(string("") + (char)i, i);
	}
	i++;/*skip 0x80 for EOF*/
	ostringbitstream obits;
	while (s.length() != 0)
	{
		string pre = trie.LongestPrefixOf(s);
		unsigned short nTemp = (unsigned short)trie.Get(pre);
		WriteWbit(obits, nTemp);
		s = s.substr(pre.length());
		if(s.length() != 0 && i < L)
		{
			trie.Put(pre + s.at(0), i++);
		}
	}
	WriteWbit(obits, 0x0080);
	result = obits.str();
	return result;
}
string LZW::Expand(string s)
{
	string result;
	string* pString = new string[L];
	int i = 0;
	for (i; i < R; i++)
	{
		pString[i] = string("") + (char)i;
	}
	i++;
	istringbitstream ibits(s);
	unsigned short nTemp = 0;
	ReadWbit(ibits, nTemp);
	string val = pString[nTemp];
	while (true)
	{
		result += val;
		nTemp = 0;
		ReadWbit(ibits, nTemp);
		if (nTemp == 0x80) break;
		string s;
		if (nTemp == i)
		{
			s = val + val.at(0);
		}
		else
		{
			s = pString[nTemp];
		}
		if (i < L)
		{
			pString[i++] = val + s.at(0);
		}
		val = s;
	}
	return result;
}

void LZW::WriteWbit(ostringbitstream& obits, unsigned short n)
{
	for (int i = W-1; i >=0; i--)
	{
		unsigned short b = ((1 << i)&n)==0?0:1;
		obits.writeBit(b);
	}
}
void LZW::ReadWbit(istringbitstream& ibits, unsigned short& n)
{
	for (int i = W - 1; i >= 0; i--)
	{
		n += ibits.readBit() << i;
	}
}