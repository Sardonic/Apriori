/********
*	Team: Herugrim
*	Authors: David Johnston, Scott Barrett, Jack Storm
*	Tester: Wangchuk Zigmyal
*	Class: CSI-281-01
*	Assignment: Apriori
*	Date Assigned: Monday, November 11th, 2013
*	Date Due: 17:00 EST, Friday, December 6, 2013
*	Description: Implement the apriori algorithm using data structures 
*				 learned in class
*	Certification of Authenticy: We hearby certify that this assignment is our own work
********/

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
	double time = 0;

	char continueGenerating = 'y';

	while(continueGenerating == 'y' || continueGenerating == 'Y')
	{
		Dataset mainData;
		string fileName;
	
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);

		while(mainData.getSpecifications(fileName) == false)
		{
			cout << "~Error: Invalid File Name~\n";
			cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
			getline(cin, fileName);
		}

		double threshold = 0;

		while(threshold <= 0 || threshold > 1)
		{
			cout << "Enter the desired minimum support threshold, between 1 and 0. \n(1 = 100% and 0 = 0%)\n";
			cin >> threshold;

			cin.clear();
			cin.ignore(100, '\n');
		}

		string outFileName;
		cout << "Enter the desired output file name (no .txt extension, please): ";
		getline(cin, outFileName);
		ofstream outFile(outFileName + ".txt");

		mainData.populateArray(fileName);

		cout << "Generating itemsets..." << endl << endl;

		timer.startClock();
		mainData.generateAllItemsets(threshold, outFile);
		time = timer.getTime();

		cout << "Finished in " << time << " seconds.\n\n\n";

		continueGenerating = NULL;
		while(continueGenerating != 'y' && continueGenerating != 'Y' && continueGenerating != 'n' && continueGenerating != 'N')
		{
			cout << "Would you like to generate another itemset? y/n\n";
			cin >> continueGenerating;

			cin.clear();
			cin.ignore(100, '\n');
		}

		outFile.close();
	}

	string junk;
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

	//tempDataset.generateAllItemsets(0.025);
	//tempDataset.generateItemset(5, 0.5);

	string junk;
	cout << "Test complete. Press enter to continue." << endl;
	getline(cin, junk);
}