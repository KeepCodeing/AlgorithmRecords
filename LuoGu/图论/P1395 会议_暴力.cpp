#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 暴力解...正解写了三个小时搞不出来w... 
// 暴力得70，数据范围诚不欺我... 

const int N = 50000 + 10, M = N * 2, INF = 0x3fffffff;
typedef pair<int, int > PII;
int dist[N];
int head[N], e[M], ex[M], w[M], idx = 0;
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int bfs(int st) {
	memset(vis, 0, sizeof vis);
	int res = 0;
	queue<PII > que;
	que.push(PII(st, 0));
	while (que.size()) {
		PII now = que.front(); que.pop();
		int ut = now.first, dep = now.second;
		if (vis[ut]) continue;
		vis[ut] = true;
		res += dep;
		for (int i = head[ut]; i != -1; i = ex[i]) que.push(PII(e[i], dep + 1));
	} 
	return res;
}
// 虚拟源点坠毁了w，因为这个题是无向图... 
//void dijkstra(int st) {
//	memset(vis, 0, sizeof vis);
//	memset(dist, 0x3f, sizeof dist);
//	priority_queue<PII, vector<PII >, greater<PII > > que;
//	que.push(PII(0, st));
//	dist[st] = 0;
//	while (que.size()) {
//		PII now = que.top(); que.pop();
//		int ut = now.second, wt = now.first;
//		if (vis[ut]) continue;
//		vis[ut] = true;
//		for (int i = head[ut]; i != -1; i = ex[i]) {
//			int vt = e[i];
//			if (dist[vt] > wt + w[i]) {
//				dist[vt] = wt + w[i];
//				que.push(PII(dist[vt], vt)); 
//			}
//		}
//	} 
//}
int main() {
	memset(head, -1, sizeof head);
	int n, ut, vt, res = INF, mpoi = INF;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt, 1), add(vt, ut, 1);
//	for (int i = 1; i <= n; i++) add(0, i, 0), add(i, 0, 0);
//	dijkstra(0);
//	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	for (int i = 1; i <= n; i++) {
		int t = bfs(i);
		if (res > t) res = t, mpoi = i;
	}
	printf("%d %d", mpoi, res);
	return 0;
}
/*
7
1 2
2 4
4 6
3 1
5 2
3 7 
*/
