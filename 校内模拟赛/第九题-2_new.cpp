#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// ������ʱ����Ϊ�����·��Ȼ��ȴ��֪����Ȩ��ô�㣨���ܣ���������ʼˢ���·��ʱ��������ͬ�������������
// ���Ǿ�֪���˱�Ȩ��һ��Ҫ�������������������ʵ����С���������ؼ����ǻ��������ȫ��ͨ... 

const int N = 1000 * 10 + 10;
struct pos {
	int x, y, h;	
} ps[N];
struct Graph {
	int u, v;
	double w;
	Graph(int u, int v, double w) : u(u), v(v), w(w) {};
	Graph() {};
	bool operator < (const Graph& g) {
		return w < g.w;
	}
} G[N];
double getDist(int x1, int y1, int x2, int y2, int h1, int h2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + (h1 - h2) * (h1 - h2);
}
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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &ps[i].x, &ps[i].y, &ps[i].h);
	}
	int cnt = 0;
	// �ӱ�Ȩ����Ϊ������ͼ����һ���㵽��һ����ı�Ȩ��һ�ξ��У���j = i + 1��֤��i����j�ı�Ȩ�ܱ��㵽��ֻ��һ�� 
	// ע����� i��jӦ��ͳһ��1��ʼ��ͬ����Ҳ�ͱ����<=n�����Ǹ��޿ӣ���������������������������������Ȼ����Ϊ
	// �±걬0��Ϊ����ʾ���þͲ����ˣ� 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			G[cnt++] = Graph(i, j, getDist(ps[i].x, ps[i].y, ps[j].x, ps[j].y, ps[i].h, ps[j].h));
		}
	}
	sort(G, G + cnt);
	double res = 0;
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(G[i].u, G[i].v)) {
			res += G[i].w;
			u.uni(G[i].u, G[i].v); 
		}
	}
	printf("%.2lf", res);
	return 0;
}
/*
4
1 1 3
9 9 7
8 8 6
4 5 4
*/
