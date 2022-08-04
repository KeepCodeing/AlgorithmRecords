#include <iostream>
#include <cstdio>
#include <queue> 
#include <cstring>
using namespace std;

// 不知道为什么这个题改了三次名...总之拿来复习最短路了... 

typedef pair<int, int > PII;
// 单向边 
const int M = 1e5 + 10, N = 1e3 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
int dist[N], _dist[N];
bool visited[N];
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// 为了防止混淆全局变量这里都加了个t，把算法名字记错了w 
void dijkstra(int st, int et[], int ext[], int wt[], int headt[], int distt[]) {
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	distt[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wtt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// 明明要用参数指针却写成了板子导致结果有问题的屑w..这么看跑这种最短路最好把板子变量也改下了... 
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (distt[vt] > wtt + wt[i]) {
				distt[vt] = wtt + wt[i];
				que.push(PII(distt[vt], vt)); 
			}
		}
	} 
}
int main() {
	// 因为是指针传参而其不知道怎么初始化指针w故而这里统一初始化... 
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	memset(dist, 0x3f, sizeof dist);
	memset(_dist, 0x3f, sizeof _dist);
	int n, m, x, ut, vt, wt;
	scanf("%d%d%d", &n, &m, &x);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// 正向边，这条边以x为起点跑最短路可以获得回去的最短路 
		add(ut, vt, wt);
		// 反向边，这条边以x为起点跑最短路可以获得来的最短路 
		_add(vt, ut, wt);
	}
	 
	dijkstra(x, e, ex, w, head, dist);
	dijkstra(x, _e, _ex, _w, _head, _dist);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dist[i] + _dist[i]);
	printf("%d", res);
	return 0;
}
