
#include <iostream>
#include <queue>
using namespace std;

// 双 倍 经 验 
// 就改了下终点和数据范围（谔谔，没改成有向图，TLE加WA了一次...）
// 值得一提的是vector超时了，而数组链表时间在1s左右，高下立判... 

const int N = 100010, M = 100010 * 2 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[M], e[M], ex[M], w[M], idx = 0;
int n, m, s, t;
int dist[N];
bool visited[N];
void add(int k, int v1, int w1) {
	e[idx] = v1, w[idx] = w1, ex[idx] = head[k], head[k] = idx++;
}
void dijkstra(int s) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[s] = 0;
	que.push(PII(0, s)); 
	while(!que.empty()) {
		PII t = que.top();que.pop();
		int ver = t.second, wei = t.first;
		if (visited[ver]) continue;
		visited[ver] = true;
		for (int i = head[ver]; i != -1; i = ex[i]) {
			int j = e[i];
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
	fill(head, head + M, -1);
	fill(dist, dist + N, INF);
	cin >> n >> m >> s;
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) {
		cout << dist[i];
		if (i != n) cout << ' ';
	}
	return 0;
} 
