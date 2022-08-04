#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// ��Ŀ���������ɸ�����ڿ�ѡ�ɲ�ѡ�������һ�����С����������ֻҪ��ȫ��ͨ���޻�����Ȩ��С�� 
// ��ô���ǿ����£��еĵ����ѡ���Ǹɴ���Ȱ����ֱ���������������Щ����ɵ���ͼ�Ƿ�ɻ�����
// һ���������ɸ����ڽڵ㡣�������������˼�룬����Щ��ͨ�鿴��һ���㣬Ҳ�������ǵ����ڽڵ㣬 
// Ȼ��ԷǱ�ѡ�㰴��Ȩ���������ߵĹ������ж��µ�ǰ�Ǳ�ѡ�����ڵ���ͨ������ڵ��Ƿ���Ҫ����
// �ĵ�����ڵ���ͨ�������ͨ�����ӱߣ�����ǰ�ӵı�һ���������ʹ��������ͨ����ͨ��������
// ����������ʵ�ǿ����л��ģ������������ͨ�鿴��һ�����Ǿ����޻��ģ� 

// �ܽ��������������ͨ����ͨ����Ŀ������һ���޸ģ�����Ҫ����ѡ����ɵ���ͨ�鿴��һ���㣬Ȼ��
// �÷Ǳ�ѡ�㽫��Щ��ͨ�����ߡ��������ͨ����Ծ���������Ĺ����оͽ���ѡ����������Ȼ�󽫷Ǳ�ѡ
// �������������Ĳ����ͺ���ͨ��һ���ˡ�������������������� 

const int N = 2000 * 10 + 10;
struct G {
	int ut, vt, wt;
	bool operator< (const G& g) {
		return wt < g.wt;
	}
	G (int ut, int vt, int wt) : ut(ut), vt(vt), wt(wt) {};
	G () {};
} graph[N];
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
	// ���ѭ����register���Լӿ��ٶȣ��������ѭ������register����2s������ֻ����0.5s 
	// for (register int i = 0; i < 999999999; ++i);
	int n, m, ut, vt, wt, p, cnt = 0, res = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &p, &ut, &vt, &wt);
		// ��ѡֱ��������ͳ�Ʊ�Ȩ�ͣ��Ǳ�ѡ���ȴ��ţ������ٽ������� 
		if (p == 1) res += wt, u.uni(ut, vt);
		else graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	// �����װ��ӣ��Էǿ�ѡ�߽������ߣ�ֱ�����е���ͨ 
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].ut, graph[i].vt)) {
			u.uni(graph[i].ut, graph[i].vt);
			res += graph[i].wt; 
		}
	}
	printf("%d", res);
	return 0;
}

/*
5 6
1 1 2 1
1 2 3 1
1 3 4 1
1 4 1 1
2 2 5 10
2 2 5 5

9
*/
