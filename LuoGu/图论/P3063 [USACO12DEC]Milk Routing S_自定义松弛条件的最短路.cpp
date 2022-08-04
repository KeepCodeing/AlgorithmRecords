#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 起点是1，终点是n，无向图 
// 这个题和SPFA判断正环的题不一样，虽然也是自定义边权，但是它不存在重复
// 走的过程... 
// 似乎题意搞错了w，题目里给的公式L + X / C算出来的是当前时间，下一个点的容积（C）是途径的所有路径中
// 最小的，而L是一个累加的，也就是经过多少个路径L就加多少... 
// 那么可以利用记录路径的方法来记录上一个点的信息... 

// 注意边权是浮点型 
typedef pair<double, int > PII;
const int N = 500 + 10, M = N * 2, INF = 0x3f3f3f3f;
int head[N], e[M], ex[M], l[M], c[M], idx = 0;
pair<int, int > graph[N][N];
// 边权为浮点型，但是最后要取整回去 
double dist[N];
bool vis[N];
struct Node {
	int mc, lsum;	
	Node (int mc, int lsum) : mc(mc), lsum(lsum) {};
	Node () {};
} pre[N];
void add(int ut, int vt, int lt, int ct) {
	e[idx] = vt, l[idx] = lt, c[idx] = ct, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed, int x) {
	for (int i = 0; i < N; i++) dist[i] = 0x3fffffff; 
	memset(pre, -1, sizeof pre);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(.0, st));
	dist[st] = .0; 
	pre[st] = Node(INF, 0);
	while (que.size()) {
		PII now = que.top(); que.pop();
		int ut = now.second;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 沿途的延迟和 + X / 最小容积 
			int lsum = (pre[ut].lsum + l[i]), mc = min(c[i], pre[ut].mc);
			double cost = lsum + (x + .0) / mc; 
//			double cost = pre[ut].lsum + l[i] + min((x + .0) / c[i], pre[ut].mcost);
//			cout << ut << ' ' << vt << ' ' << cost << endl;
			if (dist[vt] > cost) {
				pre[vt] = Node(mc, lsum);
				dist[vt] = cost;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
//	for (int i = 1; i <= ed; i++) cout << dist[ed] << ' ';
	return dist[ed];
}
int main() {
	memset(graph, 0x3f, sizeof graph);
	memset(head, -1, sizeof head);
	int n, m, x, lt, ct, ut, vt;
	scanf("%d%d%d", &n, &m, &x);
	// 初始化邻接矩阵 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = pair<int, int >(INF, INF);
		}
	}
	// 当成邻接矩阵输入，然后有重边选择更优的 
	while (m--) {
		scanf("%d%d%d%d", &ut, &vt, &lt, &ct);
		graph[ut][vt] = pair<int, int >(min(graph[ut][vt].first, lt), min(graph[ut][vt].second, ct));
	}
	// 将邻接矩阵转换为邻接表 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			lt = graph[i][j].first, ct = graph[i][j].second;
			if (lt != INF && ct != INF) add(i, j, lt, ct), add(j, i, lt, ct);
		}
	}
	cout << dijkstra(1, n, x) << endl;
//	int st = n;
//	while (true) {
//		cout << st << endl;
//		if (pre[st] == -1) break;
//		st = pre[st];
//	}
	return 0;
}
/*
3 3 15
1 2 4 3
1 2 1 1
2 3 1 1

*/
