#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

// �����Ҫ���¼���·������ô˼·������ͼ�����·����࣬���Ǽ�¼ǰ���ڵ�Ȼ��ԭ.. 
// TLE�ˣ��ɹ�... 

typedef long long LL;
typedef pair<int, int > PII;
const int N = 1e5 + 10, M = N * 2;
const LL INF = 9223372036854775806;
int head[N], e[M], ex[M], w[M], idx = 0;
// ע��Ҫ��long long����Ȼ�ᱬ... 
LL dist[N];
// ע�����ﲻ��������ı�����prev�������������Ļ���������ͻ����CE����... 
int pre[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// ��д��Dijkstra���ٲ���¼·��
bool dijkstra(int st, int ed) {
//	memset(dist, 0x3f, sizeof dist);
	// ��ʼ��ʼ��·�����飬��Ȼ�յ��ǲ�ȷ���ģ���Ϊ1��һ�����ŵ�n... 
	memset(pre, -1, sizeof pre);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				// ��¼��ǰ�����һ����ı�� 
				pre[vt] = ut;
				que.push(PII(dist[vt], vt));
			}
		}
	}
	if (dist[ed] == INF) return false;
	return true;
} 
int main() {
	memset(head, -1, sizeof head);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) dist[i] = INF;
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	// �������1~n�����·�������·��������дҪ�������������������Բο�����ͼ�ı�������
	// ֱ�Ӵ��յ������·��Ȼ���������·���� 
	if (dijkstra(n, 1)) {
		int now = 1;
		for (; now != -1; now = pre[now]) cout << now << ' ';
		return 0;	
	} 
	printf("-1");
	return 0;
}
/*
5 5
1 2 2 2
2 3 1 1
1 4 1 1
4 5 1 1
5 3 1 1
*/
