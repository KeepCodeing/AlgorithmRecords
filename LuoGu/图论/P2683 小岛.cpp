#include <iostream>
#include <queue>
using namespace std;

// 一开始看到有个新增边的操作觉得会超时，然而看题解发现数据很水裸
// Dijkstra都能过... 

// 谔谔，忘了ao多，还是优先用vector版罢... 

// RE了三次，实在不知道边和点数组大小的分配关系，现在看来都分配的很大应该是没问题的... 
// 看了下题解可能就是顶点和访问数组的大小可以根据n来（就是顶点数），而距离和其它数组
// 都得跟着m来（也就是边数），而且最好是乘2+10的 

const int N = 110, M = 100010, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[M], w[M], e[M], ex[M], idx = 0;
void add(int k, int v1, int w1) {
	e[idx] = v1, w[idx] = w1, ex[idx] = head[k], head[k] = idx++;
}
int dist[M];
bool visited[M];
int n, m;
void dijkstra(int st) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	// 忘记了为什么要用pair存，这样其实是为了方便之后入队 
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (!que.empty()) {
		PII t = que.top();que.pop();
		int ver = t.second, wei = t.first;
		if (visited[ver]) continue;
		visited[ver] = true;
		for (int i = head[ver]; i != -1; i = ex[i]) {
			int j = e[i];
			// j是当前点 
			if (dist[j] > w[i] + wei) {
				dist[j] = w[i] + wei;
				que.push(PII(dist[j], j));
			}
		} 
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N, -1);
	cin >> n >> m;
	int u, v, w;
	while (m--) {
		int op;
		cin >> op;
		if (op) {
			cin >> u >> v >> w;
			// 无向图 
			add(u, v, w), add(v, u, w);
		} else {
			cin >> u >> v;
			dijkstra(u);
			if (dist[v] != 0x3fffffff) cout << dist[v];
			else cout << -1;
			cout << endl;
		}
	} 
	return 0;
} 
