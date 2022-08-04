#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// �������Ҫ����ǵڶ��̵����·�����ζ�·���⡣����˼����Dijkstra�����·����ô��ģ������㷨����һ���ɳ�
// ����������ö�ٵ�ǰ������бߣ�Ȼ���ж������ǰ��ͨ�������ߵ���һ����ľ����Ƿ���̣������̣��ͽ���һ���� 
// �ľ������Ϊ���̾��룬Ȼ���������ӣ��´α�����ʱ��ͻ�ӵ�ǰ�����б��ܵ��ĵ��б�Ȩ��С���Ǹ��㿪ʼ��
// ��������˼·���Լ��޸ģ��Ϳ��Եõ��ζ�·�����ˡ��ڱ�����ʱ�򣬲���Ҫ��¼���·�ľ��룬��Ҫ��¼�ζ�·�ľ���
// ���������·�ľ������жϵ�ǰѡ��������ǲ��ǵڶ��̵ģ���Ϊ��u->v�Ĵζ�·�޷Ǿ����������һ����u�Ĵζ�·->v��
// һ����u->v�����·����ȷ����һ��֮��ʣ�����ľͺ�Dijkstra���·�����ˡ� 
// ����Ҫע������ϵļ������𣬱���Ҫ��֤��ǰѡ�ı߲�����̱ߣ�����߿��Զ���ߣ�û��visited��ǣ���... 

typedef pair<int, int > PII;
const int N = 5000 + 10, M = 100000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
// �����·�ʹζ�·���� 
int dist[N], dist2[N];
int n, m;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(dist2, 0x3f, sizeof dist2);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	// ע������ζ�·�������㲻�ܽ��и�ֵ����Ȼ�����жϵ�ǰ�����Ƿ��Ǵζ̵�ʱ�����Ϊ���û�дζ�·���ڣ�Ҳ����
	// ˵��������ȫ�ᱻ���� 
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		// �����ǰ��ı�Ȩ����С�ģ��Ǿ���ζ������߲�����Ϊ�ζ̱�ʹ�ã�����Ҫ���� 
		if (dist2[ut] < wt) continue;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// ��Ϊwt + w[i]�����õ������Կ����ø����������� 
			int dt = wt + w[i];
			// ����̾��룬����ѡ�ζ̾���
			if (dist[vt] > dt) {
				dist[vt] = dt;
				que.push(PII(dist[vt], vt)); 
			}
			// ��ζ�·�ĺ��Ĵ��룬ֻҪ��ǰ��Ȩ������С�ģ��ǾͰ��������Ϊ���ܵĴζ̱߼������������ж�
			// ��ǰ���Ƿ���С��Ҫͨ�����·�������ˣ�Ҳ����˵���·���������ֻ�������жϵ�ǰ���ǲ�����̵�... 
			if (dist2[vt] > dt && dist[vt] < dt) { // ��ζ̾��룬ֻҪ��ǰ�߲�����̵ľͿ���������ζ�·.. 
				dist2[vt] = dt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	}
	return dist2[n];
}
int main() {
	// ���˳�ʼ��ͷ���... 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	printf("%d", dijkstra(1));
	return 0;
}
