#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// 坠毁w，还以为是最小生成树...结果是个数论题w... 

const int N = 50000 + 10, M = N * 50;
typedef long long LL;
struct Pos {
	int x, y;
} pos[N];
struct Node {
	int u, v;
	LL dist;
	bool operator<(const Node& n) const {
		return dist > n.dist;
	}
	Node (int u, int v, LL dist) : u(u), v(v), dist(dist) {};
	Node () {};
} graph[M];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	};
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
int getdist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
	int n, cnt = 0, k = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = Node(i, j, getdist(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
		}
	}
	sort(graph, graph + cnt);
	unionFind uf;
	// 最小生成树的最后连上的那条边一定是最长的..
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].u, graph[i].v)) {
			uf.uni(graph[i].u, graph[i].v);
			cout << graph[i].dist << endl;
			k++;
			if (k == n - 1) {
				printf("%lld", graph[i].dist);
				break;
			}
		}
	} 
	return 0;
} 
