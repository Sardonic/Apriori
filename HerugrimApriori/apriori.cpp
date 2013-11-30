#include <iostream>
#include "dataset.h"
#include "itemset.h"
using namespace std;

void ItemsetStub();
void DatasetPopulateStub();

int main()
{
	//ItemsetStub();
	DatasetPopulateStub();

	/*
	Dataset mainData = Dataset();

	string fileName, junk;

	cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
	getline(cin, fileName);

	while(mainData.getSpecifications(fileName) == false)
	{
		cout << "~Error: Invalid File Name~\n";
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);
	}
	*/

	return 0;
} 

void ItemsetStub()
{
	Itemset one_itemset(1);

	cout << "Made a one-itemset" << endl;

	cout << "Adding 3 to itemset" << endl;
	one_itemset.addItem(3);

	Item first_item;
	cout << "Getting first item." << endl;
	cout << "Returned " << one_itemset.getItem(0, first_item) << "." << endl;
	cout << "First item is: " << first_item << endl;

	Itemset two_itemset(2);

	cout << "Made a two-itemset" << endl;

	cout << "Adding 5 to itemset" << endl;
	two_itemset.addItem(5);

	cout << "Getting first item." << endl;
	cout << "Returned " << two_itemset.getItem(0, first_item) << "." << endl;
	cout << "First item is " << first_item << endl;

	cout << "Adding 8 to itemset" << endl;
	two_itemset.addItem(8);

	cout << "Getting first item." << endl;
	cout << "Returned " << two_itemset.getItem(0, first_item) << "." << endl;
	cout << "First item is " << first_item << endl;

	Item second_item;

	cout << "Getting second item." << endl;
	cout << "Returned " << two_itemset.getItem(1, second_item) << "." << endl;
	cout << "Second item is " << second_item << endl;

	cout << two_itemset << endl;

	string junk;

	cout << "Test complete. Press enter to continue." << endl;
	getline(cin, junk);
}

void DatasetPopulateStub()
{
	Dataset tempDataset;

	string fileName;
	cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
	getline(cin, fileName);

	while(tempDataset.getSpecifications(fileName) == false)
	{
		cout << "~Error: Invalid File Name~\n";
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);
	}

	tempDataset.populateArray(fileName);
	tempDataset.printArray();

	string junk;
	cout << "Test complete. Press enter to continue." << endl;
	getline(cin, junk);
}