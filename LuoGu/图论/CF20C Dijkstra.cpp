#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

// 这个题要求记录最短路径，那么思路和网格图的最短路径差不多，都是记录前驱节点然后还原.. 
// TLE了，蒙古... 

typedef long long LL;
typedef pair<int, int > PII;
const int N = 1e5 + 10, M = N * 2;
const LL INF = 9223372036854775806;
int head[N], e[M], ex[M], w[M], idx = 0;
// 注意要开long long，不然会爆... 
LL dist[N];
// 注意这里不能用书里的变量名prev，这会与评测机的环境变量冲突导致CE爆零... 
int pre[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// 先写个Dijkstra，再补记录路径
bool dijkstra(int st, int ed) {
//	memset(dist, 0x3f, sizeof dist);
	// 初始初始化路径数组，不然终点是不确定的，因为1不一定最后才到n... 
	memset(pre, -1, sizeof pre);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				// 记录当前点的上一个点的编号 
				pre[vt] = ut;
				que.push(PII(dist[vt], vt));
			}
		}
	}
	if (dist[ed] == INF) return false;
	return true;
} 
int main() {
	memset(head, -1, sizeof head);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) dist[i] = INF;
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	// 如果存在1~n的最短路，输出其路径（这样写要反着输出，所以这里可以参考网格图的遍历方法
	// 直接从终点跑最短路，然后从起点输出路径） 
	if (dijkstra(n, 1)) {
		int now = 1;
		for (; now != -1; now = pre[now]) cout << now << ' ';
		return 0;	
	} 
	printf("-1");
	return 0;
}
/*
5 5
1 2 2 2
2 3 1 1
1 4 1 1
4 5 1 1
5 3 1 1
*/
