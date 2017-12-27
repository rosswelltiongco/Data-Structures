#ifndef BST_H
#define BST_H

#include <vector>
using namespace std;

/*
	Binary Search Tree

	A binary search tree that can add values by using a tree. Using the key and value,
	the tree can be evaluated through its postfix notation
*/
class BST
{
public:
	enum TraversalOrder { PREORDER, INORDER, POSTORDER };

/*
Method Name:  BST()

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
	BST();

/*
Method Name:  add(key, data)

		Adds a node containing data based on the key

	Input Only:
		key - the node's key
		data - Node content
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
	void add(int key, string data);

/*
Method Name:  isPresent(key)

		Checks to see if a node is present based on its key

	Input Only:
		key - how the data will be found
	Input & Output:
		None
	Output Only:
		None
	Returns:
		boolean value indicating if node is found in BST
	Side Effects:
		None
	Throws:
		None
*/
	bool isPresent(int key) const;

/*
Method Name:  getTraversal(order)

		Gives notation for BST

	Input Only:
		order - notation method
	Input & Output:
		None
	Output Only:
		None
	Returns:
		the bst in the desired notation
	Side Effects:
		None
	Throws:
		None
*/
	vector<string> getTraversal(TraversalOrder order) const;

/*
Method Name:  evaluate()

		Finds the computation of the entire tree

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		Value of entire tree
	Side Effects:
		None
	Throws:
		None
*/
	double evaluate();

/*
Method Name:  evaluate(key)

		Gives value of a subtree based on key

	Input Only:
		key - indicates where to take the value from
	Input & Output:
		None
	Output Only:
		None
	Returns:
		value of a certain subtree
	Side Effects:
		None
	Throws:
		None
*/
	double evaluateAt(int key);

private:

	class Node
	{
		friend class BST;
	public:
		Node(int key, string data);
		void add(int key, string data);
		bool isPresent(int key) const;
		void getTraversal(TraversalOrder order, vector<string> &answer) const;
		double evaluate(Node *root);
		double evaluateAt(int key);

	private:
		Node* mLeft;
		Node* mRight;
		string mData;	
		int mKey;
		double mValue;
	};
	
	//BST::Node * find(int key)const; //Not used
	Node *mRoot;

};

#endif