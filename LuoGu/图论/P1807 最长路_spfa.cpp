#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// SPFA求最长路，简单来说就是将松弛的条件改了下，从大于变成小于...
// 之前用Dijkstra做过，但是坠毁了w，果然有负权边还是用SPFA比较好...，但是也有点小问题，
// 比如其加了判负环的逻辑，似乎负环的存在会导致不存在最短路，但是却对最长路没有影响，因为
// 我们要的是边权不断变大，而不是不断变小... 

// 有向图 
const int N = 1500 + 10, M = 5 * 1e4 + 10, INF = -0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m, ut, vt, wt;
int spfa(int st) {
	queue<int > que;
	for (int i = 0; i < N; i++) dist[i] = INF, visited[i] = false;
	que.push(st);
	// 注意初始化起点 
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front();que.pop();
		// SPFA将每个出队的节点标记为未访问，这里和Dijkstra还是有点区别的 
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 松弛条件改下就行了..注意和Dijkstra的区别，Dijkstra不是通过dist[ut]来获取边权的，而是通过
			// pair里的属性来的 
			if (dist[vt] < dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				// 没用用过就循环入队 
				if (!visited[vt]) {
					visited[vt] = true;
					que.push(vt); 
				}
			}
		}
	}
	// 可能有不连通的情况 
	if (dist[n] == INF) return -1;
	return dist[n];
}
int main() {
	// 又忘了初始化头头结点w 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	printf("%d", spfa(1));
	return 0;
}
