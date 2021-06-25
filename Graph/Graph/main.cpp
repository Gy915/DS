#include"graph.h"


int main() {

	Graph g;
	InitGraph(g);
	vector<pair<char, char>>A;
	int weight[11] = { 5,2,6,6,9,2,4,5,7, 2};
	A.push_back(pair<char, char>('1', '2'));
	A.push_back(pair<char, char>('2', '3'));
	A.push_back(pair<char, char>('3', '5'));
	A.push_back(pair<char, char>('5', '2'));
	A.push_back(pair<char, char>('2', '4'));
	A.push_back(pair<char, char>('4', '1'));
	A.push_back(pair<char, char>('1', '5'));
	A.push_back(pair<char, char>('5', '6'));
	A.push_back(pair<char, char>('5', '4'));
	A.push_back(pair<char, char>('6', '2'));
	g = CreateGraph(A, 1);
	for (int i = 0; i < A.size(); i++) {
		SetWeight(g, A[i].first, A[i].second, weight[i], 1);
	}
	
	int** g2 = GraphMatrix(g);
	ShowMatrix(g2);
	vector<int>dist(11);
	vector<int>path(11);
	Dijkstra(g, 1, path, dist);
	cout << dist[2];

	vector<pair<char, char>>B;
	int weight2[11] = {6,1,5,5,3,5,6,4,2,6};
	B.push_back(pair<char, char>('1', '2'));
	B.push_back(pair<char, char>('1', '3'));
	B.push_back(pair<char, char>('1', '4'));
	B.push_back(pair<char, char>('2', '3'));
	B.push_back(pair<char, char>('2', '5'));
	B.push_back(pair<char, char>('3', '4'));
	B.push_back(pair<char, char>('3', '5'));
	B.push_back(pair<char, char>('3', '6'));
	B.push_back(pair<char, char>('4', '6'));
	B.push_back(pair<char, char>('5', '6'));

	Graph G2 = CreateGraph(B, 0);
	for (int i = 0; i < B.size(); i++) {
		SetWeight(G2, B[i].first, B[i].second, weight2[i], 0);
	}
	ShowGraph(G2);
	vector<pair<int, int>>T;
	Kruskal(G2, T);
	for (int i = 0; i < T.size(); i++) {
		cout << T[i].first << " " << T[i].second << endl;
	}
	DFS(G2);
	float f;
	f = 0.1 + 0.2;
	cout << f << endl;
} 