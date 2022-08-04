#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// �����⣬����Ҫע���ֵ��򣬸�����ĿҪ�󣬿���ʹ�յ���С������յ�����ͬ����ʹ�����С... 

// ��֪��ΪʲôRE�����Σ�һ����˵��ͼ���ռ�͸�����Ŀ����������������..Ȼ��ĵ��ر��
// �������һ����TLE��w���������ȥ��... 
const int N = 1e6 * 5 + 10, M = 1e6 * 5 + 10;
struct Node {
	int u, v;
	bool operator<(const Node& n) const {
		// �����ڽӱ����ȳ���ԭ��������������Ӧ�����յ�Ӵ�С��
		// ����С����.. 
		if (n.v != v) return v > n.v;
		return u < n.u;
	}
} tp[M];
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
bool visited[N];
void dfs(int ut) {
	printf("%d ", ut);
	visited[ut] = true;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (!visited[vt]) dfs(vt);
	}
}
int que[N];
void bfs(int ut) {
	int qtop = 0, qback = 0;
	que[qtop] = ut;
	while (qtop <= qback) {
		int now = que[qtop++];
		// ����֮ǰû������Ϊʲô�����ظ��ĵ����w��Ȼ��ŷ���now������ô�����ᱻ�����Ȼ����ǰ��ѧ��
		// Dijkstra��������ԭ�����������ʱ���еķ��ʹ���ǣ��ĳ��˵�ǰԪ�ر���ǣ�Ȼ�����.. 
		if (!visited[now]) printf("%d ", now), visited[now] = true;
		for (int i = head[now]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (!visited[vt]) que[++qback] = vt;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d%d", &tp[i].u, &tp[i].v);
	sort(tp, tp + m);
	// �����... 
	memset(head, -1, sizeof head);
	for (int i = 0; i < m; i++) add(tp[i].u, tp[i].v);
	memset(visited, 0, sizeof visited);
	dfs(1);
	puts("");
	memset(visited, 0, sizeof visited);
	bfs(1);
	return 0;
}
