#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// ��ϰ��ڶ���������ʱģ�⿼����..�������Ŀӵ�ĳ�����±��������...
// �������±꣬��������Ȩʱ�±�һ��Ҫ��1��ʼ���������ֺ���ֵĴ���...Ȼ�������⣬��Ŀ�ʵ�����������
// ������ʳ�ĺ��ӵ���������������������������ʳ�ĺ��ӵ�����...

// ��ô��Ϊ������������Ծ�ֱ��˵˼·�ˣ���ÿ������Ϊһ�����㣬��������������е�ľ�����Ǳ�Ȩ������Ҫʹ��һֻ����
// ���������������ʳ����ʵ����ʹ��������֮��ľ��루��Ȩ�����ֵ��С������ҲҪ��ÿ��������ͨ�ģ���Ϊһֻ����ֻ�ܴ�
// һ��������һ����..����ô˼·���ǽ�ͼ������С����������¼��ߵ�ֵ������ж����ж��ٸ����ӵ���Ծ�������ڵ������ֵ
// ����... 

// ����������صĴ��󣬵�����һ����������WA���Σ����ܺ�״̬�е��ϵ����ȫû�뵽������... 

const int M = 500 * 10 + 10, N = 100000 * 5 + 1000;
int monkeys[M]; 
struct pos {
	int x, y;
} ps[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
double gd(int x1, int y1, int x2, int y2) {
	return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
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
	int m, n, cnt = 0;
	scanf("%d", &m);
	// �±�ûͳһ����������ѭ����1��ʼ����ô����ļ���ѭ�����Ҳ��1��ʼ��ΨһҪע�����ʵ��graph�������
	// ��Ϊ��Ҫ������������±��1��ʼ�������������... 
	for (int i = 1; i <= m; i++) scanf("%d", &monkeys[i]);
	scanf("%d", &n);
	// �����׵Ĵ��������Ȼֻд��һ��%d�����һ��ܹ�������... 
	for (int i = 1; i <= n; i++) scanf("%d%d", &ps[i].x, &ps[i].y);
	// �ӵ㣺�����±�һ��Ҫ��1��ʼ...
	// ���㵱ǰ�㵽����ı�Ȩ 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// ��������������ѭ��Ҫע���±꣬�����ط�������ν��ֻҪͳһ����... 
			graph[cnt++] = G(i, j, gd(ps[i].x, ps[i].y, ps[j].x, ps[j].y));
		}
	}
	double lst = 0;
	// ��С������������... 
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		// ����+ͳ�����... 
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			lst = max(lst, graph[i].w); 
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) res += ((double)monkeys[i] >= lst);
	printf("%d", res);
	return 0;
}
