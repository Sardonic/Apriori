#include "itemset.h"

/*      Pre:  None
 *     Post:  Itemset is constructed
 *  Purpose:  To create the itemset
 ***************************************************/
Itemset::Itemset(int size)
{
	mSize = size;
	mCurrIndex = 0;
	mItems = new Item[size];
	isFull = false;
}

/*      Pre:  None
 *     Post:  Itemset destructor
 *  Purpose:  Destructor
 ***************************************************/
Itemset::~Itemset()
{
	delete [] mItems;
}

/*      Pre:  Itemset is filled
 *     Post:  The requested item is given to output
 *  Purpose:  To access data in the itemset
 ***************************************************/
bool Itemset::getItem(int index, Item& output)
{
	// Check array indices.
	// Also, if itemset isn't full, it was not set up properly and should not let the
	// caller read from it. Return false.
	if ((index < 0 || index >= mSize) || !isFull)
		return false;

	output = mItems[index];
	return true;
}

/*      Pre:  Itemset is not full
 *     Post:  Itemset adds a new item to itself
 *  Purpose:  To give data to the itemset
 ***************************************************/
bool Itemset::addItem(Item newItem)
{
	if (isFull)
		return false; // Itemset is full -- do not continue.

	mItems[mCurrIndex] = newItem;
	mCurrIndex++;

	if (mCurrIndex == mSize)
	{
		isFull = true;
		sort();
	}

	return true;
}

/*      Pre:  None
 *     Post:  Returns size
 *  Purpose:  To get the size of the itemset
 ***************************************************/
int Itemset::getSize()
{
	return mSize;
}

/*      Pre:  Itemset is full
 *     Post:  Itemset is sorted
 *  Purpose:  To sort the itemset
 ***************************************************/
void Itemset::sort()
{
	// Bubblesort -- itemsets are very small and likely to be
	// sorted or almost sorted before this function is called.

	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (int i = 0; i < mSize - 1; i++)
		{
			if (mItems[i + 1] < mItems[i])
			{
				// Swap the two items
				Item temp = mItems[i];
				mItems[i] = mItems[i + 1];
				mItems[i + 1] = temp;

				swapped = true;
			}
		}
	}
}

// Operator overloads ///////////////

/*      Pre:  Itemset is full
 *     Post:  Itemset is outputted
 *  Purpose:  To output the itemset
 ***************************************************/
std::ostream& operator<<(std::ostream& os, const Itemset& obj)
{
	// If it's not full, it's not set up properly. Don't output.
	if (!obj.isFull)
		return os;

	os << "{ ";

	for (int i = 0; i < obj.mSize; i++)
	{
		os << obj.mItems[i];

		if (i != obj.mSize - 1)
		{
			os << ", ";
		}
	}

	os << " }";

	return os;
}