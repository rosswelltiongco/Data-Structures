#ifndef BST_H
#define BST_H

#include <vector>
using namespace std;


class BST
{
public:
	enum TraversalOrder { PREORDER, INORDER, POSTORDER };

	BST();
	void add(int key, string data);
	bool isPresent(int key) const;
	vector<string> getTraversal(TraversalOrder order) const;
	double evaluate();
	double evaluateAt(int key);

private:

	class Node
	{
		friend class BST;

	}
	
	Node *find(int key);  // Delete if you don't want it.
	Node *mRoot;		  // MUST use this

};

#endif
