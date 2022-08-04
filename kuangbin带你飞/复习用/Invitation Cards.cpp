#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 一下子没看出题意w.. 

const int N = 1000000 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef long long LL;
typedef pair<LL, int > PII;
int _head[N], _e[N], _ex[N], _w[N], _idx = 0;
int __head[N], __e[N], __ex[N], __w[N], __idx = 0;
// 两个idx都忘了自增... 
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void __add(int ut, int vt, int wt) {
	__e[__idx] = vt, __w[__idx] = wt, __ex[__idx] = __head[ut], __head[ut] = __idx++;
}
LL _dist[N], __dist[N];
bool visited[N];
void dijkstra(int st, int e[], int ex[], int w[], int head[], LL dist[]) {
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second;
		LL wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
int main() {
	int T, n, m, ut, vt, wt;
	scanf("%d", &T);
	while (T--) {
		memset(_head, -1, sizeof _head);
		memset(__head, -1, sizeof __head);
		for (int i = 0; i < N; i++) _dist[i] = __dist[i] = INF;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			// 正向图和反向图.. 
			_add(ut, vt, wt);
			__add(vt, ut, wt);
		}
		dijkstra(1, _e, _ex, _w, _head, _dist);
		dijkstra(1, __e, __ex, __w, __head, __dist);
		LL res = 0;
		for (int i = 1; i <= n; i++) {
			if (_dist[i] == INF || __dist[i] == INF) continue;
			// 又看错了题w，要求的是路径和，不是来回两个最短路径... 
			res += _dist[i] + __dist[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
