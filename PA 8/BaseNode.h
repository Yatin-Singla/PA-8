#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BaseNode
{
public:
	//virtual destructor, each derived class might/ might not have the declaration for the their respective deconstructor
	virtual ~BaseNode();
	BaseNode(string newString = "");

	//getters
	string getData(void);
	BaseNode *& getpLeft(void);
	BaseNode *& getpRight(void);

	//setters
	void setData(string newData);
	void setpLeft(BaseNode * newpLeft);
	void setpRight(BaseNode * newpRight);

	//pure virtual, class is abstract and every derived class must have its own declaration of destructor
	virtual void printData(void) = 0;

protected:
	string mData;
	BaseNode * mpLeft;
	BaseNode * mpRight;
};