#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ��һ�ۿ�������е��ɣ���Ϊ�������С�����t���ӱߡ��ĸо���������ʵ�ϻ�����ͼ�Ϳ������ˣ�����t�ӱߡ���ʵ�Ǹ�����
// ���ŵĹ��̣�Ҳ����һ���ߵ�t�ڼ���ʱ�������бߵ�tҲ�ڼ��١���ô�����һ�뷨���Ǹ���С����������t����t���Ǳ�Ȩ��
// Ȼ��ͳ��������t������������һ������ȫ��ͨ���޻��ұ�Ȩ�����С��

// Ȼ�����±�ǩ����û�����������ɻ��ܵ���⿴���£�ԭ��Ҳ�����ò��鼯��д����ʵ�����˲��鼯��Ҳ�����и���Ҫ��
// ʲôʱ����ֻ�·�Ǹ�˼�룬����̫��û���������ʵ�֡�
// ���鼯��ʵ�֣��Ա�Ȩ��������Ȼ�󰴱�Ȩ��С�������ߣ�ÿ����һ�����ܱ�����-1��������е���ͨ��һ����n-1���ߣ�Ȼ��
// ���߹�����ͳ��������Ȩ�����˼·����С��������˼·��ʵһģһ����ֻ��������д������˵��������˼·���Ǻܾ��вο�
// �Եġ�

// ��������С������д���ˣ���Ϊ������... 

// ֵ��һ����ǿռ俪С����RE�ˣ���ô����N = 1k�� M = 10w��ʱ��N��ÿ�500����50w����M��ÿ�5����50w��
// �����register��ѭ���Ϻ���ҲûʲôЧ��.. 

const int N = 1000 * 100 * 5 + 10, M = 100000 * 5;
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
	int n, m, ut, vt, wt, cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	int res = -1, pcnt = 0;
	for (register int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) res = max(res, graph[i].w), pcnt++, u.uni(graph[i].u, graph[i].v); 
	}
	if (pcnt != n - 1) printf("%d", -1);
	else printf("%d", res);
	return 0;
}
