//Circular Queue Implementation
#include <iostream>
#include "queue.h"

static const string FULL = "Q Full";
static const string EMPTY = "Q Empty";

Queue::Queue(int size)
{
	init(size);
}
Queue::Queue(const Queue &other)
{
	init(other.mSize);
	copyAll(other);
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
	if (mCount == mSize)
	{
		throw FULL;
	}
	mQueue[mRear] = s;
	mRear = (mRear + 1) % mSize;
	mCount++;

}
string Queue::remove() throw(string)
{
	if (mCount == 0)
	{
		throw EMPTY;
	}
	string removedString = mQueue[mFront];
	mFront = (mFront + 1) % mSize;
	mCount--;
	return removedString;
}
bool Queue::isEmpty() const
{
	if (mCount == 0)
	{
		return true;
	}
	else return false;
}

ostream &operator<<(ostream &os, const Queue &q)
{
	for (int i = q.mFront; i < q.mRear; i++)
	{
		os << q.mQueue[i] << " ";
	}
	return os;
}


void Queue::init(int size)
{
	mSize = size;
	mFront, mRear, mCount = 0;
	//mQueue[mSize];
	mQueue = new string[mSize];
}
void Queue::copyAll(const Queue &other)
{
	for (int i = 0; i < other.mCount; i++)
	{
		mQueue[i] = other.mQueue[i];
	}
	mSize = other.mSize;
	mCount = other.mCount;
	mFront = other.mFront;
	mRear = other.mRear;
}
void Queue::deleteAll()
{
	delete[] mQueue;
	mSize, mCount, mFront, mRear = 0;
}