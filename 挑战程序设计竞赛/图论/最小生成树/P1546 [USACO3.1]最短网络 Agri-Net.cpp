#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������⣬�����������ڽӾ���������prim���ȽϺ���... 
// ������������ûʲô˼��������w 

// ̫�����ˣ������������Ҳ���˺ܳ�ʱ�䣬��Ҫ��û����Ŀ��POJ�Ĳ������ݺ�ǿ���кܶ��飬Ȼ���һֱ����������...
// ���о��ǻ���..��������˵ûʲô����w������POJ����û�����������ô����.. 

// ��ȿռ俪С��RE�����Σ���ʵ�������������5k���㣬��Ϊsum(1~100)... 
const int N = 5000;
struct g {
	int u, v, w;
	bool operator<(const g& gg) const {
		return w < gg.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	void initBin () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, w, cnt;
	// POJ�ϵ������кܶ��飬�����ֻ��һ��... 
	while (~scanf("%d", &n)) {
		u.initBin();
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &w);
				// ���ߵ��＼�������¾����Բ��ܺ��Լ�����Ȼ������˫��ߣ�����
				// ֻ����һ�룬�����Լ�֮��ı�... 
				if (j > i) {
					graph[cnt].u = i, graph[cnt].v = j, graph[cnt].w = w;
					cnt++;
				}
			}
		}
		// �����������ͼ��ķ�ʽ����... 
		sort(graph, graph + cnt);
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v); 
				res += graph[i].w;
			}
		}
		// ע��������ݻ���.. 
		printf("%d\n", res);
	}
	return 0;
}
