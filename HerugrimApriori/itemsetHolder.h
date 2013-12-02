#ifndef ITEMSETHOLDER_H
#define ITEMSETHOLDER_H

#include "queue.h"
#include "itemset.h"

using namespace std;

class ItemsetHolder : public Queue<Itemset>
{
public:
	ItemsetHolder(int n){whichItemset = n;}
	~ItemsetHolder();

	inline int getWhichItemset(){return whichItemset;}

	friend bool operator>(ItemsetHolder& rhs, ItemsetHolder& lhs);
	friend bool operator<(ItemsetHolder& rhs, ItemsetHolder& lhs);

private:
	int whichItemset;
};

#endif