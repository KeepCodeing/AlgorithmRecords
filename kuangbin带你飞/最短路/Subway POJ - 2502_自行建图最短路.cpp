#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

// 这个题和其它题不一样，这个题要求我们自己分析题目然后建正确的图...我们首先分析下这个题的目的，要判断是从坐地铁到终点
// 快还是走到终点快，只有相邻的两个站台才能互相到达（图里看起来应该类似一条直线），我们可以选择走到任意一个站台上车或者
// 从任意一个站台下车走到终点或者另一个站台...
// 那么我们建图就要根据这个来了，首先我们给每个站台一个编号，因为可以从任意一个站台走到终点或者起点，因此每个站台都要和
// 终点起点连边。其次因为只有相邻的站台能互相到达，所以我们还要记录上一个站台的位置，然后让上一个站台和当前站台连边，最后
// 因为我们可以从任意一个站台走路到其它站台，所以还要枚举所有站台让他们互相连一条走路的边...建完图后跑最短路就行了 

// 没带脑子对着别人的代码写完的...没有干劲w... 

typedef pair<double, int > PII;
const int N = 205, M = 5e4 + 10;
const double INF = 1e18 + .0;
int sx, sy, edx, edy;
int head[N], e[M], ex[M], idx = 0;
double dist[N];
bool vis[N];
double w[M];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// 计算边权，注意题目给的km/h，答案要的m/m 
double cpl(int x1, int y1, int x2, int y2, int tm) {
	int t1 = x1 - x2, t2 = y1 - y2;
	// 两点距离/每小时走的速度再还原成米/每分钟 
	return sqrt(t1 * t1 + t2 * t2) / tm / 1000 * 60;
}
// 记录当前站点编号 
int id = 1;
// 存放站点信息的结构体数组 
struct Station {
	int x, y;
} station[N]; 
double dijkstra(int st) {
	for (int i = 1; i < id; i++) dist[i] = INF;
	// 注意起点不用走，终点可能没有地铁能够直接到达所以要手动初始化 
	dist[st] = 0, dist[201] = INF;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(.0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second;
		double wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[201];
}
int main() {
	memset(head, -1, sizeof head);
	int x, y, px, py;
	scanf("%d%d%d%d", &sx, &sy, &edx, &edy);
	// 这样输入可以不用判断第一个站点有没有上一个站点... 
	while (~scanf("%d%d", &station[id].x, &station[id].y)) {
		x = station[id].x, y = station[id].y;
		// 每个站点都可以直接走到终点或者起点
		add(0, id, cpl(x, y, sx, sy, 10));
		add(id, 201, cpl(x, y, edx, edy, 10));
		id++;
		while (~scanf("%d%d", &station[id].x, &station[id].y), station[id].x != -1) {
			// 获取上一个站点的信息 
			px = station[id - 1].x, py = station[id - 1].y;
			x = station[id].x, y = station[id].y; 
			// 上一个站点和当前站点可以通过地铁互相到达
			add(id, id - 1, cpl(x, y, px, py, 40));
			add(id - 1, id, cpl(x, y, px, py, 40));
			// 可以从上一个站点走到当前站点，当前站点也可以走回上一个站点，这个干脆改写在下面，因为可以从当前站点走到任意
			// 站点... 
			// add(idx, idx - 1, cpl(x, y, px, py, 10));
			// add(idx - 1, idx, cpl(x, y, px, py, 10));
			// 从当前站点可以是从起点走过来的，也可以直接走到终点 
			add(0, id, cpl(x, y, sx, sy, 10));
			add(id, 201, cpl(x, y, edx, edy, 10));
			id++; 
		}
	}
	// 每个站台之间可以步行  总共的标号是[1, id-1]，因为是idx++，所以最后结束输入的时候的那个点是不存在的... 
	int tx1, tx2, ty1, ty2;
	// for (int i = 1; i < id; i++) cout << station[i].x << ' ' << station[i].y << endl;
	for (int i = 1; i < id; i++) {
		for (int j = i + 1; j < id; j++) {
			tx1 = station[i].x, ty1 = station[i].y;
			tx2 = station[j].x, ty2 = station[j].y;
			add(i, j, cpl(tx1, ty1, tx2, ty2, 10));
			add(j, i, cpl(tx1, ty1, tx2, ty2, 10));
		}
	}
	// 四舍五入输出 
	printf("%d", (int)(dijkstra(0) + 0.5));
	return 0;
}
//#include <cstdio>
//#include <cmath>
//#include <iostream>
//#include <cstring>
//#include <queue> 
//using namespace std;
//const int N = 205, M = 5e4 + 5;
//struct E {
//	int v, next;
//	double w;
//} e[M];
//struct Stop {
//	int x, y;
//} stop[N];
//int id = 1, x, y, lx, ly, sx, sy, ex, ey, len = 1, h[N];//id代表点的标号 
//bool vis[N]; //起点是0 终点的编号是201 因为最多有200个站点 
//double d[N];
//double getD(int x1, int y1, int x2, int y2, int t) {
//	double x = x1 - x2;
//	double y = y1 - y2;
//	cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << t << endl;
//	cout << sqrt(x*x + y*y) / t / 1000 * 60 << endl;
//	return sqrt(x*x + y*y) / t / 1000 * 60; 
//}
//void add(int u, int v, double w) {
//	e[len].v = v;
//	e[len].w = w;
//	e[len].next = h[u];
//	h[u] = len++;
//}
////若a > b 返回true a <= b 返回false 
//bool cmp(double a, double b) {
//	if (a - b > 1e-4) return true;
//	return false;
//}
//void spfa() {
//    for (int i = 1; i < id; i++) d[i] = 1e18; 
//	d[0] = 0; d[201] = 1e18;
//	queue<int> q;
//	q.push(0);
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		vis[u] = false;
//		for (int j = h[u]; j; j = e[j].next) {
//			int v = e[j].v;
//			double w = d[u] + e[j].w;
//			if (cmp(d[v], w)) {
//				d[v] = w;
//				if (!vis[v]) q.push(v), vis[v] = true;
//			} 
//		}
//	}
//}
//int main() {
//	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
//	while (~scanf("%d%d", &stop[id].x, &stop[id].y)) {
//		x = stop[id].x, y = stop[id].y;
//		add(0, id, getD(x, y, sx, sy, 10));
//		add(id, 201, getD(x, y, ex, ey, 10));
//		++id; 
//		while (scanf("%d%d", &stop[id].x, &stop[id].y), stop[id].x != -1) {
//			x = stop[id].x, y = stop[id].y;
//			lx = stop[id - 1].x, ly = stop[id - 1].y;
//			//从站点步行到终点 和起点 
//			add(0, id, getD(x, y, sx, sy, 10));
//			add(id, 201, getD(x, y, ex, ey, 10)); 
//			//建立与前一个站点的边
//			add(id, id - 1, getD(x, y, lx, ly, 40)); 
//			add(id - 1, id, getD(x, y, lx, ly, 40));
//	 		++id; //-1的时候id不变 
//		} 
//	}
//	//每个站台之间可以步行  总共的标号是【1, id-1】 
//	// for (int i = 1; i < id; i++) cout << stop[i].x << ' ' << stop[i].y << endl;
//	for (int i = 1; i < id; i++) {
//		for (int j = i + 1; j < id; j++) {
//			x = stop[i].x, y = stop[i].y;
//			lx = stop[j].x, ly = stop[j].y;
//			add(i, j, getD(x, y, lx, ly, 10));
//			add(j, i, getD(x, y, lx, ly, 10));
//		}
//	}
//	spfa();
//	printf("%d", int(d[201] + 0.5));//四舍五入 
//	return 0;
//}
///*
//0 0 10000 1000
//0 200 5000 200 7000 200 -1 -1
//0 0 200 0 10
//nan
//0 10000 200 1000 10
//59.8077
//5000 0 200 200 40
//7.5
//5000 0 200 200 40
//7.5
//5000 0 200 0 10
//29.976
//5000 10000 200 1000 10
//29.6135
//7000 5000 200 200 40
//3
//7000 5000 200 200 40
//3
//7000 0 200 0 10
//41.9829
//7000 10000 200 1000 10
//17.3482
//2000 600 5000 600 10000 600 -1 -1
//2000 0 600 0 10
//11.4473
//2000 10000 600 1000 10
//47.94
//5000 2000 600 600 40
//4.5
//5000 2000 600 600 40
//4.5
//5000 0 600 0 10
//29.7832
//5000 10000 600 1000 10
//29.9038
//10000 5000 600 600 40
//7.5
//10000 5000 600 600 40
//7.5
//10000 0 600 0 10
//59.8919
//10000 10000 600 1000 10
//nan
//
//*/
