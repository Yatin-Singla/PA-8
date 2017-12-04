#include "TransactionNode.h"

//explicitly invoking BaseNode's constructor
TransactionNode::TransactionNode(string newData, int newUnits) :BaseNode(newData)
{
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{}

int TransactionNode::getUnits(void)
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

//pure virtual in base class
//yet to define
void TransactionNode::printData(void)
{
	cout << mUnits << " units of " << mData << "\n";
}