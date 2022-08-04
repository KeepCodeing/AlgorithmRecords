#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ������֮ǰ��acwing�������Ǹ�����һ����...Ȼ�������û�п�����...
// һ�仰�ܽ��������Դ�����ֱ�ӵ���ͼ���ĳ���㣬��������㵽�������е�ľ��붼����С�ġ� 

// �������룬��������˵��̫�ԣ���ȷ�����Ӧ������0�����ĳ����Ҫ��ˮ�����������㵽���������С���붼����ˮ���Ļ��Ѵ�
// ��ô�������������ݣ���ˮ��һ���ᱻ��ѡ�� 

// RE�ˣ��ɴ˿ɼ�������ڽӾ��󵱳��ڽӱ����룬ҲҪ��֤�ռ���N * N���ϵ�... 
const int N = 1e5 + 10;
struct Node {
	int u, v, w;
	Node (int u, int v, int w) : u(u), v(v), w(w) {};
	Node () {};
	bool operator<(const Node& n) const {
		return w < n.w;
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
	int n, cnt = 0, wt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wt);
		graph[cnt++] = Node (0, i, wt);
	}
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &wt);
			if (j > i) graph[cnt++] = Node(i, j, wt);
		}
	}
	unionFind uf;
	sort(graph, graph + cnt);
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		int ut = graph[i].u, vt = graph[i].v;
		if (!uf.ask(ut, vt)) {
			uf.uni(ut, vt);
			res += graph[i].w; 
		}
	}
	printf("%d", res);
	return 0;
}
