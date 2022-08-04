#include <iostream>
#include <queue>
using namespace std;
const int N = 100010, INF = 0x3fffffff;
int head[N], e[N], ex[N], w[N], idx = 0;
add(int k, int vi, int wi) {
	e[idx] = vi, w[idx] = wi, ex[idx] = head[k], head[k] = idx++;
}
int dist[N];
bool visited[N];
typedef pair<int, int > PII;
int n, m;
int dijkstra() {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, 1));
	while (!que.empty()) {
		PII temp = que.top();que.pop();
		int ver = temp.second, wei = temp.first;
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
	if (dist[n] == 0x3fffffff) return -1;
	return dist[n]; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	fill(head, head + N, -1);
	fill(dist, dist + N, INF);
	cin >> n >> m;
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	cout << dijkstra();
	return 0;
}
