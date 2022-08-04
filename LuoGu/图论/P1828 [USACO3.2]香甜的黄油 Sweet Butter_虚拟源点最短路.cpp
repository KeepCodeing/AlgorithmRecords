#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ����һ���������⣬�����Ҳ������Դ�㣬ֵ��ע����Ƿ���ͼ�ƺ����ռ�����Ƚ϶࣬������Դ����
// �������Ƚ϶࣬�����仹�и��߼����÷�.. 
// ׹�٣������ֳ���w������Դ��ֻ����������ͼ...
// ��������n�����·��Ȼ��ͳ�ƾ���.. 
// ������Ŀ����˼����ʵ�������ĳ��ũ����������ţũ�������·֮�ͣ���Ϊ��˫��ߣ�����������ũ��ȥ�Ǹ�
// ũ�������·ʵ��Ҳ��������Ǹ�ũ���������·... 

typedef pair<int, int > PII;
// �ռ��ֿ�СRE��w 
const int P = 1800 + 10, N = 1500 + 10, M = 11450 * 2 + 10, INF = 0x3f3f3f3f;
int farmes[P];
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool vis[N];
int n, p, c, ut, vt, wt;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top(); que.pop();
		int ut = now.second, wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
	int res = 0;
	// �����ǰ�㵽������ţ�ڵ������ĺͣ�ͬʱҲ��ζ������ţ�����ũ���ĺ�.. 
	for (int i = 0; i < n; i++) {
		if (dist[farmes[i]] == INF) return INF;
		res += dist[farmes[i]];
	}
	return res;
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d%d%d", &n, &p, &c);
	for (int i = 0; i < n; i++) scanf("%d", &farmes[i]);
	while (c--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
		add(vt, ut, wt);
	} 
	int res = INF;
	for (int i = 1; i <= p; i++) res = min(res, dijkstra(i));
	printf("%d", res);
	return 0;
}
