#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

// 题意没看清楚w，想着反向建边来着..实际上不能反向建边，当有多个点到一个点的时候，
// 可以反向建边，否则就不能，这个题其实似乎中心到其它城市，而不是其它城市到中心.. 
// 另外可以考虑下这个题会不会有负环，首先可以确定有负权边（不能用Dijkstra），但是它
// 存在负环么..应该是没有的，有负环的话最短路不存在，而且也没办法判断后面的点能不能到.. 

// 不知道因为什么神必原因TLE了... 

const int N = 150000 + 10, M = N * 2 + 10, INF = 0x3f3f3f3f;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N], cnt[N];
int n, r, p, s, ut, vt, wt;
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void spfa(int st) {
	queue<int > que;
	que.push(st);
	// 又池沼了w，把初始化写在了起点初始化之后... 
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front();que.pop();
		vis[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!vis[vt]) {
					cnt[vt]++;
					if (cnt[vt] >= n) return;
					vis[vt] = true;
					que.push(vt);
				}
			}
		}
	}
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d%d%d%d", &n, &r, &p, &s);
	// 建双向边 
	for (int i = 0; i < r; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		add(vt, ut, wt);
	}
	// 建单向边
	for (int i = 0; i < p; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	} 
	spfa(s);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) printf("NO PATH");
		else printf("%d", dist[i]);
		puts("");
	}
	return 0;
}
