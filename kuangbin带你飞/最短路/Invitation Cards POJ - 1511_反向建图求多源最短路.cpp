#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ������������w�����������뵽�˷���ͼ���Դ���·������Ȿ����˵����ţ�ɶԻ����ʵ�Ա������һ���ģ�����Ҫ��
// 1��n�����·��n��1�����·��ǰ����ͨ���·�����ˣ����߷���ͼ��1�ܾ�����...����������ƺ��������ֵ֮��Ķ���
// Ҫ��longlong�����ֵҲҪ���õı���ͨ���·��... 

typedef pair<int, int > PII;
typedef long long LL;
// ͻȻ�������ǵ���ߣ����ǵ����Ҳ��û����ν�ķ���ͼ�˰�w 
const int N = 1000000 + 10;
// ע�����ֵ������ 
const LL INF = 0x3f3f3f3f3f3f3f3f;
int head[N], e[N], ex[N], w[N], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int _head[N], _e[N], _ex[N], _w[N], _idx = 0;
LL _dist[N], __dist[N];
bool visited[N];
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void _init() {
	for (int i = 0; i < N; i++) _dist[i] = __dist[i] = INF;
}
LL dijkstra(int st, int n, int headt[], int et[], int ext[], int wt[], LL dist[]) {
	// ע��visitedҪ��γ�ʼ������Ϊ�����������·... 
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wtt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (dist[vt] > wtt + wt[i]) {
				dist[vt] = wtt + wt[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
	LL res = 0;
	for (int i = 1; i <= n; i++) res += dist[i];
	return res;
}
int main() {
	int T, n, m, ut, vt, wt;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head);
		memset(_head, -1, sizeof _head);
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, wt), _add(vt, ut, wt);
		}
		// ��ʼ�������������飬���з������� 
		_init();
		// �𰸾�������ͼ���������·֮��
		printf("%lld\n", dijkstra(1, n, head, e, ex, w, _dist) + dijkstra(1, n, _head, _e, _ex, _w, __dist));
	}
	return 0;
}
