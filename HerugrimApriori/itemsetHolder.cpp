/********
*	Team: Herugrim
*	Authors: David Johnston, Scott Barrett, Jack Storm
*	Tester: Wangchuk Zigmyal
*	Class: CSI-281-01
*	Assignment: Apriori
*	Date Assigned: Monday, November 11th, 2013
*	Date Due: 17:00 EST, Friday, December 6, 2013
*	Description: Implement the apriori algorithm using data structures 
*				 learned in class
*	Certification of Authenticy: We hearby certify that this assignment is our own work
********/
#include "itemsetHolder.h"

ItemsetHolder::~ItemsetHolder(){}

/*      Pre:  We have two ItemsetHolders we would like to compare
 *     Post:  We know if the left ItemsetHolder is of larger order
 *  Purpose:  To compare ItemsetHolders
 *****************************************************************************/
bool operator>(ItemsetHolder& lhs, ItemsetHolder& rhs)
{
	if(lhs.getWhichItemset() > rhs.getWhichItemset())
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
bool operator<(ItemsetHolder& lhs, ItemsetHolder& rhs)
{
	if(lhs.getWhichItemset() < rhs.getWhichItemset())
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
bool operator>=(ItemsetHolder& lhs, ItemsetHolder& rhs)
{
	if(lhs.getWhichItemset() >= rhs.getWhichItemset())
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
bool operator<=(ItemsetHolder& lhs, ItemsetHolder& rhs)
{
	if(lhs.getWhichItemset() <= rhs.getWhichItemset())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*      Pre:  None
 *     Post:  ItemsetHolder is outputted
 *  Purpose:  To output the ItemsetHolder
 ***************************************************/
std::ostream& operator<<(std::ostream& os, ItemsetHolder& obj)
{
	if (obj.getCount() == 0)
	{
		os << "There are no " << obj.whichItemset << "-itemsets\n";
		return os;
	}

	os << "There are " << obj.getCount() << ", " << obj.whichItemset << "-itemsets\n";
	for (int i = 0; i < obj.getCount(); i++)
	{
		os << *(obj.getData(i)) << endl;
	}

	return os;
}