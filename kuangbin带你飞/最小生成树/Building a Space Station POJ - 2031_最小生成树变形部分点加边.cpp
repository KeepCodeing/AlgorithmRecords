#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// �����Ӧ���Ǹ���С�����������⣬��Ϊ�������ֵ㲻�üӱߡ�����Ŀ������������ཻ/���е����岻��Ҫ����ħ��
// ��������������ô�ּ���������ۣ����е㶼����ӻ������еģ����ǾͲ���Ҫ��Ǯ�����ֵ����ཻ���еģ���ô��Щ
// ��Ͳ��û�Ǯ��������ΪҪ�����е��������������Ի�Ҫ�㲻�û�Ǯ�ĵ㵽Ҫ��Ǯ�ĵ����С���룬��ö�����в���Ǯ��
// �㣬Ȼ������Щ���ÿ��Ҫ��Ǯ�ĵ�ӱߣ���Ȩ���Ǿ���������С���������...
// ����������ķ����ƺ����鷳�������ж��Ƿ��ཻ�����Ǽӱߵ�..�����뵽��һ�����ܸ����ķ�ʽ��������Ϊÿ���㶼��
// ���ൽ���˲�����ÿ���㶼����һ�����������е�ıߣ���Ȩ��Ϊ������ľ��룬Ȼ����������С���������ڽ����ع�
// ���Ĺ������жϵ�ǰ�������Ƿ��ཻ�������У�����ཻ�����У��򻨷Ѽ�Ϊ0�����򻨷Ѿ������ǵľ���...�������ǿ���
// �ģ�˼·�����˴����ĺ��Ӻ�һ��Ҫ���Ȩ����D���⡣
// Ȼ�����䲻��֪����ô�������Ƿ��ཻ��������w��ְ������ĩ·ôw..���˱��˵Ĳ��ͣ��������ཻ���к���Բ�ཻ����
// �ƺ���һ���ģ�ֻ�����������������꣬Բ���������ꡣ���㷽������sqrt((x1 - x2) * (x1 - x2)...) - r1 + r1����˼
// ���������������������ľ��룬Ȼ���ȥ���ǵİ뾶�ͣ�����뾶��С�ڵ���0����˵�����ཻ�������еģ��෴���Ǿ���
// ����ģ���ô����ӵı�ȨӦ�þ��Ǿ��� - �뾶�ͣ�Ϊʲô�������أ���Ϊ���ǿ�����Ϊ�����������岻�Ǵ����Ŀ�ʼ�ģ�
// ���Ǵ����濪ʼ��...������Բ�ľ����Բ�ľ����ƺ���������w��һֱ��֪��w... 

const int N = 100 + 10, M = 1e5 * 5 + 50;
struct Ball {
	double x, y, z, r;
} ball[N];
struct G {
	int ut, vt;
	double wt;
	G () {};
	G (int ut, int vt, double wt) : ut(ut), vt(vt), wt(wt) {};
	bool operator<(const G& g) const {
		return wt < g.wt;
	}
} graph[M];
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
	int n, cnt;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%lf%lf%lf%lf", &ball[i].x, &ball[i].y, &ball[i].z, &ball[i].r);
		// ���±�ӹ�w 
		double tx, ty, tz, tr, dist;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				tx = ball[i].x - ball[j].x, ty = ball[i].y - ball[j].y, tz = ball[i].z - ball[j].z, tr = ball[i].r + ball[j].r;
				// ����Բ�ľ��� 
				dist = sqrt(tx * tx + ty * ty + tz * tz);
				// �������Բ������ģ���Ȩ���Ǿ����ȥ�뾶�� 
				if (dist > tr) graph[cnt++] = G(i, j, dist - tr);
				// ����ཻ�������У�ֱ�Ӵ����ȨΪ0�����ˣ����������������жϱȽ��鷳... 
				else graph[cnt++] = G(i, j, .0); 
			}
		}
		unionFind uf;
		double res = .0;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				uf.uni(graph[i].ut, graph[i].vt);
				res += graph[i].wt; 
			}
		}
		// ע����������ѡC++��G++��֧��%lf... 
		printf("%.3lf\n", res);
	}
	return 0;
}
