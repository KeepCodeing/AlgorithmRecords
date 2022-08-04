#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int v, w;
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m;
int *dist;
vector<Node > graph[2510];
priority_queue<Node > que;
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
}
void dijkstra(int start) {
	// 注意初始化起点...
	dist[start] = 0;
	que.push((Node){start, 0}); 
	Node x(0, 0), y(0, 0);
	while (!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				que.push((Node){y.v, dist[y.v]});
			}
		}
	}
}
int main() {
	cin >> n >> m;
	initArr(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		// 无向图，注意.. 
		graph[v].push_back((Node){u, w});
	}
	dijkstra(1);
	cout << dist[n];
	delete[] dist;
	return 0;
} 
