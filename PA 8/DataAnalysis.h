#pragma once
#include "BST.h"

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis(void);

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCSVstream;
	void OpenFile(void);
	void ReadSplit(int * Units, string & Type, string & TransactionField);
	void Loop(void);
	void CompareTF(int Units, string Type, string Description);
	void displayTree(void);

};