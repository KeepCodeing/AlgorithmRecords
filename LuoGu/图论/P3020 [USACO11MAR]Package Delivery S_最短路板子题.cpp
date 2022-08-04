#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 5e4 + 10, M = N * 2;
int head[N], e[M], ex[M], w[M], dist[N], idx = 0;
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top(); que.pop();
		int ut = now.second, wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(head, -1, sizeof head);
	int n, m, ut, vt, wt;
	cin >> n >> m;
	while (m--) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt), add(vt, ut, wt);
	}
	cout << dijkstra(1, n);
	return 0;
}
