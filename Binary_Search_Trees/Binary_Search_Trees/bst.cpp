#include "bst.h"
#include <iostream>
#include <string>
enum TraversalOrder { PREORDER, INORDER, POSTORDER };

/////////////////////////////////////////////////////
//////////       BST Public           ///////////////
/////////////////////////////////////////////////////
BST::BST()
{
	//Default constructor does nothing
}

void BST::add(int key, string data)
{
	if (mRoot == NULL)
	{
		mRoot = new Node(key, data);
	}
	else
	{
		mRoot->add(key,data);
	}
}

bool BST::isPresent(int key) const
{
	if (mRoot == NULL)
		return false;
	else
		return mRoot->isPresent(key);
}

vector<string> BST::getTraversal(TraversalOrder order) const
{
	vector<string> returnVector;
	if (mRoot == NULL)
	{
		return returnVector;
	}
	else
	{
		mRoot->getTraversal(order, returnVector);
		return returnVector;
	}
}

double BST::evaluate()
{
	if (mRoot == NULL)
	{
		return 0;
	}
	else
	{
		return mRoot->evaluate(mRoot);
	}
}

double BST::evaluateAt(int key)
{
	if (mRoot == NULL)
	{
		return 0;
	}
	else
	{
		return mRoot->evaluateAt(key);
	}
}

/////////////////////////////////////////////////////
//////////       Node Public           //////////////
/////////////////////////////////////////////////////

BST::Node::Node(int key, string data)
{
	mLeft = mRight = 0;
	mKey = key;
	mData = data;
	mValue = 0;
}

void BST::Node::add(int key, string data)
{
	if (key < mKey)
	{
		if (mLeft == 0) mLeft = new Node(key, data);
		else return mLeft->add(key, data);
	}
	else
	{
		if (mRight == 0) mRight = new Node(key, data);
		else mRight->add(key, data);
	}
}

bool BST::Node::isPresent(int key) const
{
	if (key == this->mKey)
		return true;
	else if (key < this->mKey) {
		if (mLeft == NULL)
			return false;
		else
			return mLeft->isPresent(key);
	}
	else if (key > this->mKey) {
		if (mRight == NULL)
			return false;
		else
			return mRight->isPresent(key);
	}
	return false;
}

void BST::Node::getTraversal(TraversalOrder order, vector<string>& answer) const
{
	if (this != NULL) {

		if (order == PREORDER) answer.push_back(mData);
		mLeft->getTraversal(order, answer);
		if (order == INORDER) answer.push_back(mData);
		mRight->getTraversal(order, answer);
		if (order == POSTORDER) answer.push_back(mData);
	}
}

double BST::Node::evaluate(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (!root->mLeft && !root->mRight)
	{
		return stoi(root->mData);
	}

	double lVal = evaluate(root->mLeft);
	double rVal = evaluate(root->mRight);

	if (root->mData == "+") return lVal + rVal;
	if (root->mData == "-") return lVal - rVal;
	if (root->mData == "*") return lVal * rVal;
	if (root->mData == "/") return lVal / rVal;
}

double BST::Node::evaluateAt(int key)
{
	if (key == this->mKey)
		return evaluate(this);
	else if (key < this->mKey) {
		if (mLeft == NULL)
			return false;
		else
			return mLeft->evaluateAt(key);
	}
	else if (key > this->mKey) {
		if (mRight == NULL)
			return false;
		else
			return mRight->evaluateAt(key);
	}
	return false;

}
/*
Not used
BST::Node* BST::find(int key) const
{
	Node *current = mRoot;

	while (current != NULL)
	{
		if (key == current->mKey) return current;
		else if (key < current->mKey) return current->mLeft;
		else current = current->mRight;
	}
	return NULL;
}
*/