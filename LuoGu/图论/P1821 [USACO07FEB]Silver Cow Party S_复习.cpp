#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 因为好久没刷题加上不可抗力（迫真）所以这里复习下最基本的最短路和最小生成树 

// 这个题可以反向建图或者虚拟源点，比较有意义的一个题 

// 这里总结下为什么这个题错了：首先，题意没搞清楚就开始瞎写，题目要求的是两次来回的和的最大值，其却想成了求一次去的最大值， 
// 然后莫名其妙用虚拟源点求了次来的最小值，最后加在一起，这样的出的和肯定是非法的，考虑一个点去的最小值最小，来的最小值
// 却是最大的...但是好在模板算是背下来了（虚心），就算好久没打也能轻松写完代码了... 

typedef pair<int, int > PII;
const int N = 1000 * 10 + 10, M = 100000 * 5 + 10, INF = 0x3fffffff;

int head[N], e[M], ex[M], w[M], idx = 0;
int head1[N], e1[M], ex1[M], w1[M], idx1 = 0;
int dist1[M];
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void add1(int ut, int vt, int wt) {
	e1[idx1] = vt, w1[idx1] = wt, ex1[idx1] = head1[ut], head1[ut] = idx1++; 
}
void dijkstra(int st) {
	memset(visited, 0, sizeof visited);
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	// 注意这里的起点距离初始化... 
	dist[st] = 0;
	que.push(PII(0, st));
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
}
// 虚拟源点写炸了，再写次最短路...
void dijkstra1(int st) {
	memset(visited, 0, sizeof visited);
	memset(dist1, 0x3f, sizeof dist1);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist1[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head1[ut]; i != -1; i = ex1[i]) {
			int vt = e1[i];
			if (dist1[vt] > w1[i] + wt) {
				dist1[vt] = w1[i] + wt;
				que.push(PII(dist1[vt], vt)); 
			}
		}
	} 
} 
int main() {
	int n, m, x;
	memset(head, -1, sizeof head);
	memset(head1, -1, sizeof head1);
	scanf("%d%d%d", &n, &m, &x);
	int ut, vt, wt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		// 这里老老实实反向建图，然后跑两次最短路，求最大和... 
		add1(vt, ut, wt); 
	}
	// 加虚拟源点（错） 
//	for (int i = 1; i <= n; i++) 
//		if (i != x) add(0, i, 0);
	// 求出牛回去的最短路的值 
	dijkstra(x);
	// 求出牛来的最短路的值
	dijkstra1(x); 
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dist[i] + dist1[i]);
	}
	printf("%d", res);
	// 通过虚拟源点求出牛来的最短路（这里是错误的要说的话就是题目都没看清楚就开始写了，首先题目要求
	// 的是一头牛来回的最短路之和的最大值，那么思考下可不能有一头牛去的最短路的值是最小的，来的最短路
	// 的值却最大且这两个值相加也是最大的，如果有，那么我们第一个最短路求的就是错的，因为第一个最短路
	// 求的是所有牛回去的最短路的最大值，而这很明显不满足我们上面所说的，那么再看第二个最短路，求的就是
	// 所有点到终点的最短路，那这个最短路有什么用呢？这个最短路什么用都没有，因为我们要使来回路径最长，
	// 而不去的路径取所有点最小值，回的路径取最大值...由此，这个题的正解只能是反向建图然后跑两次最短路
	// 求最大和... 
//	dijkstra(0, 0);
//	// 46
//	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	return 0;
}


