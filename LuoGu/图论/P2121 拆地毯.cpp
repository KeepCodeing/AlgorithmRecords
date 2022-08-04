#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ��Ƚ��˼���ȫ�����ˣ��գ���ϣ���������AC��������ͦ�����.. 

const int N = 100000 + 10;
struct Node {
	int u, v, w;
	bool operator<(const Node& n) const {
		// ���������... 
		return w > n.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, m, k, res = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	sort(graph, graph + m);
	unionFind uf;
	for (int i = 0; i < m; i++) {
		if (!uf.ask(graph[i].u, graph[i].v)) {
			// ���˰���Ϊʲô�Լ������������л���Ȼ��һ�����뷢����������... 
			uf.uni(graph[i].u, graph[i].v); 
			res += graph[i].w;
			k--;
			if (!k) break;
		}
	}	
	printf("%d", res);
	return 0;
}
