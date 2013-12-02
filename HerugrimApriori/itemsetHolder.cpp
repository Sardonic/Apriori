#include "itemsetHolder.h"

ItemsetHolder::~ItemsetHolder(){}

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know which ItemsetHolder contains larger itemsets
 *  Purpose:  To compare ItemsetHolders
 *****************************************************************************/
bool operator>(ItemsetHolder& rhs, ItemsetHolder& lhs)
{
	if(rhs.getWhichItemset() > lhs.getWhichItemset())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know which ItemsetHolder contains smaller itemsets
 *  Purpose:  To compare ItemsetHolders
 *****************************************************************************/
bool operator<(ItemsetHolder& rhs, ItemsetHolder& lhs)
{
	if(rhs.getWhichItemset() < lhs.getWhichItemset())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, ItemsetHolder& obj)
{
	/*
	Node<Itemset*>* tmp;

	if (obj.mHead == NULL)
	{
		os << "The list is empty\n";
		return os;
	}

	tmp = obj.mHead;
	while (tmp != NULL)
	{
		os << tmp->mData << " ";
		tmp = tmp->mNext;
	}

	os << endl;

	return os;
	*/

	if (obj.getCount() == 0)
	{
		os << "The list is empty\n";
		return os;
	}

	for (int i = 0; i < obj.getCount(); i++)
	{
		cout << *(obj.getData(i)) << endl;
	}
}