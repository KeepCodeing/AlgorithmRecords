#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// ���ڰ��ߴ���ϰ����w��������һ�������壬�м��������ǵ繤..��һ��������£��о���̫����w���Ͼ�����������w
// �����˼·�Ƚ�ģ����������Ȼ�������껹�о��룬��ô��ž����Ȱ�������֮��ľ����������Ȼ�������D������
// ������֮��ľ��룬����Ҫ��D��ͳһ�ģ�Ҳ����˵�м�����Ҫ��D�ͳ��϶��ٱ���Ȼ���и����ǣ����Կ�����������
// �ĵ㲻�����ʽ�...�����ȻҪ�����е㶼����������ô��ʵ���Ǳ�֤�����̣��������ǲ��û�ǮӦ�þ�����ζ��
// �����ټ����ߵ�Ǯ����������ǵĸ���Ϊn����ô�Ϳ���ʡȥn-1���ߵ�Ǯ���ȼٶ�����ʡȥ�ıߵ�Ǯ�������...

// ����С�����ǵģ����Ȼ����װ��ӣ��������ÿ����ľ��룬Ȼ�����ߣ�����ע����������߲��Ƕ�����Ҳ��������
// �����������Ǹ�ɭ�֡�������������һ����ͨ��С�������ж��ٸ��ߣ������p���㣬�Ǿ���p-1���ߣ��������������
// ν�����ǣ������s�����ǣ��Ǿ���˵��s���㲻�ý������ߣ�Ҳ����������������s-1���ߣ�������ǰ���Kruskal�㷨
// ��˼·���Ļ���������Ȩ�ٵı߾�����Ȩ�ٵıߣ����Ǻ�����������p-1-(s-1)���߾����ˣ�Ҳ����ֻ����p-s���߾����� 
 
const int N = 500 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[M];
struct unionFind {
	int bin[M];
	unionFind() {
		for (int i = 0; i < M; i++) bin[i] = i;
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
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
int main() {
	int T, s, p, cnt;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &s, &p);
		// ϲ���ּ����±�ӣ�����ÿ�õ�һ���ͻ�˵�£��ɼ������ĺ����Ǹ��������ɵ���Ӱw 
		for (int i = 1; i <= p; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		cnt = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = i + 1; j <= p; j++) {
				graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		}
		double maxDist = .0;
		int bcnt = 0;
		unionFind uf;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				bcnt++;
				maxDist = max(maxDist, graph[i].w);
				if (bcnt == p - s) break;
			}
			// printf("%d %d %.2lf\n", graph[i].u, graph[i].v, graph[i].w);
		}
		printf("%.2lf\n", maxDist);
	}
	return 0;
}
