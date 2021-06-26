#include "graph.h"

VNode* GetVNode(char data){
	VNode* v = new VNode;
	v->data = data;
	v->first = NULL;
	return v;

}

ArcNode* GetArcNode(char dest, int w = 1){
	ArcNode* arc = new ArcNode;
	arc->dest = dest;
	arc->next = NULL;
	arc->w= w;
	return arc;
}

void InitGraph(Graph& g){
	g.vexnum = 0;
	g.arcnum = 0;
	g.vertices.clear();
}

void AddNode(Graph& g, char v){
	if (g.vertices.find(v)== g.vertices.end()){
		VNode* temp = GetVNode(v);
		g.vertices[v] = temp;
		g.vexnum++;
	}
}

void AddEdge(Graph& g, char x, char y) {
	AddNode(g, x);
	AddNode(g, y);
	VNode* head = g.vertices[x];
	if (head->first == NULL) {
		head->first = GetArcNode(y);
	}
	else {
		ArcNode* p = head->first;
		ArcNode* pre = p;
		while (p!= NULL) {
			if (p->dest == y)
				return;//存在则返回
			pre = p;
			p = p->next;
		}
		pre->next = GetArcNode(y);
	}
	g.arcnum++;
}

void ShowGraph(Graph g){
	cout << "vecnum: " << g.vexnum << "  arcnum: " << g.arcnum << endl;
	map<char, VNode*>::iterator p = g.vertices.begin();
	for (p; p != g.vertices.end(); p++) {
		cout << p->first << " -->";
		VNode* head = p->second;
		ArcNode* arc = head->first;
		while (arc) {
			cout << arc->dest << " ";
			arc = arc->next;
		}
		cout << endl;
	}
}

