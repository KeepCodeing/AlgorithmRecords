#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// Floyd板子，但是还是用dijkstra做的，这个算法更常用，但是想必蓝桥杯考最短路应该就是考Floyd吧..Floyd 

typedef pair<int, int > PII;
const int N = 1000 + 10, M = 2000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dist[N]; 
bool visited[N];
int n, m, ut, vt, wt;
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
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
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[n];
}
int main() {
	scanf("%d%d", &m, &n);
	memset(head, -1, sizeof head);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	printf("%d\n", dijkstra(1));
	return 0;
}
