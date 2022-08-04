#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 这个题差不多是SPFA判断负环的模板题了...，SPFA判断负环其实就是判断一个点是否被入队多次（即入队的次数大于等于了点数），
// 可以考虑下极端情况，一个点和n个点相连，求它的最短路最多会使得其入队n-1次，而如果超过这次数，就意味着存在负环，即边
// 的最短距离可以无限被初始化... 
// 这个题既有双向边也有单向边，不过双向边就是特殊的单向边，所以建图不需要特殊处理... 

// 因为又有单向边又有双向边所以边数开的大一些w 
const int N = 500 + 10, M = 2500 * 3 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int T, n, m, wm, ut, vt, wt;
// SPFA判断负环就是用一个数组记录每个点的入队次数 
int dist[N], cnt[N];
bool visited[N];
bool spfa(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	// 注意是多组数据，因此要多次初始化... 
	memset(cnt, 0, sizeof cnt);
	dist[st] = 0, cnt[st] = 1;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				// 更新最短距离 
				dist[vt] = dist[ut] + w[i];
				if (!visited[vt]) {
					visited[vt] = true;
					// 注意统计点的数量的前提是这个点入队了，即没有被重复访问... 
					cnt[vt]++;
					if (cnt[vt] >= n) return true;
					que.push(vt); 
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		// 多组数据，多次初始化... 
		memset(head, -1, sizeof head);
		idx = 0;
		scanf("%d%d%d", &n, &m, &wm);
		while (m--) {
			// 连双向边
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, wt), add(vt, ut, wt);
		}
		while (wm--) {
			// 连单向边，注意建边的边权是负的，因为题目的描述是所谓的回溯wt秒，那么我们走过去是耗时，
			// 即边权为正，反过来回溯就是边权为负了... 
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, -wt); 
		}
		bool res = spfa(1);
		if (res) puts("YES");
		else puts("NO");
	}
	return 0;
}
