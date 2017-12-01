#include "BST.h"

BST::~BST()
{
	DestroyTree();
}

BST::BST()
{
	mpRoot = nullptr;
}

BaseNode * BST::getpRoot(void)
{
	return mpRoot;
}

void BST::setpRoot(BaseNode * newNode)
{
	mpRoot = newNode;
}

void BST::insert(int Units, string Type)
{
	TransactionNode * newNode = new TransactionNode(Type, Units);
	insert(mpRoot, newNode);
}

void BST::inOrderTraversal(void)
{
	inOrderTraversal(mpRoot);
}

//yet to define
TransactionNode * BST::findSmallest(void)
{
	TransactionNode * pMem = dynamic_cast<TransactionNode*>(mpRoot);
	if (mpRoot != nullptr)
	{
		while (pMem->getpLeft() != nullptr)
		{
			pMem = dynamic_cast<TransactionNode*>(pMem->getpLeft());
		}//found the item which is least sold/purchased
	}
	return pMem;
}

//yet to define
TransactionNode * BST::findLargest(void)
{
	TransactionNode * pMem = dynamic_cast<TransactionNode*>(mpRoot);
	if (pMem != nullptr)
	{
		while (pMem->getpRight() != nullptr)
		{
			pMem = dynamic_cast<TransactionNode*>(pMem->getpRight());
		}
	}
	return pMem;
}

//yet to define
void BST::DestroyTree(void)
{

}

//yet to define
void BST::insert(BaseNode *& pT, TransactionNode *& newNode)
{

}

//yet to define 
void BST::inOrderTraversal(BaseNode * pRoot)
{

}
