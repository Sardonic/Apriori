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

#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include "itemsetHolder.h"


#include "itemset.h"
#include "linkedList.h"
#include "timerSystem.h"

using namespace std;

class Dataset
{
	public:
		Dataset();
		~Dataset();

		inline int Dataset::getTransactions(){return mNumTransactions;}
		inline int Dataset::getTotalItems(){return mNumTotalItems;}

		void allocateArrayMemory();
		bool getSpecifications(string inputFileName);
		void generateAllItemsets(double supportThreshold, ostream& outStream);
		void generateItemset(int itemSet, double supportThreshold, ostream& outStream);
		void populateArray(string fileName);
		void printArray(ostream& os);

	private:
		LinkedList<ItemsetHolder*> mAllItemsets;
		int** mDataArray;
		int mNumTransactions;
		int mNumTotalItems;
		int mNumItemsets;
		TimerSystem mTimer;

		void generateItemsetRecur(int recursionIterator, int itemSet, int loopsLeft, double supportThreshold, int* setArray, ItemsetHolder& holder);
};


#endif