/* ***       Author:  Wei Kian Chen
     *  Last Update:  April 3, 2013
     *        Class:  CSI-240-04
     *      Project:  Final Project
     *     Filename:  linkedList.h
     *
     *  Description:
     *      This is the template linked list definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
struct Node
{
   T  mData;
   Node *mNext;

   Node();
   Node(T data);
};

/*      Pre:  None
   *     Post:  This object is initialized using default values
   *  Purpose:  To initialize date object
   *************************************************************************/
template <class T>
Node<T>::Node()
{
   mNext = NULL;
}


/*      Pre:  None
   *     Post:  This object is initialized using specified data
   *  Purpose:  To initialize date object
   *************************************************************************/
template <class T>
Node<T>::Node(T data)
{
   mData = data;
   mNext = NULL;
}

#endif