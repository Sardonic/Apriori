#include "dataset.h"

//Pre: None
//Post: None
//Purpose: default constructor
//**********************************************************************
Dataset::Dataset(){}

//Pre: None
//Post: None
//Purpose: deletes the mDataArray
//**********************************************************************
Dataset::~Dataset()
{

	for(int i = 0; i < mNumTransactions; i++)
	{
		delete [] mDataArray[i];
	}

	delete [] mDataArray;
}

//Pre: inputFileName name has been instantiated;
//Post: returns false if file not found, returns true if file is found
//Purpose: retrives the total number of distinct items and transactions
//**********************************************************************
bool Dataset::getSpecifications(string inputFileName)
{
	int junk, numItems, numTrans;
	//string fullName = inputFileName + ".input";
	ifstream inputFile = ifstream(inputFileName + ".input");

	if(!inputFile.good())
	{
		inputFile.close();
		return false;
	}
	else
	{
		inputFile >> junk;
		inputFile >> numItems;
		inputFile >> numTrans;
		inputFile.close();

		mNumTotalItems = numItems;
		mNumTransactions = numTrans;
		return true;
	}


}