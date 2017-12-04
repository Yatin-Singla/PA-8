#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	OpenFile();
}

DataAnalysis::~DataAnalysis()
{
	mCSVstream.close();
}

void DataAnalysis::OpenFile(void)
{
	if (mCSVstream.is_open() == false)
	{
		mCSVstream.open("data.csv");
	}
}

void DataAnalysis::runAnalysis(void)
{
	Loop();
}

void DataAnalysis::ReadSplit(int * Units, string & Type, string & TransactionField)
{
	if (mCSVstream.is_open() != false)//file is open to read
	{
		char Characters[50] = { '\0' };
		mCSVstream.getline(Characters, 50);//discarded 1st line
		mCSVstream.getline(Characters, 50, ',');
		*Units = atoi(Characters);
		mCSVstream.getline(Characters, 50, ',');
		Type = Characters;
		mCSVstream.getline(Characters, 50, '\n');
		TransactionField = Characters;
	}
}

void DataAnalysis::Loop(void)
{
	int Units = 0;
	string  Type = "", TransactionField = "";
		if (mCSVstream.is_open() == true)
	{
			while (mCSVstream.eof() != true)
		{
			ReadSplit(&Units, Type, TransactionField);
			CompareTF(Units, Type, TransactionField);
		}
		displayTree();
	}
}

void DataAnalysis::CompareTF(int Units, string Type, string TransactionField)
{
	if (TransactionField == "Sold")
	{
		mTreeSold.insert(Units, Type);
	}
	else if (TransactionField == "Purchased")
	{
		mTreePurchased.insert(Units, Type);
	}
}

void DataAnalysis::displayTree(void)
{
	cout << "\n\nTree of Purchased Items:\n";
	mTreePurchased.inOrderTraversal();
	cout << "\n\nTree of Sold Items:\n";
	mTreeSold.inOrderTraversal();

	cout << "\n\n\n\n Purchased Item: ";
	cout << (mTreePurchased.findLargest())->getData() << "\n"; //writes the type
	cout << "Units Purchased: " << (mTreePurchased.findLargest())->getUnits() << "\n\n";//displays Units
	cout << "Purchased Item: ";
	cout << (mTreePurchased.findSmallest())->getData() << "\n"; //writes the type
	cout << "Units Purchased: " << (mTreePurchased.findSmallest())->getUnits() << "\n\n\n\n";//displays Units
	cout << "Sold Item : ";
	cout << (mTreeSold.findLargest())->getData() << "\n";//writes the type
	cout << "Units Sold: ";
	cout << (mTreeSold.findLargest())->getUnits() << "\n";//displays Units
	cout << "Sold Item: ";
	cout << (mTreeSold.findSmallest())->getData() << "\n";//writes the type
	cout << (mTreeSold.findSmallest())->getUnits() << "\n";//displays the units
}