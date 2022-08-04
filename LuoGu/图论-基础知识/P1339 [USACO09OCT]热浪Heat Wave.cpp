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
vector<Node > graph[2510];
priority_queue<Node > que;
int n, m, s, t;
int *dist;
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
}
void dijkstra(int start) {
	// 又忘记了初始化起点距离，这样做的明显表现就是距离数组全部为初始值 
	dist[start] = 0;
	que.push((Node){start, 0});
	Node x(0, 0), y(0, 0);
	while (!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > y.w + dist[x.v]) {
				dist[y.v] = y.w + dist[x.v];
				// 这里应该是将得到的新最近点作为一个新的点入队 
				que.push((Node){y.v, dist[y.v]}); 
			}
		} 		
	}
}
int main() {
	cin >> n >> m >> s >> t;
	initArr(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		// 被坑了，这里是个无向图... 
		graph[v].push_back((Node){u, w});
	}
	dijkstra(s);
	cout << dist[t];
	delete[] dist;
	return 0;
}
