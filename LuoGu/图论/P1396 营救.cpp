#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 看了半天题目搞不懂怎么求出的2，其实题目是求的最短路径中的最大权值.. 
// 不是这样哦！这个题并非裸的最短路... 

struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m, s, t;
int *dist;
bool *visited;
vector<Node > graph[10010];
priority_queue<Node > que;
void initArr(int n) {
	dist = new int[n + 1];
	visited = new bool[n + 1];
	fill(dist, dist + n + 1, INF);
	fill(visited, visited + n + 1, false);
}
void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node) {start, 0});
	Node x(0, 0), y(0, 0);
	while(!que.empty()) {
		x = que.top(); que.pop();
		if (!visited[x.v]) {
			visited[x.v] = true;
			for (int i = 0; i < graph[x.v].size(); i++) {
				y = graph[x.v][i];
				if (dist[y.v] > dist[x.v] + y.w) {
					dist[y.v] = dist[x.v] + y.w;
					que.push((Node){y.v, dist[y.v]});
				}
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
		// 题解给出的是无向图，或许无向图使用更多 
		graph[v].push_back((Node){u, w});
	}
	dijkstra(s);
	int ans = -1;
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	cout << ans;
	delete[] dist, visited;
	return 0;
} 
