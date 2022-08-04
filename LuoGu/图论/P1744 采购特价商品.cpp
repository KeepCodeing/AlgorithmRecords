#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// 突然觉得很像前天蓝桥杯省赛模拟的一道题，这个题同样是给的坐标形式而不是点
// 形式。如果我们要求最短路一般是给若干个顶点编号，然后还有对应的边的边权。
// 所以可以考虑把输入顺序当成点的编号，两点的权值就是它们的直线距离.... 

#define x first
#define y second
typedef pair<int, int > PII1;
typedef pair<double, int > PII2;
const int N = 110, M = 1000 * 2 + 10;
const double INF = 0x3fffffff;
int head[N], e[M], ex[M], idx = 0;
double w[M], dist[M];
bool visited[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
PII1 pos[N];
double getWei(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void dijkstra(int st) {
	fill(dist, dist + M, INF);
	priority_queue<PII2, vector<PII2 >, greater<PII2 > > que;
	dist[st] = .0;
	que.push(PII2(.0, st));
	while (que.size()) {
		PII2 now = que.top();que.pop();
		int ut = now.second;
		double wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII2(dist[vt], vt)); 
			}
		}
	} 
}
int main() {
	int n, m, x, y, st, ed;
	double wt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	scanf("%d", &m);
	// 调了半天bug，原来是其head填充的问题，其在dijkstra函数里进行的填充，这也就意味着读入建图全部木大了w 
	fill(head, head + N, -1);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		wt = getWei(pos[x].x, pos[x].y, pos[y].x, pos[y].y);
		add(x, y, wt);
		add(y, x, wt);
	}
	scanf("%d%d", &st, &ed);
	dijkstra(st);
	// for (int i = 1; i <= n; i++) printf("%.2lf ", dist[i]);
	printf("%.2lf", dist[ed]);
	return 0;
}
