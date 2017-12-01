#pragma once
#include "BaseNode.h"

class TransactionNode : public BaseNode
{
public:
	TransactionNode(string newData = "", int newUnits = 0);
	~TransactionNode();

	//getter 
	int getUnits(void);
	//setter
	void setUnits(int newUnits);
	void printData(void);
private:
	int mUnits;
};