#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10, M = N * 2;
typedef pair<int, int > PII;
int head[M], e[M], ex[M], w[M], idx = 0;

int dist[N];
bool vis[N];

void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}

int dijkstra(int st, int ed) {
	memset(vis, 0, sizeof vis);
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
	for (int i = 1; i <= 2021; i++) {
		for (int j = 1; j <= 2021; j++) {
			if (i == j) continue;
			if (abs(i - j) <= 21) {
				int t = i * j / __gcd(i, j);
				add(i, j, t);
				add(j, i, t);
			}
		}
	}
	cout << dijkstra(1, 2021);
	return 0;
}
