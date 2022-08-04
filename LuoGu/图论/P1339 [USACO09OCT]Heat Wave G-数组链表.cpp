#include <iostream>
#include <queue>
using namespace std;

// 测试下数组链表的效率和vector的效率，如果差不多还是用vector算了（无能） 

// 数组链表居然比vector快了60ms左右，看起来还是用这个好了 

const int N = 2510, M = 6200 * 2 + 10, INF = 0x3fffffff;
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
	cin >> n >> m >> s >> t;
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
	dijkstra(s);
	cout << dist[t];
	return 0;
} 
