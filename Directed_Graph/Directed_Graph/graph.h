#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

/*
* Graph
*
*      Contains subclass of node to represent vertices
*	   Edges to each other node represented in node class
*/
class Graph
{
public:

	/*
	* Method Name:  Graph()
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
	Graph();

	/*
	* Method Name:  addEdge
	*
	*    Adds a one way edge between 'from' and 'to' nodes
	*
	* Input Only:
	*      from – Node to connect from
	*      to – Node to connnect to
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
	*     DISCONNECT – The from node must already exist unless it is the first 
					   node, otherwise the graph will become disconnected
	*     REDUNDANT - Will not create the exact same connection twice
	*/
	void addEdge(int from, int to);

	/*
	* Method Name:  outputNodes
	*
	*    Displays the number of each node
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
	*     Prints each nodes' number
	*
	* Throws:
	*     None
	*/
	void outputNodes() const;


	/*
	* Method Name:  outputEdges()
	*
	*    Displays all the connections between each node
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
	*     Prints every connection between every node
	*
	* Throws:
	*     None
	*/
	void outputEdges() const;

	/*
	* Method Name:  DFS(nodeNumberFrom)
	*
	*    Displays the results of a depth first search from a certain node
	*
	* Input Only:
	*      nodeNumberFrom - the node to perform DFS on
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
	*     Prints the results of the DFS from the recursive helper function
	*
	* Throws:
	*     None
	*/
	void DFS(int nodeNumberFrom);

private:

	class Node
	{

		friend Graph;

	public:
		Node(int nodeNumber);
		void addEdge(Node *to);
		void DFS();
		bool isAdjTo(int to);

	private:
		int mNodeNumber;
		vector<Node *> mAdjList;  
		bool mVisited;
	};

	void markAllUnvisited();
	Node *find(int nodeNumber) const;
	vector<int> getNodeNumbers() const;

	vector<Node *> mNodes;

};


#endif
