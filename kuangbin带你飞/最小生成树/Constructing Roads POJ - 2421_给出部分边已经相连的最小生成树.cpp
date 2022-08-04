#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������Ҳ���������ˣ������ĶԽǾ�����ô��Prim��ȽϺ�����Ŀ������һЩ���Ѿ�����������˵��Щ���ڽ�����С����
// ��֮ǰ�������ˣ�����˵��Щ�߱�ȨΪ0��������Ҫ�κλ��ѡ���ô�����뵽��������ϵ�һ���⣬��ž��Ǹ���һЩ���Ѿ�������
// Ȼ�󲿷ֱ�û��������Ҫ�����·������������İ�����������һ����������ͼ�Ǿ��Ի��ģ������������ܱ�֤�������·����ȷ
// ���������Ȳ�����ν���Ѿ�������ֱ���ܴ����·��������·��ֵ������ν���޺ú�Ļ��ѣ�Ȼ��Ա��޺õĵ�Լ�0�ߣ��������·
// �������ν���޸�ǰ�Ļ��ѣ�Ȼ������������ܵõ���ν���޺���Щδ�����ıߵĻ����ˡ���һ˲������·����ĸо���ww�������
// ��Ҳ��ͬ�����Ƕ��Ѿ��޺õĵ��0�߾�����...����һ��ʼ�����ֱ�����ߣ����Ǽ�0��Ȼ������С�����������Ļ��ƺ�������... 

const int N = 1e5 * 5 + 10;
struct G {
	int ut, vt, wt;
	G (int ut, int vt, int wt) : ut(ut), vt(vt), wt(wt) {};
	G () {};
	bool operator<(const G& g) const {
		return wt < g.wt;
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
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, cnt = 0, wt, m, ut, vt;
	scanf("%d", &n);
	// ע�������һ��ʼд��i = 0, j = 0���Ǿ�����ζ����Ŀ���ĵ��0��ʼ��ţ���ʵ������Ŀ���ĵ��1��ʼ���
	// �����������i��jҲ��1��ʼ.. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &wt);
			if (j > i) {
				graph[cnt++] = G(i, j, wt);
			}
		}
	}
	scanf("%d", &m);
	while (m--) {
		// ���������³������⣬����ut��vt������0... 
		scanf("%d%d", &ut, &vt);
		graph[cnt++] = G(ut, vt, 0);
	}
	sort(graph, graph + cnt);
	unionFind uf;
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].ut, graph[i].vt)) {
			uf.uni(graph[i].ut, graph[i].vt);
			res += graph[i].wt;
		}
	}
	printf("%d", res);
	return 0;
} 
