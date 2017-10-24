#include "linked_list.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	init();
}
LinkedList::LinkedList(vector<string> &strings)
{
	init();
	for (unsigned int i = 0; i < strings.size(); ++i)
	{
		add(strings.at(i));
	}
}
LinkedList::LinkedList(const LinkedList &other)
{
	init();
	Node *oldTracker = other.mFront->mNext;  //Other link's node
	for (int i = 0; i < other.getCount(); i++)
	{
		add(oldTracker->mData);
		oldTracker = oldTracker->mNext;
	}
}
LinkedList LinkedList::operator=(const LinkedList &other)
{
	return other;
}
LinkedList::~LinkedList()
{
	deleteAll();
}

void LinkedList::add(string element) {
	Node *newNode = new Node(element);
	newNode->mNext = mRear;
	newNode->mPrevious = mRear->mPrevious; //"The new node's previous gets the rear's previous
	newNode->mNext->mPrevious = newNode; //Node before the one after is itself
	newNode->mPrevious->mNext = newNode; //Node pointing before it that coems after is itself
}
void LinkedList::addToFront(string element)
{
	addAt(element, 0);
}
void LinkedList::addToRear(string element)
{
	addAt(element, getCount()) ;
}
void LinkedList::addAt(string element, int index) throw (string)
{
	Node *newNode = new Node(element);
	Node *tracker = mFront->mNext;  //Currently pointing at index 0

	//Traversing through the list
	for ( int ii = 0 ; ii < index ; ii++ ) {
		tracker = tracker->mNext;  //Continuously reassigning the new node, shifting its address
	}
	
	//Reconnecting pointers
	newNode->mNext = tracker;
	newNode -> mPrevious = tracker->mPrevious; //The new node's previous gets the value that the tracker's previous pointed to
	//Pointing back
	newNode->mPrevious->mNext = newNode;
	newNode->mNext->mPrevious = newNode;

}
void LinkedList::addBefore(string elementToAdd, string elementToAddBefore) throw(string)
{
	int index = find(elementToAddBefore);
	addAt(elementToAdd, index);  //-2?? instead of -1?
}	
void LinkedList::addAfter(string elementToAdd, string elementToAddAfter)  throw(string)
{
	int index = find(elementToAddAfter);
	addAt(elementToAdd, index + 1); // Needs +2? , not just index
}

void LinkedList::remove(string element) throw (string)
{
	removeAt(find(element));

}
void LinkedList::removeAt(int index) throw (string)
{
	Node *current = mFront->mNext;
	int seek = 0;
	while (seek != index)
	{
		current = current->mNext;
		seek++;
	}
	Node *previous = current->mPrevious;
	previous->mNext = current->mNext;
	current->mNext->mPrevious = previous;
	delete current;
}
void LinkedList::removeFront() throw (string)
{
	removeAt(0);
}
void LinkedList::removeRear() throw (string)
{
	removeAt(getCount() - 1);
}

string LinkedList::getAt(int index) const throw (string)
{
	Node *placeHolder = mFront->mNext;
	for (int ii = 0; ii < index; ii++)
	{
		placeHolder = placeHolder->mNext;
	}

	return placeHolder->mData;
}
string LinkedList::getFront() const throw (string)
{
	return getAt(0);
}
string LinkedList::getRear() const throw (string)
{
	return getAt(getCount() - 1 );
}

int LinkedList::getCount() const
{
	
	int counter = 0;
	Node *newNode = mFront ->mNext;
	while (newNode->mNext != NULL) {
		newNode = newNode->mNext;
		counter++;
	}
	return counter ;

}
bool LinkedList::isEmpty() const
{
	if (getCount() == 0)
	{
		return true;
	}
	else return false;
}
bool LinkedList::isPresent(string element) const
{
	Node *tracker = mFront->mNext;  //Currently pointing at index 0

	//Traversing through the list
	while (tracker->mData != element)
	{
		if (tracker->mData == element)
		{
			return true;
			break;
		}
		else return false;
		tracker = tracker->mNext;  //Continuously reassigning the new node, shifting its address
	}
}

vector<string> LinkedList::toVector(bool sorted) const
{
	Node *tracker = mFront->mNext;  //Currently pointing at index 0
	vector<string> conversion;
	for (int i = 0; i < getCount(); i++)
	{
		conversion.push_back(tracker->mData);
		tracker = tracker->mNext;
	}
	if (sorted = false)
	{
		return conversion;
	}
	sort(conversion.begin(), conversion.end());
	return conversion;
}

LinkedList LinkedList::operator+(const LinkedList &other)
{
	LinkedList sum(*this);
	Node *oldTracker = other.mFront->mNext;  //Other linkedlist's node
	for (int i = 0; i < other.getCount(); i++)
	{
		sum.add(oldTracker->mData);
		oldTracker = oldTracker->mNext;
	}
	return sum;
}
LinkedList LinkedList::operator-(const LinkedList &other)
{
	LinkedList sum(*this);
	Node *oldTracker = other.mFront->mNext;  //Other linkedlist's node
	for (int i = 0; i < other.getCount(); i++)
	{
		sum.remove(oldTracker->mData);
		oldTracker = oldTracker->mNext;
	}
	return sum;
}
bool LinkedList::operator==(const LinkedList &other)
{
	Node *oldTracker = other.mFront->mNext;  //Other linkedlist's node
	for (int i = 0; i < other.getCount(); i++)
	{
		if (oldTracker->mData != getAt(i))
		{
			return false;
		}
		oldTracker = oldTracker->mNext;
	}

	return true;
}

ostream &operator<<(ostream &os, const LinkedList &list)
{
	for (int ii = 0; ii < list.getCount(); ii++)
	{
		os << list.getAt(ii) << " ";
	}
	return os;
}


class Node
{
	friend class LinkedList;

private:
	inline Node(string data)
	{
		mPrevious = mNext = 0;
		mData = data;
	}

	string mData;
	Node *mPrevious;
	Node *mNext;
};

void LinkedList::init()
{
	//Making mFront and mRear initially point to each other
	mFront = new Node("dummyFront");
	mRear = new Node("dummyRear");
	mFront->mNext = mRear;
	mRear->mPrevious = mFront;
}
void LinkedList::copyAll(const LinkedList &other)
{
	//init();
}
void LinkedList::deleteAll()
{
Node *tracker = mFront->mNext;
	while (tracker->mNext != NULL)
	{
		delete tracker->mPrevious;
		tracker = tracker->mNext;
	}
	delete tracker;
}

int LinkedList::find(string s) const
{
	int counter = 0;  //initializing counter
	Node *counterNode = mFront->mNext; //Start from the beginning, not a new node
	while (counterNode->mData != s) //While the new node's data isnt equivalent to s
	{
		counter++;  //Increment BEFORE shifting
		counterNode = counterNode->mNext;
	}
	return counter;
}
