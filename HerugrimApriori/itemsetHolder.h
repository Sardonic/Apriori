#ifndef ITEMSETHOLDER_H
#define ITEMSETHOLDER_H

#include "LinkedList.h"
#include "itemset.h"

using namespace std;


class ItemsetHolder : public LinkedList<Itemset*>
{
public:
	ItemsetHolder(int n){whichItemset = n;}
	~ItemsetHolder();

	inline int getWhichItemset(){return whichItemset;}

	friend bool operator>(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend bool operator<(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend ostream& operator<<(ostream& os, ItemsetHolder& obj);

private:
	int whichItemset;
};

#endif