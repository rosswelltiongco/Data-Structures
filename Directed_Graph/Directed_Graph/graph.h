#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:

	Graph();

	void addEdge(int from, int to);  //calls node addedge
	void outputNodes() const;   //prints edges
	void outputEdges() const;   //prints edges
	void DFS(int nodeNumberFrom); //do later

private:

	class Node
	{

		friend Graph;

	public:
		Node(int nodeNumber);
		void addEdge(Node *to); //adds to madjlist
		void DFS();  //do later
		bool isAdjTo(int to);  //checks madjlist

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
