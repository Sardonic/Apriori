#include <iostream>
#include "dataset.h"
#include "timerSystem.h"
using namespace std;

void ItemsetStub();
void DatasetPopulateStub();
void AllItemsetStub();

#define DEBUG_FILENAME "testfile"

int main()
{
	//ItemsetStub();
	//DatasetPopulateStub();
	//AllItemsetStub();

	TimerSystem timer;
	Dataset mainData = Dataset();
	double time = 0;
	

	string fileName, junk;

	cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
	getline(cin, fileName);

	while(mainData.getSpecifications(fileName) == false)
	{
		cout << "~Error: Invalid File Name~\n";
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);
	}

	mainData.populateArray(fileName);

	cout << "Checking 0.25% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.0025);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-0.25threshold.txt");

	
	mainData.populateArray(fileName);

	
	cout << "Checking 0.5% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.005);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-0.5threshold.txt");

	
	mainData.populateArray(fileName);

	cout << "Checking 1% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.01);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-1threshold.txt");

	
	mainData.populateArray(fileName);

	cout << "Checking 2.5% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.025);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-2.5threshold.txt");

	
	mainData.populateArray(fileName);

	cout << "Checking 10% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.1);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-10threshold.txt");

	
	mainData.populateArray(fileName);

	cout << "Checking 25% threshold..." << endl << endl;

	timer.startClock();
	mainData.generateAllItemsets(0.25);
	time = timer.getTime();

	cout << "Finished in " << time << " seconds.";

	mainData.writeToFile(fileName + "-25threshold.txt");

	cout << endl << "Press enter to continue..." << endl;
	getline(cin, junk);

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
	tempDataset.printArray(cout);

	string junk;
	cout << "Test complete. Press enter to continue." << endl;
	getline(cin, junk);
}

void AllItemsetStub()
{
	Dataset tempDataset;

	string fileName;
	//cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
	//getline(cin, fileName);
	
	while(tempDataset.getSpecifications(DEBUG_FILENAME) == false)
	{
		cout << "~Error: Invalid File Name~\n";
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);
	}

	tempDataset.populateArray(DEBUG_FILENAME);
	//tempDataset.printArray();

	tempDataset.generateAllItemsets(0.025);
	//tempDataset.generateItemset(5, 0.5);

	tempDataset.printItemsets(cout);

	string junk;
	cout << "Test complete. Press enter to continue." << endl;
	getline(cin, junk);
}