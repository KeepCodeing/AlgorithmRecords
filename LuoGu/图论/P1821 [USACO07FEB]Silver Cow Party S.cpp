#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// Ŀǰ��˼·�Ǵ�x����һ�����·��Ҳ��������ţ��ȥ��·�̣��ٶ�ÿ������һ��
// ��x�����·��Ҳ����ÿͷţ����·�̣�Ȼ����ӶԱ����ֵ... 

// �������n�����·�����㷨Ч��̫���ˣ���������ûTLEw����ȷ�������ǽ�����ͼ
// һ����������һ�����������о������е��ɣ������ϵ�ʵ����a->b��һ��ͼ��b->a��һ��
// ͼ��Ȼ���������ͼ��һ�����·�����Ǵ�x��ʼ������ſ���������a->b�����a->b�����·����
// b->a�����b->a�����·���ɴ˾Ϳ����������·������е������·�ˣ��ɹţ� 

// �Է���ʱ����ͨ�ˣ����Ž�ͼ��x�������������x������������·���ѱ�Ȩ�����������Ǵ�x�������·
// �����ͱ����x�ߵ������е㵽x�ıߵ�Ȩ��Ҳ�ͱ�������е㵽x�����· 

typedef pair<int, int > PII;
const int N = 1010, M = 100000 * 2 + 10, INF = 0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int edist[N], dist2[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	fill(visited, visited + N, false);
	edist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (edist[vt] > w[i] + wt) {
				edist[vt] = w[i] + wt;
				que.push(PII(edist[vt], vt)); 
			}
		}
	} 
}
int dijkstra2(int st, int x) {
	fill(visited, visited + N, false);
	fill(dist2, dist2 + N, INF);
	dist2[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist2[vt] > w[i] + wt) {
				dist2[vt] = w[i] + wt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	} 
	return dist2[x];
}
int main() {
	int n, m, x, ut, vt, wt;
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i <= n; i++) head[i] = -1, edist[i] = INF;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt); // ����ͼ���������ͼ... 
	}
	// ��һ��x��������ľ��룬����ţ��ȥ�ľ��� 
	dijkstra(x);
	for (int i = 1; i <= n; i++) printf("%d ", edist[i]);
	puts("");
	// ����һ�����е㵽x�ľ��룬Ҳ�������ľ���
	for (int i = 1; i <= n; i++) edist[i] += dijkstra2(i, x), cout << dijkstra2(i, x) << ' ';
	int res = -1;
	for (int i = 1; i <= n; i++) res = max(res, edist[i]);
	printf("%d", res);
	return 0;
}