int** GraphMatrix(Graph g){
	int** graph;
	graph = (int**)malloc(51 * sizeof(int*));
	for (int i = 0; i <= 50; i++) {
		graph[i] = (int*)malloc(50 * sizeof(int));
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			graph[i][j] = 99999;
		}
	}
	map<char, VNode*>::iterator p = g.vertices.begin();
	/*收集信息，加入矩阵*/
	p = g.vertices.begin();
	for (p; p != g.vertices.end(); p++) {
		VNode* head = p->second;
		ArcNode* arc = head->first;
		int arc1 = g.NodeIndex[p->first];
		while (arc) {
			int arc2 = g.NodeIndex[arc->dest];
			graph[arc1][arc2] = arc->w;
			arc = arc->next;
		}
	}
	return graph;
}
void ShowMatrix(int** g) {
	
	
	for (int i = 0; i <=10; i++) {
		cout.width(4);
		if (i == 0)
			cout << " ";
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= 10; i++) {
		cout.width(4);
		cout << i << " |";
		for (int j = 1; j <= 10; j++) {
			cout.width(4);
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}
 
Graph CreateGraph(vector<pair<char, char>> A, int type){
	Graph g;
	InitGraph(g);
	for (int i = 0; i < A.size(); i++) {
		if (type == 0) {
			AddEdge(g, A[i].first, A[i].second);
			AddEdge(g, A[i].second, A[i].first);
			g.arcnum--;
		}
		else {
			AddEdge(g, A[i].first, A[i].second);
		}
	}
	char v[50];
	int cnt = 1;
	map<char, VNode*>::iterator p = g.vertices.begin();
	for (p; p != g.vertices.end(); p++) {
		v[cnt++] = p->first;
	}
	sort(v + 1, v  + cnt);
	cnt = 1;
	for (int i = 1; i <= g.vexnum; i++) {
		g.NodeIndex[v[i]] = cnt++;
	}

	return g;
}

ArcNode* SearchArc(Graph g, char x, char y) {
	ArcNode* target = NULL;
	
	if (g.vertices.find(x) != g.vertices.end() && g.vertices.find(y) != g.vertices.end()) {
		VNode* vx = g.vertices[x];
		ArcNode* p = vx->first;
		while (p) {
			if (p->dest == y) {
				target = p;
			}
			p = p->next;
		}
	}
	return target;
}

void	SetWeight(Graph &g, char x, char y, int weight, int type) {
	ArcNode* arc1 = SearchArc(g, x, y);
	if(arc1)
		arc1->w = weight;
	if (type == 0) {
		arc1 = SearchArc(g, y, x);
		if (arc1)
			arc1->w = weight;
	}
}

void Dijkstra(Graph graph, int v0, vector<int>& path, vector<int>& dist){
	int vnum = graph.vexnum;
	int** g = GraphMatrix(graph);
	bool* S = new bool[vnum+1];
	int maxV = 99999;//不连通
	/*初始化*/
	for (int i = 1; i <= vnum; i++) {
		dist[i] = g[v0][i];
		S[i] = false;
		if (i != v0 && dist[i] < maxV)
			path[i] = v0;
		else
			path[i] = -1;
	}
	S[v0] = true;//v0加入S中
	dist[v0] = 0;
	for (int i = 1; i <= vnum; i++) {
		int minn = maxV;
		int u = v0;
		for (int j = 1; j <= vnum; j++) {
			if (S[j] == false && dist[j] < minn) {
				u = j;
				minn = dist[j];
			}
		}
		S[u] = true;

		for (int k = 1; k <= vnum; k++) {
			int w = g[u][k];
			if (S[k] == false && dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}

void Prim(Graph graph, vector<pair<int,int>>& T){
	vector<int> U;//顶点

	int vnum = graph.vexnum;
	bool *visit = new bool(vnum + 1);
	int have_visited = 0;
	int** g = GraphMatrix(graph);
	ShowMatrix(g);
	int maxn = 99999;

	for (int i = 1; i <= vnum; i++) {
		visit[i] = false;
	}
	U.push_back(1);
	visit[1] = true;
	have_visited++;

	while (have_visited < vnum) {
		int minn = maxn;
		int x_min, y_min;
		for (int i = 0; i < U.size(); i++) {
			int x;
			x = U[i];
			for (int k = 1; k <= vnum; k++) {
				//选择x在U中，k在V-U中的最小值
				if (g[x][k] != maxn && visit[k] == false && g[x][k] < minn) {
					x_min = x;
					y_min = k;
					minn = g[x][k];
				}
			}
		}
		T.push_back(pair<int, int>(x_min, y_min));
		visit[y_min] = true;
		have_visited++;
		U.push_back(y_min);

	}	
}

struct arc {
	int x;
	int y;
	int  w;
};

bool cmp(arc a, arc b) {
	return a.w < b.w ;
}


void InitUnion(vector<int>& A){
	for (int i = 0; i < A.size(); i++) {
		A[i] = -1;
	}
}
int FindRoot(vector<int> A, int x) {
	while (A[x] >= 0)
		x = A[x];
	return x;
}
void Union(vector<int>& A, int x, int y) {
	int temp = A[x] + A[y];
	if (abs(A[x] )< abs(A[y])) {	
		A[y] = temp;
		A[x] = y;
	}
	else {
		A[x] = temp;
		A[y] = x;

	}
}
void Kruskal(Graph graph, vector<pair<int, int>>& T) {
	int** g = GraphMatrix(graph);
	int vnum = graph.vexnum;
	int maxn = 99999;
	arc* E = new arc[graph.arcnum+1];

	int cnt = 0;
	for (int i = 1; i <= vnum; i++) {
		for (int j = i; j <= vnum; j++) {
			if (g[i][j] != maxn) {
				E[cnt].w = g[i][j];
				E[cnt].x = i;
				E[cnt].y = j;
				cnt++;
			}
		}
	}
	sort(E, E + graph.arcnum, cmp);
	vector<int>UnionSet(11);
	InitUnion(UnionSet);
	for (int i = 0; i < graph.arcnum; i++) {
		int root1 = FindRoot(UnionSet, E[i].x);
		int root2 = FindRoot(UnionSet, E[i].y);
		if (root1 == root2)
			continue;
		else {
			T.push_back(pair<int, int>(E[i].x, E[i].y));
			Union(UnionSet, root1, root2);

		}

	}

	

}

void BFS(Graph graph){
	vector<int> Q(101);
	int vnum = graph.vexnum;
	int** g = GraphMatrix(graph);
	bool* visit = new bool(vnum + 1);
	for (int i = 1; i <= vnum; i++) {
		visit[i] = false;
	}
	int rear = 0;
	int front = 0;
	Q[rear++] = 1;
	int maxn = 99999;
	visit[1] = true;
	while (front < rear) {
		int now = Q[front];
		cout << now << " ";
		for (int j = 1; j <= vnum; j++) {
			if (g[now][j] != maxn&& visit[j]==false) {
				Q[rear++] = j;
				visit[j] = true;
			}
		}
		front++;
	}
	cout << endl;
}

void DFSTravel(int** g, int v, int vnum, bool* &visit) {
	cout << v << " ";
	visit[v] = true;
	for (int i = 1; i <= vnum; i++) {
		if (!visit[i] && g[v][i] != 99999) {
			DFSTravel(g, i, vnum, visit);
		}
	}


}
void DFS(Graph graph) {
	int** g = GraphMatrix(graph);
	int vnum = graph.vexnum;
	bool* visit = new bool(vnum + 1);
	for (int i = 1; i <= vnum; i++) {
		visit[i] = false;
	}
	DFSTravel(g, 1, vnum, visit);



}