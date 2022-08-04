#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// ����ⶼ������ͨ��������Ȩ��Ȼ�������뱻�ƻ���·��ʱ������ƻ���·�ӱ�Ȩ�����·����five��˼·���Ƚ��߼ӱ�Ȩ
// Ȼ�������·ͳ��·���ܳ��ȡ���·���ƻ�����һЩ��ȨΪ0�ıߣ����ܴ����·ͳ��·���ܳ������Ĳ����Ҫ�޵�·��
// ����... 
// �������ݷ�Χ�ǳ�С����ʵ����floyd... 

// ��Ϊû�п��Ǽ�0�ߵĿռ�����WA�ˣ���֪��Ϊʲôֻ��WAw 

typedef pair<int, int > PII;
// ���ǵ�������ɸ�0�����пռ�ÿ����... 
const int N = 2100, M = N * 10 +10;
int head[N], e[M], ex[M], w[M], idx = 0, INF = 0x3fffffff;
PII ptemp[M];
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	fill(dist, dist + M, INF), fill(visited, visited + N, false);
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
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed];
}
int main() {
	// �������Ǹ�... 
	fill(head, head + N, -1);
	int n, m, ut, vt, wt, d, st, ed, dst, ded;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// ˫��� 
		add(ut, vt, wt), add(vt, ut, wt);
	}
	scanf("%d", &d);
	// ��Ϊ�����������յ㣬��������ðѱ��ƻ���·������ 
	for (int i = 1; i <= d; i++) scanf("%d%d", &ptemp[i].first, &ptemp[i].second);
	scanf("%d%d", &st, &ed);
	// ��st��ed��һ�����·
	dst = dijkstra(st, ed);
	// �ӱ�ȨΪ0�ı�����һ��
	for (int i = 1; i <= d; i++) add(ptemp[i].first, ptemp[i].second, 0), add(ptemp[i].second, ptemp[i].first, 0);
	ded = dijkstra(st, ed);
	printf("%d", dst - ded);
	return 0;
}
