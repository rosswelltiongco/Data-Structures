#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

#include "linked_list.h"

class Queue
{
public:
	Queue();
	Queue(const Queue &other);
	Queue operator=(const Queue &other);
	~Queue();

	void add(string s);
	string remove();
	bool isEmpty() const;

	friend ostream &operator<<(ostream &os, const Queue &q);

private:
	void init();
	void copyAll(const Queue &other);
	void deleteAll();

	LinkedList mList;

};
#endif
