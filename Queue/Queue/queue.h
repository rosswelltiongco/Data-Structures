//Rosswell Tiongco, ID: 016091762, Assignment #6
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

#include "linked_list.h"

/*
* Queue
*
*     A linked list implementation via object to make a queue; adding an element adds to the front, whereas
*     removing an element removes from the end. Cannot get the element at a particular index in the queue,
      can only print out the entire list.
*/
class Queue
{
public:

/*
* Method Name:  Queue()
*
*    Default constructor
*
* Input Only:
*      None
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     None
*
* Side Effects:
*     None
*/
	Queue();

/*
* Method Name:  Queue(other)
*
*    Constructor given an existing Queue
*
* Input Only:
*      other - an existing queue
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     None
*
* Side Effects:
*     None
*/
	Queue(const Queue &other);

/*
* Method Name:  operator=(other)
*
*    Sets a queue equal to an existing queue
*
* Input Only:
*      other - an existing queue
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     Queue - a queue copied from the provided stack
*
* Side Effects:
*     None

*/
	Queue operator=(const Queue &other);

/*
* Method Name:  ~Queue()
*
*    Destructor
*
* Input Only:
*      None
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     None
*
* Side Effects:
*     None
*/
	~Queue();

/*
* Method Name:  add(s)
*
*    Adds a string to the front of the list
*
* Input Only:
*      s - a string to be queued
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     None
*
* Side Effects:
*     None
*/
	void add(string s);

/*
* Method Name:  remove()
*
*    removes the element at the end of the queue
*
* Input Only:
*      None
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     the string that was removed
*
* Side Effects:
*     None
*/
	string remove();

/*
* Method Name:  isEmpty()
*
*    Checks to see if the queue is empty or not
*
* Input Only:
*      None
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     boolean value indicating if the queue is empty or not
*
* Side Effects:
*     None
*/
	bool isEmpty() const;

/*
* Method Name:  operator<<(os, q)
*
*    Overloads the cout operator for a queue
*
* Input Only:
*      os - object stream 
*	   q - an existing queue
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     os - the object stream
*
* Side Effects:
*     Outputs the contents of a queue to the console
*
* Throws:
*     None
*/
	friend ostream &operator<<(ostream &os, const Queue &q);

private:
	void init();
	void copyAll(const Queue &other);
	void deleteAll();

	LinkedList *mList;

};
#endif
