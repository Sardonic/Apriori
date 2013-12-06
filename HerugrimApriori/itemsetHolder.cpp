#include "itemsetHolder.h"

ItemsetHolder::~ItemsetHolder(){}

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know if the left ItemsetHolder is of larger order
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
 *     Post:  We know if the left ItemsetHolder is of smaller order
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

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know if the left itemset is of larger or equal order
 *  Purpose:  To compare ItemsetHolders
 *****************************************************************************/
bool operator>=(ItemsetHolder& rhs, ItemsetHolder& lhs)
{
	if(rhs.getWhichItemset() >= lhs.getWhichItemset())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know if the left itemset is of smaller or equal order
 *  Purpose:  To compare ItemsetHolders
 *****************************************************************************/
bool operator<=(ItemsetHolder& rhs, ItemsetHolder& lhs)
{
	if(rhs.getWhichItemset() <= lhs.getWhichItemset())
	{
		return true;
	}
	else
	{
		return false;
	}
}

<<<<<<< HEAD
/*      Pre:  None
 *     Post:  ItemsetHolder is outputted
 *  Purpose:  To output the ItemsetHolder
 ***************************************************/
=======
/*      Pre:  We have an ItemsetHolder we would like to output
 *     Post:  we output the data in the ItemsetHolder
 *  Purpose:  To output ItemsetHolders
 *****************************************************************************/
>>>>>>> 8a67393ecfb9df76b4f417317849424cd6c06404
std::ostream& operator<<(std::ostream& os, ItemsetHolder& obj)
{
	if (obj.getCount() == 0)
	{
		os << "There are no " << obj.whichItemset << " itemsets\n";
		return os;
	}

	for (int i = 0; i < obj.getCount(); i++)
	{
		os << *(obj.getData(i)) << endl;
	}

	return os;
}
