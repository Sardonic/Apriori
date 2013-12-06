/********
*
* Itemset.h
*
*  Itemsets require a given size before they are created. They are
*  also immutable; they cannot be edited once created, although they
*  are not fully created until all the data has been added to them. Simply
*  create an itemset of the size you need, and add the appropriate
*  number of items. For example:
*
*    Itemset five_itemset(5); // a five-itemset.
*    five_itemset.addItem(2); // 2 means "Item with ID 2" in this case.
*    five_itemset.addItem(8);
*    five_itemset.addItem(13);
*    five_itemset.addItem(6);
*    five_itemset.addItem(9);
*    
*  Now the itemset is {2, 6, 8, 9, 13}. It organizes itself when it fills up.
*  The following line of code will not change the itemset:
*     five_itemset.addItem(100); // Error -- itemset already full. Returns false.
*
*  Items are returned to a variable passed by reference. The getItem function
*  checks array bounds, so it returns a bool instead of simply returning the item.
*  Ex:
*    Item thirdItem;
*    five_itemset.getItem(3, thirdItem) // returned true
*    cout << thirdItem;
* 
*
* *** DO NOT make an itemset with size < 1 ***
********/

#ifndef ITEMSET_H
#define ITEMSET_H

#include <iostream>
#include "linkedList.h"

typedef int Item;

class Itemset
{
public:
	Itemset();
	Itemset(int size);
	~Itemset();

	bool getItem(int index, Item& output);
	bool addItem(Item newItem);
	int  getSize();

	void setFrequency(int frequency);
	int getFrequency();

	friend std::ostream& operator<<(std::ostream& os, Itemset& obj);

	friend bool operator<(Itemset& lhs, Itemset& rhs);
	friend bool operator>(Itemset& lhs, Itemset& rhs);
	friend bool operator<=(Itemset& lhs, Itemset& rhs);
	friend bool operator>=(Itemset& lhs, Itemset& rhs);

private:
	LinkedList<Item> mItems;
	int mSize;
	bool isFull;
	int mFrequncy;
};

std::ostream& operator<<(std::ostream& os, const Itemset& obj);

#endif