//CPP for shortest path
#include "Wasalny.h"
#include "Wasalny.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>
//#include <string.h>
#include <string>
using namespace std;

Dijkstra::Dijkstra()
{
	infinity = 0x3f3f3f3f, CurrentNumberOfNodes = 15, CountNodes = 15;
	Distance = new int[100];
	parent = new int[100];
	adj = new vector<pair<int, int>>[100];

	distinationName[0] = "Al-Asher";
	distinationName[1] = "Al-Ahly";
	distinationName[2] = "Al-Tamen";
	distinationName[3] = "Akher-Fakhry";
	distinationName[4] = "Mid-Fakhry";
	distinationName[5] = "Awel-Fakhry";
	distinationName[6] = "Akher-Makram";
	distinationName[7] = "Mid-Makram";
	distinationName[8] = "Awel-Makram";
	distinationName[9] = "Akher-Abbas";
	distinationName[10] = "Mid-Abbas";
	distinationName[11] = "Awel-Abbas";
	distinationName[12] = "Al-Sabe3";
	distinationName[13] = "Al-Taiaran";
	distinationName[14] = "Al-Sadis";

	adj[0].push_back({ 3,2 });
	adj[0].push_back({ 8,12 });
	adj[1].push_back({ 5,2 });
	adj[1].push_back({ 4, 5 });
	adj[2].push_back({ 3, 0 });
	adj[2].push_back({ 5, 1 });
	adj[2].push_back({ 2, 3 });
	adj[3].push_back({ 2, 2 });
	adj[3].push_back({ 1, 4 });
	adj[3].push_back({ 1, 6 });
	adj[4].push_back({ 1, 3 });
	adj[4].push_back({ 1, 7 });
	adj[4].push_back({ 1, 5 });
	adj[5].push_back({ 1, 4 });
	adj[5].push_back({ 1, 8 });
	adj[5].push_back({ 4, 1 });
	adj[6].push_back({ 1, 3 });
	adj[6].push_back({ 2, 9 });
	adj[6].push_back({ 2, 7 });
	adj[7].push_back({ 2, 6 });
	adj[7].push_back({ 2, 8 });
	adj[7].push_back({ 1, 4 });
	adj[7].push_back({ 2, 10 });
	adj[8].push_back({ 2, 7 });
	adj[8].push_back({ 3, 11 });
	adj[8].push_back({ 1, 5 });
	adj[9].push_back({ 5, 12 });
	adj[9].push_back({ 2, 6 });
	adj[9].push_back({ 3, 10 });
	adj[10].push_back({ 3, 9 });
	adj[10].push_back({ 1, 11 });
	adj[10].push_back({ 2, 7 });
	adj[10].push_back({ 2, 13 });
	adj[11].push_back({ 1, 10 });
	adj[11].push_back({ 3, 8 });
	adj[11].push_back({ 3,14 });
	adj[12].push_back({ 8 , 0 });
	adj[12].push_back({ 4, 13 });
	adj[12].push_back({ 5, 9 });
	adj[13].push_back({ 2, 10 });
	adj[13].push_back({ 4, 12 });
	adj[13].push_back({ 5, 14 });
	adj[14].push_back({ 5, 13 });
	adj[14].push_back({ 3, 11 });
}

void Dijkstra::shortestpathFrom(int src)
{
	for (int i = 0; i < CurrentNumberOfNodes; i++)
		Distance[i] = infinity;
	Distance[src] = 0;
	priority_queue<pair<int, int>>visited;
	visited.push({ 0,src });
	while (!visited.empty())
	{
		int NodeID = visited.top().second;
		int CurrentCost = -1 * visited.top().first;
		visited.pop();
		if (Distance[NodeID] != CurrentCost) continue;
		for (pair<int, int> itr : adj[NodeID])
		{
			int Costbetweenadj = itr.first;
			int adjNode = itr.second;
			if (Distance[adjNode] > Distance[NodeID] + Costbetweenadj)
			{
				Distance[adjNode] = Distance[NodeID] + Costbetweenadj;
				visited.push({ -1 * Distance[adjNode],adjNode });
				parent[adjNode] = NodeID;
			}
		}
	}
}


void Dijkstra::printpath(int start, int end, vector<int>& V)
{
	if (start == end)
	{
		V.push_back(start);
		//cout << distinationName[start] << " --> ";
	}
	else {
		printpath(start, parent[end], V);
		V.push_back(end);
		//cout << distinationName[end] << " --> ";
	}
}

void Dijkstra::DisplayGragh()
{
	if (CountNodes == 0)
		cout << "Graph is empty!" << endl;
	else
	{
		cout << "We have " << CountNodes << " of distinations" << endl;
		int count = 1;
		for (int i = 0; i < CurrentNumberOfNodes; i++)
		{
			if (distinationName[i] == "")
				continue;
			cout << count << " -  You can go to " << distinationName[i] << " from :" << endl << endl << endl;
			for (int j = 0; j < adj[i].size(); j++)
			{
				cout << j + 1 << " >> " << distinationName[adj[i][j].second] << " and the cost will be " << adj[i][j].first << " km" << endl;
			}
			cout << endl << endl;
			count++;
		}
	}
}

