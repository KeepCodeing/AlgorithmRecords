#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m;
int *dist;
// 似乎加入visited对效率提升也不大，而且甚至比不加还慢一点 
bool *visited;
vector<Node > graph[20010];
priority_queue<Node > que;
void initArr(int n) {
	dist = new int[n + 1];
	visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);
	fill(dist, dist + n + 1, INF);
}
void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node){start, 0});
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
	cin >> n >> m;
	initArr(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
	}
	dijkstra(1);
	for (int i = 2; i <= n; i++) {
		cout << dist[i];
		if (i != n) cout << endl;
	}
	delete[] dist;
	return 0;
}
