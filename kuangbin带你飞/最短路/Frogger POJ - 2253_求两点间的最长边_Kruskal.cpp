#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// û�п�����Ŀw�����˱��˵Ĳ��Ͳŷ�������������ʵ������֮�����ߣ���ô������Ϳ�������С��������������Ϊ����
// �ⲻҪ���ߵ�˳��ʲô�ģ�ֻҪ���ߵ�·���е���ߡ�����ν�ߵ�·�����ǵ�1���2�����������Щ�ߣ�����1���2������
// �ɻ��˾�˵��1�㵽��2�㣬�������Kruskal��˼·��������1���2��ɻ���ʱ��������߾�һ�������... 
// ��������ʵҲ�����ˣ��������涼�Ƚ����뵽��С�����������... 

const int N = 200 + 10;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	// ע��const... 
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[N * N]; // �����СӦ��ֻ�ÿ�һ�룬��Ϊ�����ѭ������Ǹ��Ȳ����У�����Ϊ�˱��տ����... 
struct unionFind {
	int bin[N];
	void _init() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
unionFind u;
int main() {
	int n, cnt;
	for (int T = 1;; T++) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		}
		u._init();
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v);
				if (u.ask(1, 2)) {
					printf("Scenario #%d\n", T);
					printf("Frog Distance = %.3lf\n\n", graph[i].w);
					// �����˽��Ҫ�˳�����Ȼ���������𰸣��Ӷ�WA... 
					break;
				} 
			}
		}
	}
	return 0;
}
