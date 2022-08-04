#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 做了一天，该了结了... 

const int N = 50000 + 10, M = N * 2, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], idx = 0;
int sz[N];
int ans = INF, maxn = INF;
int n, ut, vt;
bool vis[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int ut, int nx) {
	sz[ut] = 1;
	int mx = 0;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vt == nx) continue;
		dfs(vt, ut);
		sz[ut] += sz[vt];
		mx = max(mx, sz[vt]);
	}
	mx = max(mx, n - sz[ut]);
	if (mx < maxn || (mx == maxn && ut < ans)) maxn = mx, ans = ut;
}
int bfs(int st) {
	int res = 0;
	queue<PII > que;
	que.push(PII(st, 0)); 
	while (que.size()) {
		PII now = que.front(); que.pop();
		int ut = now.first, wt = now.second;
		if (vis[ut]) continue;
		vis[ut] = true;
		res += wt;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			que.push(PII(vt, wt + 1)); 
		}
	}
	return res;
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	dfs(1, 0);
	printf("%d %d", ans, bfs(ans));
	return 0;
}
