#include "graph.h"
#include <algorithm>

////////////////////////////////////
//      Public Methods            //
////////////////////////////////////

Graph::Graph()
{
	//Constructor does nothing
}

void Graph::addEdge(int from, int to)
{
	//calls method

}
void Graph::outputNodes() const
{
	//calls method
}
void Graph::outputEdges() const
{
	//calls method
}
void Graph::DFS(int nodeNumberFrom)
{
	//call method
}

////////////////////////////////////
//     Node Public Methods        //
////////////////////////////////////
Graph::Node::Node(int nodeNumber)
{
	mNodeNumber = nodeNumber;
	mVisited = false;
}

void Graph::Node::addEdge(Node *to)
{
	//if graph is empty, its okay if first node doesn't exist
	//if not empty, from node must exist, else throw an error
	mAdjList.push_back(to);
}

void Graph::Node::DFS()
{
	/*
	mark all unvisited
	check if node has been visited, return, if not change mvisited
	output node visited
	if node adjlist is empty,
	*/
}

bool Graph::Node::isAdjTo(int to)
{
	//if (std::find(this->mAdjList.begin(),this->mAdjList.end(), to)) return true;
	//std::find(this->mAdjList.begin(), this->mAdjList.end(), to);
	return false;
}

void Graph::markAllUnvisited()
{
	for (int i = 0; i < mNodes.size(); i++)
	{
		mNodes.at(i)->mVisited = false;
	}
}

Graph::Node * Graph::find(int nodeNumber) const
{
	Node * lel = new Node(5);
	return lel;
}

vector<int> Graph::getNodeNumbers() const
{
	vector<int> nodeNumbers;
	for (int i = 0; i < mNodes.size(); i++)
	{
		nodeNumbers.push_back(mNodes.at(i)->mNodeNumber);
	}
	return nodeNumbers;
}