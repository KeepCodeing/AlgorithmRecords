#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// 目前的思路是从x点求一次最短路，也就是所有牛回去的路程，再对每个点求一次
// 到x的最短路，也就是每头牛来的路程，然后相加对比最大值... 

// 奇妙，跑了n次最短路，这算法效率太低了，不过还是没TLEw，正确的做法是建两个图
// 一个正着来，一个反着来，感觉还是有点蒙，代码上的实现是a->b建一个图，b->a建一个
// 图，然后把这两个图跑一遍最短路（都是从x开始），大概可以理解成跑a->b是求的a->b的最短路，跑
// b->a求的是b->a的最短路，由此就可以两遍最短路求出所有单点最短路了（蒙古） 

// 吃饭的时候想通了，正着建图从x到其它点求的是x到其它点的最短路，把边权反过来，还是从x点跑最短路
// 这样就变成了x走的是所有点到x的边的权，也就变成了所有点到x的最短路 

typedef pair<int, int > PII;
const int N = 1010, M = 100000 * 2 + 10, INF = 0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int edist[N], dist2[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	fill(visited, visited + N, false);
	edist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (edist[vt] > w[i] + wt) {
				edist[vt] = w[i] + wt;
				que.push(PII(edist[vt], vt)); 
			}
		}
	} 
}
int dijkstra2(int st, int x) {
	fill(visited, visited + N, false);
	fill(dist2, dist2 + N, INF);
	dist2[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist2[vt] > w[i] + wt) {
				dist2[vt] = w[i] + wt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	} 
	return dist2[x];
}
int main() {
	int n, m, x, ut, vt, wt;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i <= n; i++) head[i] = -1, edist[i] = INF;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt); // 样例图里给的有向图... 
	}
	// 求一遍x到其它点的距离，就是牛回去的距离 
	dijkstra(x);
	for (int i = 1; i <= n; i++) printf("%d ", edist[i]);
	puts("");
	// 再求一遍所有点到x的距离，也就是来的距离
	for (int i = 1; i <= n; i++) edist[i] += dijkstra2(i, x), cout << dijkstra2(i, x) << ' ';
	int res = -1;
	for (int i = 1; i <= n; i++) res = max(res, edist[i]);
	printf("%d", res);
	return 0;
}
