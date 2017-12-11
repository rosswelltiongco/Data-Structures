//Rosswell Tiongco, Assignment: #10, 016091762
#include "graph.h"
#include <algorithm>
#include <iostream>

static const string DISCONNECT = "Causes disconnected graph";
static const string REDUNDANT = "Vertex is already adjacent";

////////////////////////////////////
//      Public Methods            //
////////////////////////////////////

Graph::Graph()
{
	//Constructor does nothing
}

void Graph::addEdge(int from, int to)
{

	//If graph is empty, make 'from' node
	if (mNodes.size() == 0)
	{
		Node *firstNode = new Node(from);
		mNodes.push_back(firstNode);
	}

	//Exception handling to check for nonexistant from node
	//If from doens't exist, AND graph already has nodes, throw an error
	else if (std::find(mNodes.begin(), mNodes.end(), find(from)) == mNodes.end())
	{
		throw DISCONNECT;
	}

	//If to node doesn't already exist, make it before adding a bridge
	if (std::find(mNodes.begin(), mNodes.end(), find(to)) == mNodes.end())
	{
		Node *toNode = new Node(to);
		mNodes.push_back(toNode);
	}

	//Adds edge between nodes if there is not already a connection
	if (find(from)->isAdjTo(to))
	{
		throw REDUNDANT;
	}
	else
	{
		Node* vertex = find(from);
		vertex->addEdge(find(to));
	}
}
void Graph::outputNodes() const
{
	cout << "Vertices: ";

	for (int i = 0; i < mNodes.size(); i++)
	{
		cout << mNodes.at(i)->mNodeNumber << " ";
	}
	
	cout << endl;
}
void Graph::outputEdges() const
{
	cout << "Edges:" << endl;

	//Iterating through all nodes
	for (int i = 0; i < mNodes.size(); i++)
	{
		//Iterating through each nodes' adjacency list
		for (int j = 0; j < (mNodes.at(i)->mAdjList).size(); j++)
		{
			cout << "(" << mNodes.at(i)->mNodeNumber << "," << mNodes.at(i)->mAdjList.at(j)->mNodeNumber << ") ";
		}
		cout << endl; //Separation between each set of connections
	}
	cout << endl; //Separation after all connections
}
void Graph::DFS(int nodeNumberFrom)
{
	//call method
	/*
	mark all unvisited
	check if node has been visited, return, if not change mvisited
	output node visited
	if node adjlist is empty,
	*/
}

////////////////////////////////////
//     Node Public Methods        //
////////////////////////////////////
Graph::Node::Node(int nodeNumber)
{
	mNodeNumber = nodeNumber;
	mVisited = true;
}

void Graph::Node::addEdge(Node *to)
{
	mAdjList.push_back(to);
}

void Graph::Node::DFS()
{

}

bool Graph::Node::isAdjTo(int to)
{
	for (int i = 0; i < mAdjList.size(); i++)
	{
		if (mAdjList.at(i)->mNodeNumber == to)
		{
			return true;
		}
	}
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
	for (int i = 0; i < mNodes.size(); i++)
	{
		if (mNodes.at(i)->mNodeNumber == nodeNumber)
		{
			return mNodes.at(i);
		}
	}

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