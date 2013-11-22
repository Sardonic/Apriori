#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class Queue
{
	private:
		Node<T> *mHead, *mTail;
		int mCount;

	public:
		Queue();
		~Queue();

		int getCount();
		T dequeue();
		void display();
		void enqueue(T data);
		bool isEmpty();

};

/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize date object
 *****************************************************************************/
template <class T>
Queue<T>::Queue()
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
Queue<T>::~Queue()
{
	Node<T> *tmp, *toBeDeleted;

	tmp = mHead;

	//remove node by node

	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	//reinitialize
	mHead = NULL;
	mTail = NULL;
}

/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to the caller
 *  Purpose:  To retrieve the number of nodes in the list
 *****************************************************************************/
template <class T>
int Queue<T>::getCount()
{
	return mCount;
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template <class T>
void Queue<T>::display()
{

	Node<T> *tmp;

	if(mHead == NULL)
	{
		cout << "The queue is empty";
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

/*      Pre:  The list is instantiated
 *     Post:  First element is removed
 *  Purpose:  To remove the first element of the queue
 *****************************************************************************/
template <class T>
T Queue<T>::dequeue()
{
	Node<T> *oldNode, *newHead;
	T data;
	if(mHead == NULL)
		return data;
	else
	{
		oldNode = mHead;
		newHead = mHead->mNext;
		mHead = newHead;
	}


	data = oldNode->mData;
	delete oldNode;
	mCount--;
	return data;
}

/*      Pre:  The list is instantiated
 *     Post:  Adds element to end of Queue
 *  Purpose:  to add a new element to the end of th queue
 *****************************************************************************/
template <class T>
void Queue<T>::enqueue(T data)
{
	Node<T> *newNode;
	newNode = new Node<T>(data);

	if(mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		newNode->mNext = NULL;
		mTail = newNode;
	}
	mCount++;
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template <class T>
bool Queue<T>::isEmpty()
{
	if(mCount == 0)
		return true;
	return false;
}

#endif