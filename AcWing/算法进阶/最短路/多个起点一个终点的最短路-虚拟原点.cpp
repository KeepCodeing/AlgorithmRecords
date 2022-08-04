#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

// ����Դ���㷨������չ���ж�����������������ͼֻ����ֻ��һ���յ����������Ҫ�����յ������Ҫ��n�����·��w 
// ���������ж����㣬�����յ㣬Ҫ����Щ��㵽�յ�����·����silver cow party��ͬ���Ǹ���Ҳ��һ���յ㣬���
// ��㣬��ͬ���ǻ�Ҫ��һ�λ�ȥ�����·��Ҳ����Ҫ���յ㵽����������·������ⲻ�����ȥ�����·����ô��ʵ���ǻ���
// ���Է���ͼ���յ�������·��Ȼ��Աȳ��ȡ�
// �����������Դ��ķ�ʽ�����������·�����ǽ���һ�����Ϊ0�ĵ㣬�������������㶼��һ����ȨΪ0�ıߡ������
// �Ǵ�ͼ�Ͽ���0�㵽�յ�ľ���Ͱ�����������㵽���յ�ľ��벢�����������Ա�֤��̻���˵�޷��ﵽ�� 
// ���̣�HDOJ�ı���������Ӧ��ѡG++... 
// �����������㷨������������ʱ��û������..

// ע�⣺���ӲҪ��sliver cow party�ԱȵĻ���sliver cow party�ĵ�һ�δ��յ������·û�з���ͼ����Ϊ���ܵ���һ��
// ��ȥ�Ĺ��̣�����ֱ���ܾ��С���ô����ⷴ��ͼ����ʵ���Ǻ���ţ�ɶ�ȥ�Ĺ������ƣ�ֻ������������ǵ�����̾��룬��
// �������е����̾���֮�ͣ���Ҳ��Ϊʲô�����Ҳ�ܷ���ͼ�ܵ�ԭ��... 

// ��ΪҪ���һ���㣬�������鷶Χ��ö࿪�㣬��������ͼ���ÿ������ı� 

const int N = 1000 * 2 + 10, M = 21000 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
// �����������װ����ˣ�����Ҫ�ǵó�ʼ�� 
int dijkstra(int st, int ed) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed] == INF ? -1 : dist[ed]; 
}
int sts[N];
int main() {
	int n, m, ed, ut, vt, wt, q;
	scanf("%d", &m);
	// ��������,���붥�������������յ� 
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	scanf("%d", &q);
	// ������㣬��������Դ������ 
	while (q--) {
		scanf("%d", &ut);
		// ������㶼������Դ��0��һ����ȨΪ0�ı� 
		add(0, ut, 0);
	}
	// ���������Ǵ�0����һ�����·��Ȼ���ж����ܲ��ܵ��յ㣬�ܵ���̾����Ƕ��� 
	printf("%d\n", dijkstra(0, ed));
	return 0;
}


// ����ͼ�����յ���һ�����·��Ȼ��ȡ�����ľ�����Сֵ 
/*
while (~scanf("%d%d%d", &n, &m, &ed)) {
	// ��ͼ
	fill(head, head + N, -1), idx = 0; 
	int cnt = 0, res = INF;
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(vt, ut, wt);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &sts[++cnt]);
	}
	dijkstra(ed);
	for (int i = 1; i <= cnt; i++) res = min(res, dist[sts[i]]);
	printf("%d\n", res == INF ? -1 : res);
}

void dijkstra(int st) {
	fill(dist, dist + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
*/
