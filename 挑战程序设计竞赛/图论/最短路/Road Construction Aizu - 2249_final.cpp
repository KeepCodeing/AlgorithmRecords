#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// ��������������⣬�����û���������ô�ѡ�����֮������һ���⣬��Dijkstra���������Ҫ���������·�������Ǽ�¼�ķ���
// �����ø�pre�����¼��ǰ�����һ�������ĸ��㣬��Ϊ�����ߵ���һ�������·��������������ǿ��еġ���ô˼��������⣬
// �Ƿ�Ҳ����ת��Ϊ��¼·�������أ����ǿ��Եģ���������Ȿ���ϻ��������·�����Ե�һ���ߵ��ĵ�һ������̵ģ���ô
// ��Ȼ�����ľ�������̵ģ������Ļ��ѿ϶�Ҳ�Ǳ�ѡ�ģ����������pre�����¼��һ����Ļ��ѣ�Ȼ������������ˡ�˼����
// Ϊʲô���ܼ�¼��ţ���Ϊ��¼��Ž�Ϊ�鷳�����ʹ����ʽ��ǰ������ͨ���ڵ��Ż����·�Ļ��ѡ�
// �����������ڶ��������ת������ȫ����ͨ����¼��һ����Ļ��ѵķ�ʽ���������⡣

// ���������ɣ������С�����뷨��ȫ���ÿ���...
// �������ʵ�ܼ򵥣�ֻ���������븴���ˣ�ÿ�γ������·��ʱ����½�㻨�Ѿ����ˣ����·����ͬ��ȡ��Сֵ������
// ��¼ǰ����ȫ�Ǳ�����... 

typedef pair<int, int > PII;
const int N = 10000 + 10, M = 20000 * 2 + 10;
int head[N], e[M], ex[M], w[M], d[M], idx = 0;
int dist[N], cost[N];
bool visited[N];
void add(int ut, int vt, int wt, int dt) {
	e[idx] = vt, w[idx] = wt, d[idx] = dt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	// ע�������ݣ�����Ҫ��γ�ʼ��.. 
	memset(dist, 0x3f, sizeof dist);
	memset(cost, 0, sizeof cost);
	memset(visited, 0, sizeof visited);
	// ��pair����Ϊ�����ͻ��Ѽ���û��ʲô��ϵ��ֻ���ڼ�¼��ʱ����õ�
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	// ����������··�����Ǹ��ⲻͬ�����ﲻҪ���¼˳�����Բ���
	// ��ʼ��Ϊ-1֮��ı�ǽ�����ֱ��ȫ������������
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
				// ��¼��ǰ�ڵ����С���ѣ��������С���Ѿ���d[i]��������ĳ�������pre[ut]֮��Ķ���... 
				cost[vt] = d[i];
				que.push(PII(dist[vt], vt));
			} else if (dist[vt] == wt + w[i]) {
				// ������������·��ͬ�Ľڵ㣬ȡ��Сֵ������... 
				cost[vt] = min(cost[vt], d[i]);
			}
		}
	}
}
int main() {
	int n, m, ut, vt, wt, dt;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		// ��ʼ��ͷ��㣬���������idx��������ˣ���Ϊ�ж��Ƿ��б��жϵĻ����Ƿ���head.. 
		memset(head, -1, sizeof head);
		idx = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &ut, &vt, &wt, &dt);
			add(ut, vt, wt, dt), add(vt, ut, wt, dt);
		}
		dijkstra(1);
		int ans = 0;
		// �ۼӺ� 
		for (int i = 1; i <= n; i++) ans += cost[i];
		printf("%d\n", ans);
	}
	return 0;
}
