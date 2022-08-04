#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// ����һ�ۿ���ȥ�Ƚ���w������һ�����ܿ�����ĿҪ�ʵľ������ж��ٸ�����
// ����Ծ�������С��������n - 1���ߴ���Ϊ��С���������Ա�֤���ж���
// ��ͨ�޻������ֵ��С��
// ��ͼ���ܱ���������˳���¼��ÿ���ߵĳ��ȣ�Ӧ������̱ߵĳ��ȣ�����Ժ�����Ծ��������������׵õ�
// ��һ����Ծ���������̱ߵĺ��Ӽ������ĺ��Ӷ��ǿ����������С�����������ɸ�������ʳ�ģ�������... 
// Ȼ�������Ӷȱ�ֱ��ö�ٻ�Ҫ�ߣ����������д�˸�O(n)�ĶԱ�.. 

// �����̣���û����Ŀ������������������ʳ����������һ������һ��������ʳ���У�������Ȼ��0����ʱ�����
// ϸ�Ŀ��⣨����������Ȼ������ĶԱȹ���ͱ����>=
// �������ö��ȫRE��.... 

// ��50w�ռ���ȥ�ˣ��������㵽��Ҫ����������...֮ǰ��5w׹���ˣ��ⶫ��̫��ѧ��... 

const int N = 100000 * 5 + 1000, M = 510 * 10;
int monkeys[M];
struct POS {
	int x, y;
} p[N];
struct GRAPH {
	int u, v;
	double w;
	GRAPH(int u, int v, double w) : u(u), v(v), w(w) {};
	GRAPH() {};
	bool operator<(const GRAPH& g) {
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
// ֮ǰ����һ����Ҳ��������룬���յ�ǿת��double����Ȼ���ܻ��о������� 
double getDist(int x1, int y1, int x2, int y2) {return (double)sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));}
unionFind u;
int main() {
	int n, m, cnt = 0;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &monkeys[i]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	// ������������±��һ��Ҫע��.. 
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) 
			g[cnt++] = GRAPH(i, j, getDist(p[i].x, p[i].y, p[j].x, p[j].y));
	sort(g, g + cnt);
	double maxDist = -1.0;
	// ��������������ߵ�ֵ�� 
	for (int i = 0; i < cnt; i++) 
		if (!u.ask(g[i].u, g[i].v)) 
			maxDist = max(maxDist, g[i].w), u.uni(g[i].u, g[i].v); 
	int res = 0;
	//printf("%.2lf", maxDist);
	// �Ա�ÿ�����ӵ���Ծ�����Ƿ���ڵ������ 
	for (int i = 1; i <= m; i++) 
		if (monkeys[i] >= maxDist) res++;
	printf("%d", res);
	return 0;
}
