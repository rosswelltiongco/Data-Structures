//Rosswell Tiongco, ID: 016091762, Assignment #6
#include "queue.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Public
///////////////////////////////////////////////////////////////////////////////////////////////////////////
Queue::Queue()
{
	init();
}
Queue::Queue(const Queue &other)
{
	init();
	copyAll(other);
}
Queue Queue::operator=(const Queue &other)
{
	deleteAll();
	init();
	copyAll(other);
	return *this;
}
Queue::~Queue()
{
	deleteAll();
}

void Queue::add(string s)
{
	mList->addToFront(s);
}
string Queue::remove()
{
	string returnVal = mList->getRear();
	mList->removeRear();
	return returnVal;
}
bool Queue::isEmpty() const
{
	if (mList->isEmpty()) return true;
	else return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Friends
///////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream &operator<<(ostream &os, const Queue &q)
{
	for (int i = 0; i < q.mList->getCount(); i++)
	{
		os << q.mList->getAt(i) << " ";
	}
	return os;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Private
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Queue::init()
{
	mList = new LinkedList();
}
void Queue::copyAll(const Queue &other)
{
	for (int i = 0; i < other.mList->getCount(); i++)
	{

		this->mList->addToFront(other.mList->getAt(i));
	}
}
void Queue::deleteAll()
{
}

