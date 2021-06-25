#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#define MaxNum  1000
using namespace std;


struct ArcNode {
	char dest;
	int w;
	struct ArcNode* next;
};

struct VNode {
	char data;
	ArcNode* first;
};


struct Graph {
	map<char, VNode*> vertices;
	int vexnum, arcnum;
	map<char, int> NodeIndex;//名称-编号
};

VNode* GetVNode(char data);
ArcNode* GetArcNode(char dest, int w);
void InitGraph(Graph& g);
void AddNode(Graph& g, char v);
void AddEdge(Graph& g, char x, char y);
void ShowGraph(Graph g);
int** GraphMatrix(Graph g);
void ShowMatrix(int** g);

/*0无向图，1 有向图*/
Graph CreateGraph(vector<pair<char, char>> A, int type);
void SetWeight(Graph& g, char x, char y, int weight, int type);
void Dijkstra(Graph g, int v0, vector<int>& path, vector<int>& dist);
void Prim(Graph g, vector<pair<int,int>>& T);
void Kruskal(Graph graph, vector<pair<int, int>>& T);
void BFS(Graph graph);
void DFS(Graph graph);