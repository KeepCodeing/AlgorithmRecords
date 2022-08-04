#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �Ƿϵ����ڣ����������...������Ǹ���С���������⣬�������е���ģ���⣬���˸�������Ҫ�����б�Ȩ������C����ôһ����
// �������ߣ����ͳ���ǲ������е㶼�����˾��У�Ӧ�ã� 

// ����Ϊ�ռ�С��RE�ˣ�������Ŀӵ���Ǹ��˶����������ǲ���������һ����˵��1e6*5��û�����... 

// ��˵������������ռ�+/��ߵ��Ѷȣ������Ǳ�five��һ����ȫ�Լ�д����������Ѷȵ���w�����������������Ǹ�ģ���⣬��
// �����ĺ����Ǹ������ƣ������Ǹ���ӵ���������..��ָWA�˺ܶ�Σ� 

const int N = 2010, M = 1e6 * 5;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G() {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
struct POS {
	int x, y;
} pos[N];
int getdist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
struct unionFind {
	int bin[N];
	unionFind() {
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
	int n, c, cnt = 0;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	// �����Ȩ��ע��Ϊ��ͳһ�±�pos���������±�Ҳ��1��ʼ����֮�������±�����ν����������ѭ�����±�Ϊ0�ͻ����... 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = G(i, j, getdist(pos[i].x ,pos[i].y, pos[j].x, pos[j].y));
		}
	}
	sort(graph, graph + cnt);
	// printf("%d %d %d\n", graph[i].u, graph[i].v, graph[i].w);
	int flag = 0, res = 0;
	for (int i = 0; i < cnt; i++) {
		if (graph[i].w < c) continue;
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			res += graph[i].w, flag++;
			
		}
	} 
	// ����Ҫ��n-1������ͨ�������ͼ����ôͳ���¼��˶������߾�����... 
	if (flag != n - 1) res = -1;
	printf("%d", res);
	return 0;
}
