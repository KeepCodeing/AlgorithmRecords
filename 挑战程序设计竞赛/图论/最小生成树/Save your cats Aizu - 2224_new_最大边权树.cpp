#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// �������ƽ�ȥ��ɳ�����w����������С������ר����Ҳ��ȫû�����뵽��������С��������ʲô��ϵ...
// ������ģ�Ϳ��Եõ���ôЩ��Ϣ���µ�ͼ��û�л���Ҫʹ��ʣ�����ı߱�Ȩ����С��˵���˾���Ҫ�����
// ͼ������Ȩ������Ϊ��ȥ�ıߵ�Ȩֵ��Խ��ʣ������ͼ�ıߵ�Ȩֵ�;�ԽС����һֱ������һ����ͨ��
// ȥ����С�ߣ���ʵ�ϻ�ͼҲȷʵ���...�������Ƶ���Ҳ�������Ǹ���������Ҫ����Ƿ��ŵģ��Ǹ���Ҫʹ��
// ȥ���ıߵĺ������Ҳ�����������ıߵĺ���С��ע������������������Ǹ���Ҫ�����ȥ��������Ȩ��
// �������Ҫ�����ȥ���ı�Ȩ����С��Ҳ���Ƿ�������..
// ��ô����С���������ⲻֹһ�������ˣ���������С���������ⶼ��ʹ�ñ�Ȩ����С�����������ȻҲ��Ҫ���Ȩ��
// ��С����ȴ�������������ı�Ȩ�ͣ�׼ȷ��˵��ȥ��������Ҫ��֤ȥ���ı߱�Ȩ���.. 

// �ܽ᣺��С���������ͻ���û��ĺ�͸�������ұ���������..���ڽӴ�������С��������Ŀ�����У����⣬������
// ��̱�Ȩ�ͣ������⣬Ҫʹ�ñ�ȥ���ıߺ���������Ҫʹ�ñ�ȥ���ıߺ���С��Ȼ����������Ļ�����Ҫ��ӱ�
// ���ȵ��⣬�����ĺ����Ǹ������Ȱѱ��������Ȼ������С��������ߣ����Ա��ж���ֵ���ڵ������.. 

// M��ÿ����... 
const int N = 10000 + 10, M = N * 5;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	// �����Ȼд����int... 
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) const {
		return w > g.w;
	}
} graph[M];
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
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
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	int cnt = 0, ut, vt;
	double temp, sum = 0, tot = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ut, &vt);
		temp = cpl(pos[ut].x, pos[ut].y, pos[vt].x, pos[vt].y);
		// ͳ������ͼ�ı�Ȩ��... 
		sum += temp;
		graph[cnt++] = G(ut, vt, temp);
	}
	sort(graph, graph + cnt);
	// ������Ȩ�� 
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			tot += graph[i].w; 
		}
	}
	// ���Ҫ�����̱ߵĺ;��������ĺͼ�ȥ������������ߵĺ�... 
	printf("%.3lf", sum - tot);
	return 0;
}
