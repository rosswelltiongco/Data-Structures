//Circular Queue Implementation
//NOTE: CHANGE mQUEUE back to poitner
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(int size)
{
	init(size);
}
Queue::Queue(const Queue &other)
{
	init(other.mSize);
}
Queue Queue::operator=(const Queue &other)
{
	deleteAll();
	init(other.mSize);
	copyAll(other);
	return *this;
}
Queue::~Queue()
{
	deleteAll();
}

void Queue::add(string s) throw(string)
{
	mCount++;
}
string Queue::remove() throw(string)
{
	string dummy = "Dummy";
	mCount--;
	return dummy;
}
bool Queue::isEmpty() const
{
	if (mCount == 0)
	{
		return true;
	}
}

ostream &operator<<(ostream &os, const Queue &q)
{
	os << q.mQueue << endl;
	return os;
}


void Queue::init(int size)
{
	string *mQueue;
	int mSize = size;
	int mCount;
	int mFront;
	int mRear;
}
void copyAll(const Queue &other)
{

}
void deleteAll()
{

}

