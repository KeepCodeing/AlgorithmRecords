#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ������������֪���Ǹ���С���������⣬ԭ���������û���ᵽȫ��ͨ��Ҳû�к�ֱ�ӵ�˵Ҫʹ�ܱ�Ȩ��С...
// ��ôҪ��ľ�����С����������ߵĳ��ȣ������ֿ�������Ŀ������������������ߵĳ��ȣ�����
// ��һ���ܵ��յ�ıߵĳ���...��������Ϊ����ҲҪ��ʼ�ˣ����ԵüӰѾ���w... 

const int M = 1e5 * 5 + 10, N = 1e4 * 2 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
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
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	}
	sort(graph, graph + m);
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) u.uni(graph[i].u, graph[i].v); 
		// s����t���һ�����ı�һ�������б�����̵ģ�Ҳ�����ڵ�ǰ�������������С���Ǹ���... 
		if (u.ask(s, t)) {
			printf("%d", graph[i].w);
			return 0;
		}
	}
	return 0;
}
