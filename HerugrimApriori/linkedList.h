/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"

using namespace std;

const int LINKED_LIST_NOT_FOUND = -1;

template<class T>
class LinkedList
{
private:
	Node<T>* mHead;
	Node<T>* mTail;
	int  mCount;

public:
	LinkedList();
	~LinkedList();

	int getCount();
	T getData(int index);
	void setData(int index, T data);

	void clear();
	virtual void display();
	int getIndex(T searchKey);
	void insert(T data);
	bool isEmpty();
	bool isExist(T searchKey);
	T remove(T searchKey);
	T removeAllMatch(T searchKey);
	T removeElementAt(int index);
};


/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize date object
 *****************************************************************************/
template<class T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list 
 *****************************************************************************/
template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* tmp;
	Node<T>* toBeDeleted;
	tmp = mHead;

	// removing node by node
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
}

/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to the caller
 *  Purpose:  To retrieve the number of nodes in the list
 *****************************************************************************/
template<class T>
int LinkedList<T>::getCount()
{
	return mCount;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 *****************************************************************************/
template<class T>
T LinkedList<T>::getData(int index)
{
	int  i;
	Node<T>* tmp;

	tmp = mHead;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	return tmp->mData;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns the index location of the found item.  If 
 *            the item is not found, the functions returns LINKED_LIST_NOT_FOUND,
 *            which is -1
 *  Purpose:  To retrieve the index of the specified search key
 *****************************************************************************/
template<class T>
int LinkedList<T>::getIndex(T searchKey)
{
	bool found = false;
	Node<T>* tmp;
	int  i = 0;
   
	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
		{
			found = true;
		}
		else if (tmp->mData > searchKey)
		{
			tmp = NULL;
		}
		else
		{
			tmp = tmp->mNext;
		}
		
		i++;
	}

	if (!found)
	{
		return LINKED_LIST_NOT_FOUND;
	}
	else
	{
		return i;
	}
}

/*      Pre:  The list is instantiated, the index is valid and the data is
 *            available
 *     Post:  The data in the specified index is updated with the specified
 *            data
 *  Purpose:  To update the specified nodes in the list
 *****************************************************************************/
template<class T>
void LinkedList<T>::setData(int index, T data)
{
	int  i;
	Node<T>* tmp;

	tmp = mHead;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	tmp->mData = data;
}

/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To reset the list
 *****************************************************************************/
template<class T>
void LinkedList<T>::clear()
{
	if(mHead != NULL)
	{
		Node<T>* pCurr = mHead;
		Node<T>* pPrev;

		while( pCurr->mNext != NULL )
		{
			pPrev = pCurr;
			pCurr = pCurr->mNext;

			delete pPrev;
			pPrev = NULL;
		}

		//Delete the last node
		mHead = NULL;
		delete pCurr;
		pCurr = NULL;

	}
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template<class T>
void LinkedList<T>::display()
{
	Node<T>* tmp;

	if (mHead == NULL)
	{
		cout << "The list is empty\n";
		return;
	}

	tmp = mHead;
	while (tmp != NULL)
	{
		cout << tmp->mData << " ";
		tmp = tmp->mNext;
	}
	cout << endl;
}

/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in ascending order 
 *  Purpose:  To insert a data into the list in ascending order.  However, if
 *            the data already existed in the list, it will not be added again
 *****************************************************************************/
template<class T>
void LinkedList<T>::insert(T data)
{
	Node<T>* tmp;
	Node<T>* oneBefore = NULL;
	Node<T>* newNode;

	newNode = new Node<T>(data);

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		if (data >= mHead->mData)
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data <= mTail->mData)
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else
		{
			tmp = mHead;
			while (tmp->mData > data)
			{
			oneBefore = tmp;
			tmp = tmp->mNext;
			}

			newNode->mNext = tmp;
			oneBefore->mNext = newNode;
		}
	}

	mCount++;
}


