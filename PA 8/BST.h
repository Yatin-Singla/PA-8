#pragma once
#include "TransactionNode.h"

class BST
{
public:
	~BST();
	BST();
	BaseNode * getpRoot(void);
	void setpRoot(BaseNode * newRoot);
	void insert(int Units, string Type);
	void inOrderTraversal(void);
	TransactionNode * findSmallest(void);
	TransactionNode * findLargest(void);
private:
	BaseNode * mpRoot;
	void DestroyTree(BaseNode * pRoot);
	void insert(BaseNode *& pT, TransactionNode *& newNode);
	void inOrderTraversal(BaseNode * pRoot);

};

