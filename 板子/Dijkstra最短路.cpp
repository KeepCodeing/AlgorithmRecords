#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

// https://www.luogu.com.cn/problem/P1339

typedef pair<int, int > PII;
const int N = 2500 + 10, M = N * 2;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}

int dist[N];
bool vis[N];

int dijkstra(int st, int ed) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	memset(dist, 0x3f, sizeof dist);
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
	int n, m, s, t, ut, vt, wt;
	cin >> n >> m >> s >> t;
	while (m--) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt);
		add(vt, ut, wt);
	}
	cout << dijkstra(s, t);
	return 0;
}
