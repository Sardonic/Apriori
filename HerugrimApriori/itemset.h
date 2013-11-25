#ifndef ITEMSET_H
#define ITEMSET_H

typedef int Item;

class Itemset
{
public:
	Itemset(int size);
	~Itemset();

	bool getItem(int index, Item& output);
	bool addItem(Item newItem);
	int  getSize();

private:
	Item* mItems;
	int mSize;
	int mCurrIndex;
};


#endif