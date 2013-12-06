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

#ifndef ITEMSETHOLDER_H
#define ITEMSETHOLDER_H

#include "LinkedList.h"
#include "itemset.h"

using namespace std;


class ItemsetHolder : public LinkedList<Itemset*>
{
public:
	ItemsetHolder(){whichItemset = 1;}
	ItemsetHolder(int n){whichItemset = n;}
	~ItemsetHolder();

	inline int getWhichItemset(){return whichItemset;}

	friend bool operator>(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend bool operator<(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend bool operator>=(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend bool operator<=(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend ostream& operator<<(ostream& os, ItemsetHolder& obj);

private:
	int whichItemset;
};

#endif