#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 复习第二弹，尽量不找模板题做
// 那么这个题就是先求一遍所有终点到起点的最短路（注意，这里依然不是虚拟源点，因为我们要求的不是公共最短路，而是每个
// 点的最短路），然后再求一遍起点到所有终点的最短路（就是单纯的跑一次，但是求终点最短路要跑N - 1次），最后求和即可 
// 另外考虑需不需要所谓反向建图，可以发现是不需要的，因为不管是去还是回都有路径，而反向建图还是用来求公共最短路的.. 

// 池沼了，真按照上面的思路打算跑N - 1次最短路，这样很可能超时，正解还是反向建图
// 考虑所有点到1点的最短距离，其实就是反向图里1到所有点的距离.. 

// 这么一看反向建图虽然不好扩展，但是却适用更多情况，虚拟源点只能适用求多个起点的公共最短路的情况... 
// 比较无语w，做了两个题都能正确写出代码，但是思路多少都粘、，不知道是不是没仔细看题（心虚） 

typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e3 * 10 + 10, M = 1e5 * 5 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
bool visited[N];
int dist[N], _dist[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
// 跑起点去的最短路 
int dijkstra(int st, int n) {
	// 据说memset是整体赋值最快的方式，这里一个赋值无穷大的技巧是0x3f，因为memset会按字节赋值 
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0; // 一定要注意起点的初始化哦 
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
	int res = 0;
	// 如果现在求的是2~n到1的最短路，返回他们到1的最短路的值 
	for (int i = 1; i <= n; i++) res += dist[i];
	return res;
} 
int dijkstra2(int st, int n) {
	memset(visited, 0, sizeof visited);
	memset(_dist, 0x3f, sizeof _dist);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	_dist[st] = 0;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = _head[ut]; i != -1; i = _ex[i]) {
			int vt = _e[i];
			if (_dist[vt] > _w[i] + wt) {
				_dist[vt] = _w[i] + wt;
				que.push(PII(_dist[vt], vt)); 
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res += _dist[i];
	return res;
}
int main() {
	int n, m;
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), _add(vt, ut, wt);
	}
	printf("%d",  dijkstra(1, n) + dijkstra2(1, n));
//	// 跑2~n到1的最短路 
//	for (int i = 2; i <= n; i++) {
//		res += dijkstra(i, false, n);
//	}
//	// 再跑一遍1到2~n的最短路 
//	res += dijkstra(1, true, n);
//	printf("%ld", res);
	return 0;
}
