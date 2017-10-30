#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

#include "linked_list.h"
/*
* Stack
*
*     A linked list implementation of a stack; a Push appends an element
*	  to the end. Getting an element can only retrieve the element at the end.
*/
class Stack
{
public:
/*
* Method Name:  Stack()
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
*
* Throws:
*     None
*/
	Stack();

	/*
* Method Name:  Stack(other)
*
*    Constructor given an existing stack
*
* Input Only:
*      other - an existing stack
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
*
* Throws:
*     None
*/
	Stack(const Stack &other);

/*
* Method Name:  operator=(other)
*
*    Sets a stack equal to an existing stack
*
* Input Only:
*      other - an existing stack
*
* Input & Output:
*      None
*
* Output Only:
*      None
*
* Returns:
*     Stack - a stack copied from the provided stack
*
* Side Effects:
*     None
*
* Throws:
*     None
*/
	Stack operator=(const Stack &other);


	/*
	* Method Name:  ~Stack()
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
	*
	* Throws:
	*     None
	*/
	~Stack();

/*
* Method Name:  push(item)
*
*    Adds an element to the end of the stack
*
* Input Only:
*      item - an element to be added at the end
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
*
* Throws:
*     None
*/
	void push(string item);


/*
* Method Name:  pop()
*
*    Removes the last element from the list
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
*
* Throws:
*     empty error - cannot remove an element if the stack is empty
*/
	void pop() throw(string);  // Throws if stack is empty

/*
* Method Name:  getTop()
*
*    Gets the last element in the stack
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
*     string - the most recently added element to the list
*
* Side Effects:
*     None
*
* Throws:
*     empty error - cannot get an element from the stack if the stack is empty
*/
	string getTop() const throw(string); // Throws if stack is empty

/*
* Method Name:  isEmpty()
*
*    Tells you if the stack is empty
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
*     bool - true if the stack is empty
*
* Side Effects:
*     None
*
* Throws:
*     None
*/
	bool isEmpty() const;

/*
* Method Name:  operator<<(os, s)
*
*    An overloaded ;p
*
* Input Only:
*      os - object stream 
*	   s - an existing stack
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
*     Outputs the contents of a stack to the console
*
* Throws:
*     None
*/
	friend ostream &operator<<(ostream &os, const Stack &s);

private:
	void init();
	void copy(const Stack &other);
	void deleteAll();

	LinkedList *mList;
};

#endif
