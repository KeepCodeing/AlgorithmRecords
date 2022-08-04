#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

// 这种类型的最短路应该是第一次做，不过在最小生成树里已经接触过了，大致的思路就是先算出所有点的距离，然后加边，
// 最后计算最短路就行了 
// 这里想了下为什么这个题是最短路，首先青蛙应该能直接跳到终点，但是题目里给出的提示是青蛙不能 跳太远，需要借助中间的石头，
// 那这就很类似Dijkstra里的思想，就算能直接到，也先对比是通过中间点到更短直接到更短... 

// 似乎不是裸的最短路题...这个题要最大化最小值...，可以用Kruskal做，不过至今没有搞懂原理... 

typedef pair<double, int > PII;
// 无脑开大，不然很可能意外REw 
const int N = 1e6 + 10, M = 1e6 * 5 + 10;
// 存放点对的结构体，虽然用pair更方便，不过单独用个结构体更加和习惯 
struct Pos {
	int x, y;
} pos[N];
int head[N], e[M], ex[M], idx = 0;
// 两点之间的距离应该是实数，因此边权也是实数 
double w[M], dist[N];
bool visited[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
double dijkstra(int st, int ed) {
	// 注意memset不能用在double类型的数组上... 
	for (int i = 0; i < N; i++) dist[i] = 1e9 + .0;
	memset(visited, 0, sizeof visited);
	dist[st] = .0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(.0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second;
		double wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				// printf("--%lf--\n", dist[vt]);
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	
	return dist[ed]; 
}
int main() {
	int n;
	double temp;
	for (int t = 1;; t++) {
		scanf("%d", &n);
		if (!n) break;
		memset(head, -1, sizeof head);
		// 为了避免像在聪明的猴子那个题一样出下标坑这里下标也从1开始 
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		// 计算所有点对之间的距离，并且加边 
		// int cnt = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				// printf("%d %d %.3lf\n", i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
				temp = cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y);
				add(i, j, temp), add(j, i, temp);
				// cnt++;
			}
		}
		
		printf("Scenario #%d\n", t);
		printf("Frog Distance = %.3lf\n\n", dijkstra(1, n));
		// for (int i = 1; i <= cnt; i++) printf("%lf ", dist[i]);
	}
	return 0;
}
