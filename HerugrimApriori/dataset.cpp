#include <string>
#include <sstream>
#include "dataset.h"

//Pre: None
//Post: None
//Purpose: default constructor
//**********************************************************************
Dataset::Dataset()
{
	mNumItemsets = 0;
}

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

//Pre: we have the array specifications figured out
//Post: array is ready for population
//Purpose: allocates memory for the array
//**********************************************************************
void Dataset::allocateArrayMemory()
{
	mDataArray = new int*[mNumTransactions + 1]();

	for(int i = 0; i <= mNumTransactions; i++)
	{
		mDataArray[i] = new int[mNumTotalItems + 1]();
	}
}

void Dataset::generateAllItemsets(double supportThreshold, ostream& outStream)
{
	int i = 1;

	generateItemset(i, supportThreshold, outStream);

	while(mNumItemsets == i)
	{
		i++;

		generateItemset(i, supportThreshold, outStream);
	}
}

void Dataset::generateItemset(int itemset, double supportThreshold, ostream& outStream)
{
	ItemsetHolder holder(itemset);
	int itemCount = 0;
	int loopsLeft = itemset;
	int recursionIterator = 0;

	int* setArray = new int[itemset];

	generateItemsetRecur(recursionIterator, itemset, loopsLeft, supportThreshold, setArray, holder);

	if(holder.getCount() > 0)
	{
		mNumItemsets++;
	}

	mAllItemsets.insert(&holder);
	outStream << holder;
	delete []setArray;
}

void Dataset::generateItemsetRecur(int recursionIterator, int itemset, int loopsLeft, double supportThreshold, int* setArray, ItemsetHolder& holder)
{
	if(loopsLeft > 0)
	{
		for(int i = recursionIterator; i <= mNumTotalItems; i++)
		{
			setArray[itemset - loopsLeft] = i;

			generateItemsetRecur(i + 1, itemset, loopsLeft - 1, supportThreshold, setArray, holder);
		}
	}
	else
	{
		int itemCount = 0;

		for(int i = 0; i < mNumTransactions; i++)
		{
			int allItemsCheck = 0;

			for(int j = 0; j < itemset; j++)
			{
				allItemsCheck += mDataArray[i][setArray[j]];

				if(allItemsCheck == itemset)
				{
					itemCount++;
				}
			}

			allItemsCheck = 0;
		}

		if(itemCount >= (supportThreshold * mNumTransactions))
			{
				Itemset* currItemset = new Itemset(itemset);
				
				for(int k = 0; k < itemset; k++)
				{
					currItemset->addItem(setArray[k]);
				}

				holder.insert(currItemset);
			}
		}
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
		inputFile.close();
		return true;
	}


}

//Pre: memory is allocated for the array
//Post: the array is ready to be analyzed
//Purpose: populates the array with binary values denoting whether or not an item is in a transaction
//**********************************************************************
void Dataset::populateArray(string filename)
{
	allocateArrayMemory();

	int currIndex;
	int i = 0;
	string currLine;
	stringstream stringStream;

	ifstream inStream;
	inStream.open(filename + ".dat");

	if(inStream.good())
	{
		getline(inStream, currLine);

		while(!inStream.eof())
		{			
			stringStream << currLine;

			while(!stringStream.eof())
			{
				stringStream >> currIndex;
				mDataArray[i][currIndex]++;
			}

			stringStream.clear();
			i++;

			getline(inStream, currLine);
		}
	}

	inStream.close();
}

//Pre: None
//Post: None
//Purpose: prints the current contents of the array
//**********************************************************************
void Dataset::printArray(ostream& os)
{
	for(int i = 0; i < mNumTransactions; i++)
	{
		for(int j = 0; j < mNumTotalItems; j++)
		{
			os << mDataArray[i][j] << " ";
		}
		os << "\n\n";
	}
}