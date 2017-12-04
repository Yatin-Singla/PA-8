#include "BST.h"

BST::~BST()
{
	DestroyTree(mpRoot);
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


void BST::DestroyTree(BaseNode * pRoot)
{
	if (pRoot != nullptr)
	{
		if (pRoot->getpLeft() != nullptr)
		{
			DestroyTree(pRoot->getpLeft());
		}
		else if (pRoot->getpLeft() == nullptr && pRoot->getpRight() != nullptr)
		{
			DestroyTree(pRoot->getpRight());
		}

		delete pRoot;
	}
	return;
}

void BST::insert(BaseNode *& pT, TransactionNode *& newNode)
{
	if (newNode->getUnits() < (dynamic_cast<TransactionNode*>(pT)->getUnits()))
	{
		if (pT->getpLeft() == nullptr)
		{
			pT->setpLeft(newNode);
		}
		else
		{
			insert(pT->getpLeft(), newNode);
		}
	}
	// if (NewNode->getEnglishChar() > pRoot->getEnglishChar())
	else
	{
		if (pT->getpRight() == nullptr)
		{
			pT->setpRight(newNode);
		}
		else
		{
			insert(pT->getpRight(), newNode);
		}
	}
	return;
}

//yet to define 
void BST::inOrderTraversal(BaseNode * pRoot)
{
	if (pRoot->getpLeft() != nullptr)
	{
		inOrderTraversal(pRoot->getpLeft());
	}
	pRoot->printData();
	if (pRoot->getpRight() != nullptr)
	{
		inOrderTraversal(pRoot->getpRight());
	}
	return;
}