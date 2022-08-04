#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// 看题解都是先连通，不给边权，然后在输入被破坏的路的时候给被破坏的路加边权跑最短路。本five的思路是先建边加边权
// 然后跑最短路统计路程总长度。在路被破坏后连一些边权为0的边，再跑次最短路统计路程总长，最后的差就是要修的路的
// 长度... 
// 另外数据范围非常小，其实可以floyd... 

// 因为没有考虑加0边的空间所以WA了，不知道为什么只是WAw 

typedef pair<int, int > PII;
// 考虑到会加若干个0边所有空间得开大点... 
const int N = 2100, M = N * 10 +10;
int head[N], e[M], ex[M], w[M], idx = 0, INF = 0x3fffffff;
PII ptemp[M];
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	fill(dist, dist + M, INF), fill(visited, visited + N, false);
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
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed];
}
int main() {
	// 惯例的那个... 
	fill(head, head + N, -1);
	int n, m, ut, vt, wt, d, st, ed, dst, ded;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// 双向边 
		add(ut, vt, wt), add(vt, ut, wt);
	}
	scanf("%d", &d);
	// 因为最后输入起点终点，所以这里得把被破坏的路存起来 
	for (int i = 1; i <= d; i++) scanf("%d%d", &ptemp[i].first, &ptemp[i].second);
	scanf("%d%d", &st, &ed);
	// 从st到ed跑一次最短路
	dst = dijkstra(st, ed);
	// 加边权为0的边再跑一次
	for (int i = 1; i <= d; i++) add(ptemp[i].first, ptemp[i].second, 0), add(ptemp[i].second, ptemp[i].first, 0);
	ded = dijkstra(st, ed);
	printf("%d", dst - ded);
	return 0;
}
