#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ��Ŀ������������
// 1.Ҫ�����е�·��ͨ 2. Ҫ����ĵ�·������ 3. Ҫ���ؽ���ĵ�·�е�����ֵ��С
// ����1. ����Ҫ��ȫ��ͨ����������һ���ص㡣����2. ��ȻҪȫ��ͨ����ô����������������
// ���õ���ͼһ��ֻ��n-1���ߡ�����3. Ҳ����˵Ҫ��������С������������Ȩ��ͳ�Ƽ��ɡ� 

const int N = 100000 * 5 + 10;
struct G {
	int u, v, w;
	bool operator<(const G& g) {
		return w < g.w;
	}
	
} g[N];
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
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
	sort(g, g + m);
	int res = -1, cnt = 0;;
	for (int i = 0; i < m; i++) {
		// ͳ����С�������������Ȩ�Լ����� 
		if (!u.ask(g[i].u, g[i].v)) 
			res = max(res, g[i].w), u.uni(g[i].u, g[i].v), cnt++;
	}
	printf("%d %d", cnt, res);
	return 0;
}
