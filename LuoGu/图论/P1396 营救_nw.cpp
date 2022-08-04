#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������Ҫ�õ�����С��������˼�룬�������յ��һ����ͨʱ����ǰ����ߵı�Ȩһ������С���ֵ����Ȼ���
// �����������������·����Ϊ�������ֻ�����ж���ͨ��Ļ�����ʹ�����ߵ�˳���С����ʼ���ѡ� 

// ����������С�����������·�����ֶ����������⣬��Ϊ̫����ֻ����С������д��������������С����������...
// ˼·�ǵ����е㶼��ͨʱ�������ͨ���Ǹ������ӵ������С���ĵ㡣����ͨ�������е㲻һ������ͨ��������
// �����б߶��������������ֻҪ�γ��˻��Ϳ��Եõ����ˡ� 

const int N = 1e6 * 10 + 1;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind () {
		for (register int i = 0; i < N; i++) bin[i] = i;
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
	int n, m, s, e, cnt = 0, ut, vt, wt;
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		u.uni(graph[i].u, graph[i].v);
		if (u.ask(s, e)) {
			printf("%d", graph[i].w);
			return 0;
		}  
		
	}
	return 0;
}
