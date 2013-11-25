#include "itemset.h"

Itemset::Itemset(int size)
{
	mSize = size;
	mCurrIndex = 0;
	mItems = new Item[size];
	isFull = false;
}

Itemset::~Itemset()
{
	delete [] mItems;
}

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

int Itemset::getSize()
{
	return mSize;
}

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