//Rosswell Tiongco, Assignment 8, 016091762
#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(string name)
{
	mName = name;
	mStack;
}
string Stack::getName() const
{
	return mName;
}

int Stack::getTop() const
{
	return mStack.top();
}
void Stack::pop()
{
	mStack.pop();
}

void Stack::push(int item)
{
	mStack.push(item);
}