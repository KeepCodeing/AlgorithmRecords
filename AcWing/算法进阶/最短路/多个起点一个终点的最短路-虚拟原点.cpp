#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

// 虚拟源点算法可以扩展到有多个起点的情况，而反向建图只能求只有一个终点的情况，如果要求多个终点估计又要跑n次最短路了w 
// 这个题就是有多个起点，单个终点，要求这些起点到终点的最短路，与silver cow party不同，那个题也是一个终点，多个
// 起点，不同的是还要求一次回去的最短路，也就是要求终点到其它点的最短路。这个题不用求回去的最短路，那么其实我们还是
// 可以反向建图从终点求次最短路，然后对比长度。
// 这里采用虚拟源点的方式求多个起点的最短路。就是建立一个编号为0的点，这个点与所有起点都有一条边权为0的边。如果我
// 们从图上看，0点到终点的距离就包括了所有起点到总终点的距离并且这个距离可以保证最短或者说无法达到。 
// 谔谔，HDOJ的编译器类型应该选G++... 
// 另外这两种算法的跑起来花的时间没有区别..

// 注意：如果硬要和sliver cow party对比的话，sliver cow party的第一次从终点跑最短路没有反向建图，因为它跑的是一个
// 回去的过程，所以直接跑就行。那么这个题反向建图了其实就是和银牛派对去的过程相似，只不过这里求的是单点最短距离，而
// 不是所有点的最短距离之和，这也是为什么这个题也能反向建图跑的原因... 

// 因为要多加一个点，所以数组范围最好多开点，另外有向图不用开两倍的边 

const int N = 1000 * 2 + 10, M = 21000 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// 接下来就是套板子了，不过要记得初始化 
int dijkstra(int st, int ed) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
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
	return dist[ed] == INF ? -1 : dist[ed]; 
}
int sts[N];
int main() {
	int n, m, ed, ut, vt, wt, q;
	scanf("%d", &m);
	// 多组数据,读入顶点数，边数，终点 
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	scanf("%d", &q);
	// 输入起点，并与虚拟源点连边 
	while (q--) {
		scanf("%d", &ut);
		// 所有起点都与虚拟源点0连一条边权为0的边 
		add(0, ut, 0);
	}
	// 接下来就是从0点求一次最短路，然后判断下能不能到终点，能到最短距离是多少 
	printf("%d\n", dijkstra(0, ed));
	return 0;
}


// 反向建图，从终点跑一遍最短路，然后取到起点的距离最小值 
/*
while (~scanf("%d%d%d", &n, &m, &ed)) {
	// 建图
	fill(head, head + N, -1), idx = 0; 
	int cnt = 0, res = INF;
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(vt, ut, wt);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &sts[++cnt]);
	}
	dijkstra(ed);
	for (int i = 1; i <= cnt; i++) res = min(res, dist[sts[i]]);
	printf("%d\n", res == INF ? -1 : res);
}

void dijkstra(int st) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
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
*/