void Dijkstra::AddNode()
{
	for (int i = 0; i < CurrentNumberOfNodes; i++) {
		if (distinationName[i].empty())
			continue;
		if (i < 10)
			cout << i << "       --------->        " << distinationName[i] << endl;
		else
			cout << i << "      --------->        " << distinationName[i] << endl;
	}
	int distance_added, addednode;
	cout << "Enter Node name you want to be added: ";
	string name;
	cin >> name;
	distinationName[CurrentNumberOfNodes] = name;
	distinationNumber[name] = CurrentNumberOfNodes;
	cout << "Enter distance and Number of connected node:" << endl;
	cin >> distance_added >> addednode;
	adj[CurrentNumberOfNodes].push_back({ distance_added,addednode });
	adj[addednode].push_back({ distance_added,CurrentNumberOfNodes });
	cout << "Do you want add another connection ?(y/n)" << endl;
	char y;
	cin >> y;
	while (y == 'y') {
		cout << "Enter distance and Number of connected node:" << endl;
		cin >> distance_added >> addednode;
		adj[CurrentNumberOfNodes].push_back({ distance_added,addednode });
		adj[addednode].push_back({ distance_added,CurrentNumberOfNodes });
		cout << "Do you want add another connection ?(y/n)" << endl;
		cin >> y;
	}
	CurrentNumberOfNodes++;
	CountNodes++;
	cout << endl;
}

void Dijkstra::deleteNode()
{
	for (int i = 0; i < CurrentNumberOfNodes; i++) {
		if (distinationName[i].empty())
			continue;
		if (i < 10)
			cout << i << "       --------->        " << distinationName[i] << endl;
		else
			cout << i << "      --------->        " << distinationName[i] << endl;
	}
	int value;
	cout << "Enter The Node Number you want to be deleted: "; cin >> value;
	int i = 0;
	for (pair<int, int> itr : adj[value])
	{
		i = 0;
		int Costbetweenadj = itr.first;
		int adjNode = itr.second;
		pair <int, int> checkk = { Costbetweenadj, value };
		for (pair<int, int> iter : adj[adjNode])
		{
			if (iter.second == value)
				adj[adjNode].erase(adj[adjNode].begin() + i);
			i++;
		}

	}
	adj[value].erase(adj[value].begin(), adj[value].end());
	string name = distinationName[value];
	distinationName.erase(value);
	distinationNumber.erase(name);
	CountNodes--;
}

void Dijkstra::update()
{
	int choice;
	cout << "Press: (1) To Delete Node\n       (2) To Add Node" << endl;
	cin >> choice;
	cout << "Node Names to Numbers Map:" << endl;
	for (int i = 0; i < CurrentNumberOfNodes; i++) {
		if (distinationName[i].empty())
			continue;
		if (i < 10)
			cout << i << "       --------->        " << distinationName[i] << endl;
		else
			cout << i << "      --------->        " << distinationName[i] << endl;
	}
	if (choice == 1)
		deleteNode();
	else
		AddNode();
}

void Dijkstra::deleteGragh()
{
	adj->clear();
	distinationName.clear();
	distinationNumber.clear();
	delete[] Distance;
	Distance = new int[100];
	delete[] parent;
	parent = new int[100];
	CurrentNumberOfNodes = 0;
	CountNodes = 0;
}

Dijkstra::~Dijkstra()
{
}


