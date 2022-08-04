#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// ��С����������ΪҪ�󻨷����٣����ǽ������Ƶ�һ���߿�������С��������ı�
// ��ĿҪ��ֻ��k���ƶ䣬����˵ֻ������С����������k���ߣ���ô���ߵ�ʱ������
// �ж��¾�����

// �ܽ᣺��������ģ������Ը��������ߵĹ��̣�Ҳ���Ƕ���ģ������Ի������仯w
// ���ǲ�֪��Ϊʲô�������ռ�-... 
 
const int N = 1000 * 10 + 10, M = 10000 * 5 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 10];
		for (int i = 0; i < n + 10; i ++) bin[i] = i;
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
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	// ע���������n���㣬������n���㲻һ�����бߣ����Բ��鼯��ʼ����ʱ��Ҫ������ 
	unionFind u(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	}
	sort(graph, graph + m);
	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			ans += graph[i].w;
			cnt++;
		}
		// Ҫ��k���޻��ǣ�Ҳ���Ǵ���n-k���߾��У����ƺ���ͼ�۵Ļ������ݣ�����
		// ���ݽṹ���������Բ�̫�ǵ���w 
		if (cnt == n - k) {
			printf("%d", ans);
			return 0;
		}
	}
	printf("No Answer");
	return 0;
}
