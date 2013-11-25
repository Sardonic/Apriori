#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <fstream>
#include "queue.h"

using namespace std;

class Dataset
{
	public:
		Dataset();
		~Dataset();

		bool getSpecifications(string inputFileName);
		void generateItemSet(int itemSet, float supportThreshold);
		void populateArray(string fileName);
	private:
		int** mDataArray;
		int mNumTransactions;
		int mNumTotalItems;
};


#endif