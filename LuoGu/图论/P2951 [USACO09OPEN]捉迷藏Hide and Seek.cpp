#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 发现SPFA速度最快，不过可能被卡掉 

struct Node {
	int v, w;
	// 草，这里把w(w)写成了w(v)，这样导致
	// 权值变成了编号而不是默认的1 
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
const int INF = 0x3FFFFFFF;
int n, m;
int *dist;
vector<Node > graph[20010];
priority_queue<Node > que;
void initArr(int n) {
	dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
} 
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
int main() {
	cin >> n >> m;
	initArr(n);
	int u, v;
	while(m--) {
		cin >> u >> v;
		// 惯例的无向图
		// 题目没给权值，不过可以看出来默认为1 
		graph[u].push_back((Node){v, 1});
		graph[v].push_back((Node){u, 1});
	}
	dijkstra(1);
	// 求出了所有距离之后进行一次遍历，获取最大值，再进行一次遍历
	// 计算最大值和以及第一个等于最大值的元素的下标
	int maxDist = -1, firstIndex = 0, maxDistCnt = 0; 
	for (int i = 1; i <= n; i++) maxDist = max(maxDist, dist[i]);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == maxDist) {
			if (firstIndex == 0) firstIndex = i;
			maxDistCnt++;
		}
	}
	cout << firstIndex << ' ' << maxDist << ' ' << maxDistCnt;
	delete[] dist;
	return 0;
}
