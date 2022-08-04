#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 做过很多遍的题，再做一遍也无妨w，不过做类似的题的时候都会想到虚拟源点，
// 但是实际上用得到的题却很少..关于虚拟源点，它SPFA了w
 
typedef pair<int, int > PII;
const int N = 1000 + 10, M = 100000 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
int dist[N], _dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void dijkstra(int st, int headt[], int et[], int ext[], int wt[], int distt[]) {
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	distt[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, uw = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// 这里写成了ext[ut]，似乎就是死循环了w 
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (distt[vt] > uw + wt[i]) {
				distt[vt] = uw + wt[i];
				que.push(PII(distt[vt], vt)); 
			}
		}
	} 
}
int main() {
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	int ut, vt, wt;
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), _add(vt, ut, wt); // 反向建图，一瞬以为这个题是无向图w 
	}
	memset(dist, 0x3f, sizeof dist);
	memset(_dist, 0x3f, sizeof _dist);
	// 直接传数组就不用多写个Dijkstra了 
	dijkstra(x, head, e, ex, w, dist);
	dijkstra(x, _head, _e, _ex, _w, _dist);
	int ans = 0;
	// 题目求的最长最短路.. 
	for (int i = 1; i <= n; i++) ans = max(ans, dist[i] + _dist[i]);
	printf("%d", ans);
	return 0;
}