BFS::BFS(int N)
{
	vector<Edge> edges;
	edges.push_back(Edge(0, 12, 8));
	edges.push_back(Edge(12, 0, 8));
	edges.push_back(Edge(0, 2, 3));
	edges.push_back(Edge(2, 0, 3));
	edges.push_back(Edge(2, 1, 5));
	edges.push_back(Edge(1, 2, 5));
	edges.push_back(Edge(2, 3, 2));
	edges.push_back(Edge(3, 2, 2));
	edges.push_back(Edge(1, 5, 4));
	edges.push_back(Edge(5, 1, 4));
	edges.push_back(Edge(3, 4, 1));
	edges.push_back(Edge(4, 3, 1));
	edges.push_back(Edge(4, 5, 1));
	edges.push_back(Edge(5, 4, 1));
	edges.push_back(Edge(3, 6, 1));
	edges.push_back(Edge(6, 3, 1));
	edges.push_back(Edge(4, 7, 1));
	edges.push_back(Edge(7, 4, 1));
	edges.push_back(Edge(5, 8, 1));
	edges.push_back(Edge(8, 5, 1));
	edges.push_back(Edge(6, 7, 2));
	edges.push_back(Edge(7, 6, 2));
	edges.push_back(Edge(7, 8, 2));
	edges.push_back(Edge(8, 7, 2));
	edges.push_back(Edge(6, 9, 2));
	edges.push_back(Edge(9, 6, 2));
	edges.push_back(Edge(7, 10, 2));
	edges.push_back(Edge(10, 7, 2));
	edges.push_back(Edge(8, 11, 3));
	edges.push_back(Edge(11, 8, 3));
	edges.push_back(Edge(9, 10, 3));
	edges.push_back(Edge(10, 9, 3));
	edges.push_back(Edge(10, 11, 1));
	edges.push_back(Edge(11, 10, 1));
	edges.push_back(Edge(9, 12, 5));
	edges.push_back(Edge(12, 9, 5));
	edges.push_back(Edge(10, 13, 2));
	edges.push_back(Edge(13, 10, 2));
	edges.push_back(Edge(11, 14, 3));
	edges.push_back(Edge(14, 11, 3));
	edges.push_back(Edge(12, 13, 4));
	edges.push_back(Edge(13, 12, 4));
	edges.push_back(Edge(13, 14, 5));
	edges.push_back(Edge(14, 13, 5));

	// resize the vector to 3*N elements of type vector<int>
	adjList.resize(8 * N);

	distinationNames[0] = "Al-Asher";
	distinationNames[1] = "Al-Ahly";
	distinationNames[2] = "Al-Tamen";
	distinationNames[3] = "Akher-Fakhry";
	distinationNames[4] = "Mid-Fakhry";
	distinationNames[5] = "Awel-Fakhry";
	distinationNames[6] = "Akher-Makram";
	distinationNames[7] = "Mid-Makram";
	distinationNames[8] = "Awel-Makram";
	distinationNames[9] = "Akher-Abbas";
	distinationNames[10] = "Mid-Abbas";
	distinationNames[11] = "Awel-Abbas";
	distinationNames[12] = "Al-Sabe3";
	distinationNames[13] = "Al-Taiaran";
	distinationNames[14] = "Al-Sadis";

	// add edges to the undirected graph
	for (auto& edge : edges)
	{
		int v = edge.source;
		if (v == 4)
		{
			v = 4;
		}
		int u = edge.dest;
		int weight = edge.weight;

		// create two new vertices if the weight
		// of edge is more than 1. Also, split the edge (v, u) into (v, v+N),
		// (v+N, v+2N) and (v+2N, u) each having weight 1
		if (weight == 8)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(v + 2 * N);
			adjList[v + 2 * N].push_back(v + 3 * N);
			adjList[v + 3 * N].push_back(v + 4 * N);
			adjList[v + 4 * N].push_back(v + 5 * N);
			adjList[v + 5 * N].push_back(v + 6 * N);
			adjList[v + 6 * N].push_back(v + 7 * N);
			adjList[v + 7 * N].push_back(u);
		}
		else if (weight == 6)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(v + 2 * N);
			adjList[v + 2 * N].push_back(v + 3 * N);
			adjList[v + 3 * N].push_back(v + 4 * N);
			adjList[v + 4 * N].push_back(v + 5 * N);
			adjList[v + 5 * N].push_back(u);
		}
		else if (weight == 5)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(v + 2 * N);
			adjList[v + 2 * N].push_back(v + 3 * N);
			adjList[v + 3 * N].push_back(v + 4 * N);
			adjList[v + 4 * N].push_back(u);
		}
		else if (weight == 4)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(v + 2 * N);
			adjList[v + 2 * N].push_back(v + 3 * N);
			adjList[v + 3 * N].push_back(u);
		}
		else if (weight == 3)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(v + 2 * N);
			adjList[v + 2 * N].push_back(u);
		}
		else if (weight == 2)
		{
			adjList[v].push_back(v + N);
			adjList[v + N].push_back(u);
		}
		else
			adjList[v].push_back(u);
	}
}

// Recursive function to print path of given vertex v from the source vertex
void BFS::printPath(vector<int> const& predecessor, int v, int& cost, int N)
{
	if (v < 0)
		return;

	printPath(predecessor, predecessor[v], cost, N);
	cost++;

	// consider only original nodes present in the graph
	if (v < N)
		cout << distinationNames[v] << "   ";
}

// Perform BFS on graph starting from vertex source
void BFS::bfs(BFS const& graph, int source, int dest, int N)
{
	// stores vertex is discovered in BFS traversal or not
	vector<bool> discovered(8 * N, false);

	// mark source vertex as discovered
	discovered[source] = true;

	// predecessor[] stores predecessor information. It is used
	// to trace least cost path from destination back to source.
	vector<int> predecessor(8 * N, -1);

	// create a queue used to do BFS and push source vertex
	// into the queue
	queue<int> q;
	q.push(source);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and print it
		int curr = q.front();
		q.pop();

		// if destination vertex is reached
		if (curr == dest)
		{
			int cost = -1;
			cout << "Least cost path between " << distinationNames[source] << " and " <<
				distinationNames[dest] << " is " << endl; printPath(predecessor, dest, cost, N);
			cout << endl << "having cost " << cost << endl;
		}

		// do for every adjacent edge of current vertex
		for (int v : graph.adjList[curr])
		{
			if (!discovered[v])
			{
				// mark it discovered and push it into queue
				discovered[v] = true;
				q.push(v);

				// set curr as predecessor of vertex v
				predecessor[v] = curr;
			}
		}
	}
}

