#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph
{
public:

	Graph();

	void addEdge(int from, int to);
	void outputNodes() const;
	void outputEdges() const;
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
