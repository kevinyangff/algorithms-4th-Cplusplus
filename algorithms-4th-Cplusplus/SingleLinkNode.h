#pragma once
template<typename KEY, typename VALUE>
class SingleLinkNode
{
public:
	SingleLinkNode(KEY k, VALUE v);
public:
	KEY k;
	VALUE v;
	SingleLinkNode* next;
};

template<typename KEY, typename VALUE>
SingleLinkNode<KEY, VALUE>::SingleLinkNode(KEY k, VALUE v)
{
	this->k = k;
	this->v = v;
	this->next = 0;
}