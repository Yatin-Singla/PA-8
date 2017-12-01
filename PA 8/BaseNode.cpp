#include "BaseNode.h"

BaseNode::BaseNode(string newString)
{
	mData = newString;
}

BaseNode::~BaseNode()
{}

string BaseNode::getData(void)
{
	return mData;
}

BaseNode *& BaseNode::getpLeft(void)
{
	return mpLeft;
}

BaseNode *& BaseNode::getpRight(void)
{
	return mpRight;
}

void BaseNode::setData(string newData)
{
	mData = newData;
}

void  BaseNode::setpLeft(BaseNode*newpLeft)
{
	mpLeft = newpLeft;
}

void BaseNode::setpRight(BaseNode * newpRight)
{
	mpRight = newpRight;
}
