#pragma once
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include<string>
using namespace std;

//extern bool isFound;

class Dijkstra
{
public:
	int infinity, CurrentNumberOfNodes, SourceNode, CountNodes;
	int* Distance, * parent;
	map<int, string> distinationName;
	map<string, int> distinationNumber;
	vector<pair<int, int>>* adj;
	void shortestpathFrom(int);
	void printpath(int, int, vector<int>&);
	void update();
	void AddNode();
	void deleteNode();
	void deleteGragh();
	void DisplayGragh();
	Dijkstra();
	~Dijkstra();
};

// data structure to store graph edges
struct Edge {
	int source, dest, weight;
	Edge() {}
	Edge(int src, int destination, int w)
	{
		source = src;
		dest = destination;
		weight = w;
	}
};

class BFS
{
public:
	map<int, string> distinationNames;
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	BFS(int N);
	void printPath(vector<int> const& predecessor, int v, int& cost, int N);
	void bfs(BFS const& graph, int source, int dest, int N);
};

class car {
public:
	string name;
	string number;
	string model;
	string color;

	car();
	~car();
};

class customer;

class Driver
{
public:
	vector <Driver> V;
	string driver_name;
	string pass;
	string phone;
	string pref_Destination, curr_Destination;
	int prefnum, currnum;
	float rate;
	car c;
	Dijkstra d;
	map<string, int> distinationNumber;
	//vector<Driver> driversVec;

	Driver();
	void registerFn();
	void login(customer&);
	void display();
	void SaveToVector();
	float updateRate(float);
	~Driver();
};

class customer
{
public:
	string username;
	string phonenum;
	string getphone;
	string password;
	string email;
	string prefDes;
	string currLoc;
	string currposition;
	string distination;

	customer();
	void orderTrip(Driver&);
	void registerf();
	void login();
	//void whereto(string);
	//void selectcar();
	void display();
	//~customer();
};

