#include "itemset.h"

/*      Pre:  None
 *     Post:  Itemset is constructed
 *  Purpose:  To create an itemset with the default size of 1
 ***************************************************/
Itemset::Itemset()
{
	mSize = 1;
	isFull = false;
}

/*      Pre:  None
 *     Post:  Itemset is constructed
 *  Purpose:  To create the itemset
 ***************************************************/
Itemset::Itemset(int size)
{
	mSize = size;
	isFull = false;
}

/*      Pre:  None
 *     Post:  Itemset destructor
 *  Purpose:  Destructor
 ***************************************************/
Itemset::~Itemset()
{

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

	output = mItems.getData(index);
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

	mItems.insert(newItem);

	if (mItems.getCount() == mSize)
	{
		isFull = true;
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

// Operator overloads ///////////////

/*      Pre:  Itemset is full
 *     Post:  Itemset is outputted
 *  Purpose:  To output the itemset
 ***************************************************/
std::ostream& operator<<(std::ostream& os, Itemset& obj)
{
	// If it's not full, it's not set up properly. Don't output.
	if (!obj.isFull)
		return os;

	os << "{ ";

	for (int i = 0; i < obj.mSize; i++)
	{
		os << obj.mItems.getData(i);

		if (i != obj.mSize - 1)
		{
			os << ", ";
		}
	}

	os << " }";

	return os;
}

bool operator<(Itemset& lhs, Itemset& rhs){return true;}
bool operator>(Itemset& lhs, Itemset& rhs){return true;}
bool operator<=(Itemset& lhs, Itemset& rhs){return true;}
bool operator>=(Itemset& lhs, Itemset& rhs){return true;}