#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 又是一道做过的题，这个题也是虚拟源点，值得注意的是反向建图似乎在普及题里比较多，而虚拟源点在
// 提高题里比较多，估计其还有更高级的用法.. 
// 坠毁，脑子又抽了w，虚拟源点只能用于有向图...
// 正解是跑n次最短路，然后统计距离.. 
// 关于题目的意思：其实就是求出某个农场到其它有牛农场的最短路之和，因为是双向边，所以求出这个农场去那个
// 农场的最短路实际也就求出了那个农场来的最短路... 

typedef pair<int, int > PII;
// 空间又开小RE了w 
const int P = 1800 + 10, N = 1500 + 10, M = 11450 * 2 + 10, INF = 0x3f3f3f3f;
int farmes[P];
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool vis[N];
int n, p, c, ut, vt, wt;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
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
	int res = 0;
	// 算出当前点到所有有牛在的牧场的和，同时也意味着所有牛到这个农场的和.. 
	for (int i = 0; i < n; i++) {
		if (dist[farmes[i]] == INF) return INF;
		res += dist[farmes[i]];
	}
	return res;
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d%d%d", &n, &p, &c);
	for (int i = 0; i < n; i++) scanf("%d", &farmes[i]);
	while (c--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		add(vt, ut, wt);
	} 
	int res = INF;
	for (int i = 1; i <= p; i++) res = min(res, dijkstra(i));
	printf("%d", res);
	return 0;
}
