#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ����һ������ͬ�����ͣ�Ҳ������Kruskal�⣬��������������Ӧ�������·�����Сֵ��˼·���Ǹ�����״̬�ķ�ʽ��
// �����һ���ο�����... 
// ���������������ƺ��������������...��֮���Ǳ�Ȩ�����w����ô��������ߵ���Ӧ�ö����������������������... 
// ������������һ���⣬����ս�����·�Ҫ�����·����С��Ȩ�ͣ��Ǹ������ж����·���¼�±�Ȩ�����ˣ���Ȼ
// ��Ҳ��������С���������ˣ�����׹���ˡ���ʱ����ܽ�������Ե��˳����Ҫ�󣨼��ڲ��ı�ԭͼ��ǰ���������·��
// ��ôһ��Ͳ�������С�������������������֤����һ�㣬����ⲻ�������·��ֻ������ߣ���ô�ɴ��ع�ͼȻ����
// Kruskal������... 

// û�����������Կ���w 
const int N = 1000 + 10, M = 1e6 * 5;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		// ע����������������������Ա�ȨӦ�ôӴ�С�����д����С���������֣���Ҫ�����ߵĹ�����ͳ����ߣ�
		// ���������ֱ�ӽ�������Ͳ���ͳ������ˣ���һ���ɻ��ı�һ�������.. 
		return w > g.w;
	}
} graph[M];
struct unionFind {
	int bin[N];
	void _init() {
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
unionFind u;
int main() {
	int T, n, m;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		u._init();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
		sort(graph, graph + m);
		for (int i = 0; i < m; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v);
				if (u.ask(1, n)) {
					printf("Scenario #%d:\n", t);
					printf("%d\n\n", graph[i].w);
					break;
				}
			}
		}
	}
	return 0;
}
/*
1
3 3
1 2 3
1 3 4
2 3 3
*/

//�ο����룬��Ҫ��Dijkstra��ʼ�������Ȩ�����ı�.. 
//#include <cstdio>
//#include <queue>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1005, M = 200005, INF = 0x3f3f3f3f;
//int t, n, m, u, v, w, len, h[N], d[N];//d[i]����1��i��·���е���Сֵ�е����һ�� 
//bool vis[N];
//struct E {
//	int v, w, next;
//} e[M];
//struct Node {
//	int v, d;
//	Node(int d, int v): d(d), v(v){}
//	bool operator < (const Node&w) const {
//		return d < w.d;//d���Ӧ���ȳ��� 
//	}
//};
//void add(int u, int v, int w) {
//	e[len].v = v;
//	e[len].next = h[u];
//	e[len].w = w;
//	h[u] = len++;
//}
//void djkstra() {
//	memset(vis, false, sizeof(vis));
//	memset(d, 0, sizeof(d));
//	d[1] = INF; //��һ����Ӧ��������� 
//	priority_queue<Node> q;
//	q.push(Node(0, 1)); 
//	while (!q.empty()) {
//		int u = q.top().v;
//		q.pop();
//		if (vis[u]) continue;
//		vis[u] = true;
//		for (int j = h[u]; j; j = e[j].next) {
//			int v = e[j].v;
//			int w = min(d[u], e[j].w); //�������� ��֮ǰ����Сֵ˭С
//			if (d[v] < w) {
//				d[v] = w;
//				q.push(Node(d[v], v)); 
//			} 
//		} 
//	}
//}
//int main() {
//	scanf("%d", &t);
//	for (int cas = 1; cas <= t; cas++) {
//		memset(h, 0, sizeof(h)), len = 1;
//		scanf("%d%d", &n, &m);
//		for (int i = 1; i <= m; i++) {
//			scanf("%d%d%d", &u, &v, &w);
//			add(u, v, w); add(v, u, w);
//		} 
//		djkstra();
//		printf("Scenario #%d:\n%d\n\n", cas, d[n]);
//	} 
//	return 0;
//} 

