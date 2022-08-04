#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int v, w;
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		// Prim不关心节点编号，只关心权值大小，这样写会出错 
		// if (v != n.v) return v < n.v;
		return w > n.w;
	}
};

vector<Node > graph[10010];
priority_queue<Node > que;
// int *dist;
bool *visited;
int n, m, s;
int result = 0, tot = 0;
void initArr(int n) {
	// dist = new int[n + 1];
	visited = new bool[n + 1];
	// fill(dist, dist + n + 1, INF);
	fill(visited, visited + n + 1, false);
}
void Prim(int start) {
	// dist[start] = 0;
	que.push((Node){start, 0});
	// 当队列不空且还有顶点没有防问 
	Node x(0, 0);
	while(!que.empty() && tot < n) {
		x = que.top();que.pop();
		if (!visited[x.v]) {
			visited[x.v] = true;
			tot++;
			result += x.w;
			// dist[x.v] = x.w;
			cout<<"x.v = "<< x.v <<"  x.w =  "<< x.w <<" result =  "<< result <<"\n";
			for (int i = 0; i < graph[x.v].size(); i++) {
				if (!visited[graph[x.v][i].v]) que.push(graph[x.v][i]);
			}
		}
	}
}
int main() {
	cin >> n >> m >> s;
	int u, v, w;
	initArr(n);
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		// 无向图
		graph[v].push_back((Node){u, w});
	}
	Prim(s);
	// for (int i = 1; i <= n; i++) cout << dist[i] << (i != n ? " " : "");
	cout << result << endl;
	delete[] visited;//, dist;
	return 0;
}

/*
6 9 1
1 2 34
1 6 19
1 3 46
2 5 12
3 6 25
3 4 17
4 6 25
4 5 38
5 6 26
*/
