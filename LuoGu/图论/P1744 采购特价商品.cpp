#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// ͻȻ���ú���ǰ�����ű�ʡ��ģ���һ���⣬�����ͬ���Ǹ���������ʽ�����ǵ�
// ��ʽ���������Ҫ�����·һ���Ǹ����ɸ������ţ�Ȼ���ж�Ӧ�ıߵı�Ȩ��
// ���Կ��Կ��ǰ�����˳�򵱳ɵ�ı�ţ������Ȩֵ�������ǵ�ֱ�߾���.... 

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
	// ���˰���bug��ԭ������head�������⣬����dijkstra��������е���䣬��Ҳ����ζ�Ŷ��뽨ͼȫ��ľ����w 
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