/*      Pre:  The list is instantiated 
 *     Post:  The function returns true is the list is empty; false otherwise
 *  Purpose:  To determine if the list is empty
 *****************************************************************************/
template<class T>
bool LinkedList<T>::isEmpty()
{
	return mHead == NULL;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key is found; false otherwise 
 *  Purpose:  To determine if a specific value exists in the list or not
 *****************************************************************************/
template<class T>
bool LinkedList<T>::isExist(T searchKey)
{
	bool found = false;
	Node<T>* tmp;
	int  i = 0;
   
	tmp = mHead;
	while (tmp != NULL && !found)
	{
		if (tmp->mData == searchKey)
		{
			found = true;
		}
		else if (tmp->mData > searchKey)
		{
			break;
		}
		else
		{
			tmp = tmp->mNext;
		}
         
		i++;
	}

	return found;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  If the searchKey exists, it is removed from the list and its
 *            content is returned to the caller.  Otherwise, the function
 *            returns the default value from T type
 *  Purpose:  To remove a specific value from the list
 *****************************************************************************/
template<class T>
T LinkedList<T>::remove(T searchKey)
{
	Node<T>* tmp;
	Node<T>* oneBefore = NULL;
	Node<T>* toBeDeleted;

	int  data = LINKED_LIST_NOT_FOUND;
	bool found = false;

	if (mHead != NULL)
	{
		tmp = mHead;
		while (tmp != NULL && !found)
		{
			if (tmp->mData == searchKey)
			{
				found = true;
			}
			else if (tmp->mData > searchKey)
			{
				break;
			}
			else
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}
		}

		if (found)
		{
			toBeDeleted = tmp;
			data = toBeDeleted->mData;

			if (tmp == mHead)
			{
				if (mHead == mTail)
				{
					mHead = NULL;
					mTail = NULL;
				}
				else
				{
					mHead = tmp->mNext;
					toBeDeleted->mNext = NULL;
				}
			}
			else if (tmp == mTail)
			{
				mTail = oneBefore;
				mTail->mNext = NULL;
			}
			else
			{
				oneBefore->mNext = tmp->mNext;
			}

			delete toBeDeleted;

			mCount--;
		}
	}

	return data;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  If the searchKey exists, remove all matching keys from the list
*             and its content is returned to the caller.  Otherwise, the function
 *            returns the default value from T type
 *  Purpose:  To remove all occurrence of the specified value from the list
 *****************************************************************************/
template<class T>
T LinkedList<T>::removeAllMatch(T searchKey)
{
	T data = LINKED_LIST_NOT_FOUND;

	while (isExist(searchKey))
	{
		data = remove(searchKey);
	}

	return data;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The node in the specified index location is removed from the list.
 *            If the index location is invalid, return -1, otherwise return 
 *            data removed from the list
 *  Purpose:  To remove the node at the specified location
 *****************************************************************************/
template<class T>
T LinkedList<T>::removeElementAt(int index)
{
	Node<T>* tmp;
	Node<T>* oneBefore = NULL;
	Node<T>* toBeDeleted;

	T data = T();
	int j;

	bool found = false;

	if (!isEmpty() && index < mCount)
	{
		if (index == 0)
		{
			toBeDeleted = mHead;
			mHead = mHead->mNext;
			toBeDeleted->mNext = NULL;
		}
		else if (index == mCount - 1)
		{
			toBeDeleted = mTail;
			for (oneBefore = mHead, j = 0; j < index - 1; j++)
			oneBefore = oneBefore->mNext;

			oneBefore->mNext = NULL;
			mTail = oneBefore;
		}
		else
		{
			tmp = mHead;
			for (j = 0; j < index; j++)
			{
			oneBefore = tmp;
			tmp = tmp->mNext;
			}

			toBeDeleted = tmp;
			oneBefore->mNext = tmp->mNext;
			toBeDeleted->mNext = NULL;
		}

		data = toBeDeleted->mData;
		delete toBeDeleted;

		mCount--;
	}

	return data;
}

#endif LINKEDLIST_H