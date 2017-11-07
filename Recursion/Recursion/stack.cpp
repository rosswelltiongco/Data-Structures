#include <iostream>

using namespace std;

Stack::Stack(string name)
{
	string mName = name;
	stack<int> mStack;
}
string Stack::getName() const
{
	return mName;
}

int getTop() const;
void pop();
void push(int item);