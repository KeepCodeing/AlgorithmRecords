#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 其算法似乎效率很低，不过也能过题 

struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m, b;
int *dist;
vector<Node > graph[50010];
priority_queue<Node > que;
// 2->1 1-> 4（正确） || 2->1->2->4?
void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node){start, 0});
	Node x(0, 0), y(0, 0);
	while(!que.empty()) {
		x = que.top(); que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				que.push((Node){y.v, dist[y.v]});
			}
		}
	}
}
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
}
int main() {
	cin >> n >> m >> b;
	initArr(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		graph[v].push_back((Node){u, w});
	}
	int start, end;
	while(b--) {
		cin >> start >> end;
		dijkstra(1);
		cout << dist[start] + dist[end] << endl;
	}
	delete[] dist;
	return 0;
}
