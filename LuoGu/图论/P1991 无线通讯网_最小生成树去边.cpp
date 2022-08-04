#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// ��ʵ�Ѿ���vjudge������������ˣ���������ϵ���Ŀ������춼��ⲻ��w��������˵�Լ��������������ûw...
// ��ô��Ŀ����˵���԰�װ���ߵ����վ���û�Ǯ�����ܰ�װ��Ҫ��Ǯ��Ȼ������С�Ļ�Ǯ���������Է���װ����
// ���������϶���ԽԶԽ����������ô����ͱ����ȥ��S����ߣ���ʣ�µı�����ߵĳ��ȡ� 

// һ���������⣬Ȼ����֪��Ϊʲô���˰���... 

// ֱ��N^2��ֹ��ը 
const int N = 500 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct Node {
	int u, v;
	double w;
	Node (int u, int v, double w) : u(u), v(v), w(w) {};
	Node () {};
	bool operator<(const Node& n) const {
		return w < n.w;
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
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
int main() {
	int s, n, cnt = 0;
	scanf("%d%d", &s, &n);
	s = n - s;
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	// �±��w
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = Node(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
		}
	} 
	sort(graph, graph + cnt);
	unionFind uf;
	double res = 0.0;
	for (int i = 0; i < cnt; i++) {
		int ut = graph[i].u, vt = graph[i].v;
		if (!uf.ask(ut, vt)) {
			uf.uni(ut, vt);
			// ���������һ��ʼ���뷨�Ǽ�0�ߣ�Ȼ�����������ƻ�ԭ����ͼ�����Ի���ֱ�������ߣ���ôһ��Ҫ�����������أ��Լ���ֵ��֪���ˣ�
			// ��n == 4, s == 2ʱ�����Է������ͼ����С��������3���ߣ���s == 2��ζ�ſ���ȥ��һ���ߣ����Ծ�ֻ����n - s���ߡ���s == 1ʱ��
			// Ҳ���ǲ���ʡ�ߣ�Ҫ���ı�Ҳ��n - s��...�ٽ�һ����һ��n�����ͼҪ��n - 1���ߣ����������� s - 1���ߣ��Ϳ��Եõ�һ��Ҫ��
			// n - 1 - (s - 1)Ҳ���� n - s����.. 
			if (--s == 0) {
				res = graph[i].w;
				break;
			}
		}
	}
	printf("%.2lf", res);
	return 0;
}
