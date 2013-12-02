#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include "itemsetHolder.h"
#include "itemset.h"
#include "linkedList.h"

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
		void generateItemSet(int itemSet, double supportThreshold);
		void populateArray(string fileName);
		void printArray();

	private:
		LinkedList<ItemsetHolder*> mAllItemsets;
		int** mDataArray;
		int mNumTransactions;
		int mNumTotalItems;

		void generateItemsetRecur(int recursionIterator, int itemSet, int loopsLeft, double supportThreshold, int* setArray, ItemsetHolder& holder);
};


#endif