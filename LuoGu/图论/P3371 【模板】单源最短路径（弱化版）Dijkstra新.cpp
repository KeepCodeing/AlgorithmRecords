#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra加优先队列可以过弱化版最短路，不过强化版TLE，而且强化版的数据更大
// vector开小了还RE了... 

struct Node {
	int v, w;
	// 这种初始化方式也要提供参数 
	Node(int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
// 题目中出现了比3F3F3F3F大的值，也就是int的最大值，所以这里INF最好设置为int的最大值7FFFFFFF 
const int INF = 0x7FFFFFFF;
int n, m, s;
int *dist;
bool *visited; 
vector<Node > graph[10010];
priority_queue<Node > que;

void dijkstra(int start) {
	dist[start] = 0;
	que.push((Node){start, dist[start]}); 
	Node x(0, 0), y(0, 0);
	while(!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			// 忘记了这里，这里的意思是判断最近点的距离值是否比当前点距离值加上最近点的权值 
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				// 这里之前写成了dist[y.w]... 
				que.push((Node){y.v, dist[y.v]}); 
			}
		}
	}
}
void initArray(int n) {
	visited = new bool[n + 1];
	dist = new int[n + 1];
	fill(visited, visited + n + 1, false);
	fill(dist, dist + n + 1, INF);
}
int main() {
	cin >> n >> m >> s;
	// 忘了初始化数组.. 
	initArray(n);
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w}); 
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) cout << dist[i] << (i != n ? " " : "");
	delete[] visited, dist;
	return 0;
}
