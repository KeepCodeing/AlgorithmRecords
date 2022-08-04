#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// Kruskal�㷨˼��ǳ��򵥣���̰�ĵľ���Ӧ�á�Ϊ�˱�֤�������ı�Ȩ����С��������ÿ����ӵ�����Ľڵ�ı�Ȩ��С���ɣ�Ҳ
// ���Ƕ���������ݽ���һ������Ȼ���С������Ӷ�����С���Ȼ��Ϊ�˱�֤һ������ֻ�����һ�Σ������ò��鼯ά����������
// �������鼯�ṩ�ϲ����������ڲ���ͨ���������㣬ͳ��Ȩֵ�������������е㶼��ͨ����˵����������С������������ӵ��
// ���������������ĸ����� 

// ���˴��w�������������±�������Χ�������õ��±��Ǵ�1��ʼ�����������ʱ���0��ʼ�ˣ�����Ϊ�˷���ɴ�ʹ�0��ʼ
// Ȼ���ǲ��鼯w���о����Ӧ�õģ����Ӷ�д���ˣ����ܣ�
// ����ǲ��鼯�ṹ���ʼ��������Ϊ���ټ���ѭ��ѡ����������ݷ�Χ���ʼ��bin���飬Ȼ�����������ƺ�ÿ�β�ѯ���ǵõ�
// u�����ں�v��������ͬ��Ȼ���ֲ��鼯���ṹ�����ڶ�������ǰ�ͽ����˳�ʼ��w����Ҳ����ζ��n��ֵ��ȷ������Ȼ��ʼ���ͳ�
// ������w 

// ������С��������ͼ�󲿷ֶ�������ͼ������ͨ����һ���������· 

// �����¸�����С���������⣬�󲿷ֶ���Ҫȥ��һЩ��������Ӧ��ͼ����Ǳߣ�������С���������ľ���ÿ�ζ���ǰn-1С�ı���
// ���� 

const int N = 1e5 * 2 + 10;
int n, m;
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i <= n; i++) bin[i] = i;
	};
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
struct Graph {
	int u, v, w;
	bool operator<(const Graph g) const {
		return w < g.w;
	}
} G[N];

int main() {
	scanf("%d%d", &n, &m);
	unionFind u;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
	}
	sort(G, G + m);
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(G[i].u, G[i].v)) {
			res += G[i].w;cnt++;u.uni(G[i].u, G[i].v); 
		}	
	}
	if (cnt < n - 1) printf("Impossible!\n");
	else printf("%d\n", res);
	return 0;
}
