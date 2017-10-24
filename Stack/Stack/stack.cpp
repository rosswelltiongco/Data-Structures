#include "stack.h"

Stack::Stack()
{
	init();
}
Stack::Stack(const Stack &other)
{
	init();
	copy(other);
}
Stack Stack::operator=(const Stack &other)
{
	deleteAll();
	init();
	copy(other);
	return *this;
}
Stack::~Stack()
{
	deleteAll();
}

void Stack::push(string item)
{
	mList->add(item);
}
void Stack::pop() throw(string)  // Throws if stack is empty
{
	mList->removeRear();
}
string Stack::getTop() const throw(string) // Throws if stack is empty
{
	return mList->getRear();
}
bool Stack::isEmpty() const
{
	return mList->isEmpty();
}

ostream &operator<<(ostream &os, const Stack &s)
{
	for (int i = s.mList->getCount() - 1; i >= 0; i--)
	{
		os << s.mList->getAt(i) << " ";
	}
	return os;
}

void Stack::init()
{
	mList = new LinkedList(); //containment
}
void Stack::copy(const Stack &other)
{
	for (int i = 0; i < other.mList->getCount(); i++)
	{

		this->push(other.mList->getAt(i));
	}

}
void Stack::deleteAll()
{
}