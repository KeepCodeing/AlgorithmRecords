#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// �����1���յ���n������ͼ 
// ������SPFA�ж��������ⲻһ������ȻҲ���Զ����Ȩ���������������ظ�
// �ߵĹ���... 
// �ƺ���������w����Ŀ����Ĺ�ʽL + X / C��������ǵ�ǰʱ�䣬��һ������ݻ���C����;��������·����
// ��С�ģ���L��һ���ۼӵģ�Ҳ���Ǿ������ٸ�·��L�ͼӶ���... 
// ��ô�������ü�¼·���ķ�������¼��һ�������Ϣ... 

// ע���Ȩ�Ǹ����� 
typedef pair<double, int > PII;
const int N = 500 + 10, M = N * 2, INF = 0x3f3f3f3f;
int head[N], e[M], ex[M], l[M], c[M], idx = 0;
pair<int, int > graph[N][N];
// ��ȨΪ�����ͣ��������Ҫȡ����ȥ 
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
			// ��;���ӳٺ� + X / ��С�ݻ� 
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
	// ��ʼ���ڽӾ��� 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = pair<int, int >(INF, INF);
		}
	}
	// �����ڽӾ������룬Ȼ�����ر�ѡ����ŵ� 
	while (m--) {
		scanf("%d%d%d%d", &ut, &vt, &lt, &ct);
		graph[ut][vt] = pair<int, int >(min(graph[ut][vt].first, lt), min(graph[ut][vt].second, ct));
	}
	// ���ڽӾ���ת��Ϊ�ڽӱ� 
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
