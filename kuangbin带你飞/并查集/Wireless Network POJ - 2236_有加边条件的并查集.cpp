#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// ���·����ʮ��������w�������Բ��鼯�������ʮ��ǰ�����������˺ܲ��õ�ӡ��ww�����Լ�����ʱ����ֱ�Ӱ�����������
// ���������Ȼ���޸�ʱֱ���������ˣ����ǿ����˴��������ÿ�ζ��ж�...��������ú�����w 

// ����ⲻ�����ӻ�û�޺õĵ��ԣ���֮ǰд���ƺ�û�п��ǣ�����д�����Ҳû�п���ww... 

// TLEw�����˱��˵Ĵ����AC��..�������Ƚṹ���... 

const int N = 1001 + 10;
struct Pos {
	int x, y;
} pos[N];
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
		int xt = anc(x), yt = anc(y);
		if (xt != yt) bin[xt] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
bool cpl(int x1, int y1, int x2, int y2, double d) {
	// printf("%.3lf\n", sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2)));
	return (x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2) <= d * d;
}
unionFind uf;
bool vis[N];
int fix[N];
int main() {
	int n, u, v, cnt = 1;
	double d;
	scanf("%d%lf", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	char op[5];
	while (~scanf("%s", &op)) {
		if (*op == 'O') {
			cin >> u;
			// ����Ѿ��޺õĵ��� 
			if (vis[u]) continue;
			vis[u] = true;
			// ���Ѿ��޺õĵ��Դ���������Ȼÿ���޶�ȥö�ٻ�TLE 
			fix[cnt++] = u;
			for (int i = 1; i < cnt; i++) 
				// ����ڷ�Χ�ھͽ��кϲ� 
				if (fix[i] != u && cpl(pos[u].x, pos[u].y, pos[fix[i]].x, pos[fix[i]].y, d)) uf.uni(u, fix[i]);
		} else {
			cin >> u >> v;
			printf("%s\n", uf.ask(u, v) ? "SUCCESS" : "FAIL");
		}
	}
	return 0;
}
