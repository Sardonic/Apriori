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
