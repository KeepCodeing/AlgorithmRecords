#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// �����ܶ����⣬����һ��Ҳ�޷�w�����������Ƶ����ʱ�򶼻��뵽����Դ�㣬
// ����ʵ�����õõ�����ȴ����..��������Դ�㣬��SPFA��w
 
typedef pair<int, int > PII;
const int N = 1000 + 10, M = 100000 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
int dist[N], _dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void dijkstra(int st, int headt[], int et[], int ext[], int wt[], int distt[]) {
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	distt[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, uw = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// ����д����ext[ut]���ƺ�������ѭ����w 
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (distt[vt] > uw + wt[i]) {
				distt[vt] = uw + wt[i];
				que.push(PII(distt[vt], vt)); 
			}
		}
	} 
}
int main() {
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	int ut, vt, wt;
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), _add(vt, ut, wt); // ����ͼ��һ˲��Ϊ�����������ͼw 
	}
	memset(dist, 0x3f, sizeof dist);
	memset(_dist, 0x3f, sizeof _dist);
	// ֱ�Ӵ�����Ͳ��ö�д��Dijkstra�� 
	dijkstra(x, head, e, ex, w, dist);
	dijkstra(x, _head, _e, _ex, _w, _dist);
	int ans = 0;
	// ��Ŀ�������·.. 
	for (int i = 1; i <= n; i++) ans = max(ans, dist[i] + _dist[i]);
	printf("%d", ans);
	return 0;
}
