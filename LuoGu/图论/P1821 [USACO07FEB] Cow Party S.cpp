#include <iostream>
#include <cstdio>
#include <queue> 
#include <cstring>
using namespace std;

// ��֪��Ϊʲô��������������...��֮������ϰ���·��... 

typedef pair<int, int > PII;
// ����� 
const int M = 1e5 + 10, N = 1e3 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int _head[N], _e[M], _ex[M], _w[M], _idx = 0;
int dist[N], _dist[N];
bool visited[N];
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// Ϊ�˷�ֹ����ȫ�ֱ������ﶼ���˸�t�����㷨���ּǴ���w 
void dijkstra(int st, int et[], int ext[], int wt[], int headt[], int distt[]) {
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	distt[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wtt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// ����Ҫ�ò���ָ��ȴд���˰��ӵ��½���������мw..��ô�����������·��ðѰ��ӱ���Ҳ������... 
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (distt[vt] > wtt + wt[i]) {
				distt[vt] = wtt + wt[i];
				que.push(PII(distt[vt], vt)); 
			}
		}
	} 
}
int main() {
	// ��Ϊ��ָ�봫�ζ��䲻֪����ô��ʼ��ָ��w�ʶ�����ͳһ��ʼ��... 
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	memset(dist, 0x3f, sizeof dist);
	memset(_dist, 0x3f, sizeof _dist);
	int n, m, x, ut, vt, wt;
	scanf("%d%d%d", &n, &m, &x);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// ����ߣ���������xΪ��������·���Ի�û�ȥ�����· 
		add(ut, vt, wt);
		// ����ߣ���������xΪ��������·���Ի���������· 
		_add(vt, ut, wt);
	}
	 
	dijkstra(x, e, ex, w, head, dist);
	dijkstra(x, _e, _ex, _w, _head, _dist);
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dist[i] + _dist[i]);
	printf("%d", res);
	return 0;
}
