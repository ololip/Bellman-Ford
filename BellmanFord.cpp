// BellmanFord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ofstream outFile;

class Graph
{
	vector<vector<pair<int, int>>> edgeList;
	int *distance; 
public:
	Graph(int n)
	{
		edgeList.resize(n);
		distance = new int[n];
		distance[0] = 0;
		for (int i = 1; i < n; i++)
			distance[i] = INT_MAX;
	}
	void addEdge(int u, int v, int w)
	{
		edgeList[u].push_back(make_pair(v, w));
	}
	void BellmanFord(int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (pair<int, int> edge : edgeList[i])
			{
				if (distance[i] != INT_MAX && distance[i] + edge.second < distance[edge.first])
					distance[edge.first] = distance[i] + edge.second;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (distance[i] == INT_MAX)
				outFile << "0 ";
			else
				outFile<< distance[i] << " ";
		}
		outFile << endl;
	}
};


int main()
{
	int test, n, w;
	cin >> test;


	outFile.open("outFile.txt");
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		Graph graph(n);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> w;
				if(w!=0)
					graph.addEdge(j, k, w);
			}
			
		}
		for (int j = 1; j < n; j++)
			graph.BellmanFord(n);
		outFile << endl;
	}
	
	outFile.close();
}