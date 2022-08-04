#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// fuxi下最短路.. ，据说是跑两次，一次正着来，一次反着来 
// 题目说是单行路，但是不知道是不是要建无向图 

const int INF = 0x3FFFFFFF;
struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
priority_queue<Node > que;
vector<Node > graph[1010];
int *dist;
void dijkstra(int start) {
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

void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
}
int main() {
	int n, m;
	cin >> n >> m;
	initArr(n);
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
	}
	
	int ans = 0;
	for (int j = 1; j <= n; j++) {
		fill(dist, dist + n + 1, INF);
		dijkstra(j);
		for (int i = 1; i <= n; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
	}
	
	cout << ans;
	return 0;
}
