/*This linked list's remove method removes ONLY the first instance of the string,
allowing non-unique strings to remain.

This allows the queue's front or end to not matter anymore
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma warning( disable : 4290 )  

#include <vector>
#include <string>
using namespace std;


/*
      LinkedList

      A doubly linked list with exception handling that has methods to manipulate and
	  retrieve elements.

	  Version 2
	  This linked list's remove method removes ONLY the first instance of the string,
	  allowing non-unique strings to remain.
	  This allows the queue's front or end to not matter anymore
*/
class LinkedList
{
public:

/*
Method Name:  LinkedList()

		Default constructor

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	LinkedList();

/*
Method Name:  LinkedList(vector<string> &strings)

		Constructor that takes in a string vector

	Input Only:
		strings - an existing vector
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	LinkedList(vector<string> &strings);

/*
Method Name:  LinkedList(const LinkedList &other)

		Constructor that takes an existing linked list

	Input Only:
		other - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	LinkedList(const LinkedList &other);

/*
Method Name:  operator=(const LinkedList &other)

		Constructor that reassigns to another list

	Input Only:
		other - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		LinkedList - a linked list
	Side Effects:
		None
	Throws:
		None
*/
	LinkedList operator=(const LinkedList &other);

/*
Method Name:  ~LinkedList()

		Destructor

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	~LinkedList();

/*
Method Name:  add(string element)

		Appends a node containing an element to the end

	Input Only:
		element - an element to get added
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	void add(string element);

/*
Method Name:  addToFront(element)

		Adds an node containing an element to the very beginning

	Input Only:
		element - an element to be added
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	void addToFront(string element);

/*
Method Name:  addToRear(element)

		Adds an element to the very end

	Input Only:
		element - an element to get added
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		None
*/
	void addToRear(string element);

/*
Method Name:  addAt(element, index)

		Adds an element at the desired index

	Input Only:
		element - an element to get added
		inded - index of where element should be added
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Index error - Cannot add an element to an index that
					  is greater than the total number of nodes in the list
*/
	void addAt(string element, int index) throw (string); // Indices: 0, 1, ..., n-1

/*
Method Name:  addBefore(elementToAdd, elementToAddBefore)

		Adds an element before a known element

	Input Only:
		elementToAdd - the new element to be added
		elementToAddBefore - the element that will have a new element before itself
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Not found error - Cannot add before another element if the element is nonexistant in the list
*/
	void addBefore(string elementToAdd, string elementToAddBefore) throw(string);

/*
Method Name:  addAfter(elementToAdd, elementToAddAfter)

		Adds an element after a known element

	Input Only:
		elementToAdd - a new element to be added
		elementToAddAfter - an element that will have a new element added after itself
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Not found error - Cannot add before another element if the element is nonexistant in the list

*/
	void addAfter(string elementToAdd, string elementToAddAfter)  throw(string);

/*
Method Name:  remove(element)

		removes an element

	Input Only:
		element - an element to get removed
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Not found error - cannot remove an element if it is not already in the list

*/
	void remove(string element) throw (string);

/*
Method Name:  removeAt(index)

		removes an element at a known index

	Input Only:
		index - where the element will be removed
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Index error - cannot remove an element at an index greater than the number of nodes in the list
*/
	void removeAt(int index) throw (string); // Indices: 0, 1, ..., n-1

/*
Method Name:  removeFront()

		Removes the first node

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Empty error - Cannot remove from the front if there are no elements in the list
*/
	void removeFront() throw (string);

/*
Method Name:  removeRear()

		Removes the last node

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
	Throws:
		Empty error - Cannot remove from the rear if there are no elements in the list
*/
	void removeRear() throw (string);

/*
Method Name:  getAt(index)

		Returns the element at a certain index

	Input Only:
		index - where the element will be found
	Input & Output:
		None
	Output Only:
		None
	Returns:
		the string found at the element
	Side Effects:
		None
	Throws:
		Index error - cannot return an index greater than number of elements in the list
*/
	string getAt(int index) const throw (string) ; // Indices: 0, 1, ..., n-1

/*
Method Name:  getFront()

		Returns the first element

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		The first string
	Side Effects:
		None
	Throws:
		Empty error - Cannot return the first element if the list is empty
*/
	string getFront() const throw (string);


/*
Method Name:  getRear()

		Returns the last string

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		The last string
	Side Effects:
		None
	Throws:
		Empty error - Cannot return the last element if the list is empty
*/
	string getRear() const throw (string);

/*
Method Name:  getCount()

		Returns the number of elements in the linked list

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		counter - the number of elements in the list
	Side Effects:
		None
*/
	int getCount() const;

/*
Method Name:  isEmpty()

		Checks if the linked list has no dummy nodes

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		true if there are no nodes aside from the dummy nodes
	Side Effects:
		None
*/

/*
Method Name:  isEmpty

		Checks if the linked list has no dummy nodes

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		true if there are no nodes aside from the dummy nodes
	Side Effects:
		None
*/
	bool isEmpty() const;

/*
Method Name:  isPresent(element)

		Checks to see if an element is in the linked list

	Input Only:
		element - an element to be found
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if the element was found
	Side Effects:
		None
*/
	bool isPresent(string element) const;

/*
Method Name:  toVector(bool sorted)

		Converts to a sorted vector

	Input Only:
		sorted - if the function should be sorted or not
	Input & Output:
		None
	Output Only:
		None
	Returns:
		A sorted or unassorted vector depending on the input
	Side Effects:
		None
*/
	vector<string> toVector(bool sorted) const;


/*
Method Name:  operator+(other)

		Combines two linked lists

	Input Only:
		other - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		sum - a linked list containing both linked lists
	Side Effects:
		None
*/
	LinkedList operator+(const LinkedList &other);

/*
Method Name:  operator-(other)

		Removes elements found in a linked list

	Input Only:
		other - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		difference - a linked list without elmeents from the other list
	Side Effects:
		None
*/
	LinkedList operator-(const LinkedList &other);

/*
Method Name:  operator==(other)

		Checks to see if a linked list is equivalent

	Input Only:
		other - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		true if the linked list is equivalent
	Side Effects:
		None
*/
	bool operator==(const LinkedList &other);


/*
Method Name:  operator<<(os, list)

		Overloads the printing operator

	Input Only:
		os - output stream
		list - an existing linked list
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		Prints the elements in a linked list
*/
	friend ostream &operator<<(ostream &os, const LinkedList &list);

private:

	class Node
	{
		friend class LinkedList;

	private:
		inline Node(string data)
		{
			mPrevious = mNext = 0;
			mData = data;
		}

		inline void remove()
		{
			mPrevious->mNext = mNext;
			mNext->mPrevious = mPrevious;
		}

		string mData;
		Node *mPrevious;
		Node *mNext;
	};

	void init();
	void copyAll(const LinkedList &other);
	void deleteAll();

	int find(string s) const;

	Node *mFront;
	Node *mRear;

};
#endif
