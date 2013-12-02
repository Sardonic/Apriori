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

template <class T>
std::ostream& operator<<(std::ostream& os, ItemsetHolder& obj)
{
	Node<T>* tmp;

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
}