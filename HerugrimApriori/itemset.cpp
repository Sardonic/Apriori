#include "itemset.h"

Itemset::Itemset(int size)
{
	mSize = size;
	mCurrIndex = 0;
	mItems = new Item[size];
}

Itemset::~Itemset()
{
	delete [] mItems;
}

bool Itemset::getItem(int index, Item& output)
{
	if (index < 0 || index >= mSize)
		return false; // Index out-of-bounds

	output = mItems[index];
	return true;
}

bool Itemset::addItem(Item newItem)
{
	if (mCurrIndex == mSize)
		return false; // Itemset is full -- do not continue.

	mItems[mCurrIndex] = newItem;
	mCurrIndex++;
	return true;
}

int Itemset::getSize()
{
	return mSize;
}