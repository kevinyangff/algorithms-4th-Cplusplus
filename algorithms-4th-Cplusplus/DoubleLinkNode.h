#pragma once
template<typename KEY, typename VALUE>
class DoubleLinkNode
{
public:
	DoubleLinkNode(KEY k, VALUE v);
public:
	KEY k;
	VALUE v;
	DoubleLinkNode* left;
	DoubleLinkNode* right;
	int N;
};

template<typename KEY, typename VALUE>
DoubleLinkNode<KEY, VALUE>::DoubleLinkNode(KEY k, VALUE v):N(1)
{
	this->k = k;
	this->v = v;
	this->left = 0;
	this->right = 0;
}