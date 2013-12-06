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
		if(mDataArray[i])
		{
			delete [] mDataArray[i];
		}
	}

	delete [] mDataArray;
}

//Pre: we have the array specifications figured out
//Post: array is ready for population
//Purpose: allocates memory for the array
//**********************************************************************
void Dataset::allocateArrayMemory()
{
	mDataArray = new int*[mNumTransactions]();

	for(int i = 0; i < mNumTransactions; i++)
	{
		mDataArray[i] = new int[mNumTotalItems + 2](); //mNumTotalItems + 1 used for pruning
	}
}
<<<<<<< HEAD
//Pre: Data array is populated
//Post: All possible itemsets are in the allItemsets linked list
//Purpose: To generate all possible itemsets
=======
//Pre: support threshold has been choosen, ostream has been instantiated
//Post: all itemsets are generated
//Purpose: generate all itemsets
>>>>>>> 8a67393ecfb9df76b4f417317849424cd6c06404
//**********************************************************************
void Dataset::generateAllItemsets(double supportThreshold, ostream& outStream)
{
	int i = 1;

	cout << "Generating 1-itemsets...\n";
	generateItemset(i, supportThreshold, outStream);

	while(mNumItemsets == i)
	{
		i++;

		cout << "\nGenerating " << i << "-itemsets...\n";
		generateItemset(i, supportThreshold, outStream);
	}
}

<<<<<<< HEAD
//Pre: Data array is populated
//Post: A new dataset is in the allItemsets linked list and the database array is pruned
//Purpose: To generate an itemset and prune the array
//**********************************************************************
=======
//Pre: itemset number is choosen, support threshold has been choosen, ostream has been instantiated
//Post: n-itemset is generated
//Purpose: starts off the recursion calls to generate all items in the itemset
//***************************************************************************************************
>>>>>>> 8a67393ecfb9df76b4f417317849424cd6c06404
void Dataset::generateItemset(int itemset, double supportThreshold, ostream& outStream)
{
	ItemsetHolder holder(itemset);
	int itemCount = 0;
	int loopsLeft = itemset;
	int recursionIterator = 0;

	int* setArray = new int[itemset];

	generateItemsetRecur(recursionIterator, itemset, loopsLeft, supportThreshold, setArray, holder);

	if(holder.getCount() > 0) // if 0 then no n-itemsets were found and the algorithm will end
	{
		mNumItemsets++;
	}

	for(int i = 0; i < mNumTransactions; i++)
	{
		if(mDataArray[i])
		{
			if(mDataArray[i][mNumTotalItems+1] != itemset)
			{
				delete[] mDataArray[i];
				mDataArray[i] = NULL;
			}
			else
			{
				mDataArray[i][mNumTotalItems+1] = 0;
			}
		}
	}

	mAllItemsets.insert(&holder);
	outStream << holder;
	delete []setArray;
}

<<<<<<< HEAD
//Pre: We want to generate an itemset
//Post: We have an itemset generated
//Purpose: Recursively generates an itemset
//**********************************************************************
=======
//Pre: number of recursions done, n-itemset is determined, number of loops left, support threshold, current set to check, itemset holder has been made
//Post: n-itemset is generated
//Purpose: starts off the recursion calls to generate all items in the itemset
//***************************************************************************************************
>>>>>>> 8a67393ecfb9df76b4f417317849424cd6c06404
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
		LinkedList<int> goodTransactionList;

		//Counts the occurence of the itemset
		for(int i = 0; i < mNumTransactions; i++)
		{
			if(mDataArray[i])
			{
				int allItemsCheck = 0;

				for(int j = 0; j < itemset; j++)
				{
					allItemsCheck += mDataArray[i][setArray[j]];

					if(allItemsCheck == itemset)
					{
						itemCount++;
						goodTransactionList.insert(i);
					}
				}

				allItemsCheck = 0;
			}
		}

		//Checks to see if the itemset passes the support threshold
		if(itemCount >= (supportThreshold * mNumTransactions))
		{
			Itemset* currItemset = new Itemset(itemset);
				
			for(int k = 0; k < itemset; k++)
			{
				currItemset->addItem(setArray[k]);
			}

<<<<<<< HEAD
			holder.insert(currItemset);

			for(int i = 0; i < goodTransactionList.getCount(); i++)
			{
				mDataArray[goodTransactionList.getData(i)][mNumTotalItems+1] = itemset;
=======
				holder.insert(currItemset); // adds the itemset to the holder
>>>>>>> 8a67393ecfb9df76b4f417317849424cd6c06404
			}
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
		if(mDataArray[i])
		{
			for(int j = 0; j <= mNumTotalItems + 1; j++)
			{
				os << mDataArray[i][j] << " ";
			}
		
			os << "\n\n";
		}
	}
}
