#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

// �������͵����·Ӧ���ǵ�һ��������������С���������Ѿ��Ӵ����ˣ����µ�˼·������������е�ľ��룬Ȼ��ӱߣ�
// ���������·������ 
// ����������Ϊʲô����������·����������Ӧ����ֱ�������յ㣬������Ŀ���������ʾ�����ܲ��� ��̫Զ����Ҫ�����м��ʯͷ��
// ����ͺ�����Dijkstra���˼�룬������ֱ�ӵ���Ҳ�ȶԱ���ͨ���м�㵽����ֱ�ӵ�����... 

// �ƺ�����������·��...�����Ҫ�����Сֵ...��������Kruskal������������û�и㶮ԭ��... 

typedef pair<double, int > PII;
// ���Կ��󣬲�Ȼ�ܿ�������REw 
const int N = 1e6 + 10, M = 1e6 * 5 + 10;
// ��ŵ�ԵĽṹ�壬��Ȼ��pair�����㣬���������ø��ṹ����Ӻ�ϰ�� 
struct Pos {
	int x, y;
} pos[N];
int head[N], e[M], ex[M], idx = 0;
// ����֮��ľ���Ӧ����ʵ������˱�ȨҲ��ʵ�� 
double w[M], dist[N];
bool visited[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
double dijkstra(int st, int ed) {
	// ע��memset��������double���͵�������... 
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
		// Ϊ�˱������ڴ����ĺ����Ǹ���һ�����±�������±�Ҳ��1��ʼ 
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		// �������е��֮��ľ��룬���Ҽӱ� 
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
