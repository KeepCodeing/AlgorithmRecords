#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// ��Ȼ��Ȩ�ߵ��⼸��û��ô����Ҳû��ô������������ˢ���·ר���ʱ��о������б�Ҫ�ģ���ô���ǵ��жϸ������㷨
// ֻ��SPFA��Bellman����SPAF����������Dijkstra�������������SPFA������������ˣ�������˵SPFA�ᱻ����ָ�ľ�����
// ʱ�临�Ӷ������O(nm)������Bellman�㷨�ĸ��ӶȾ���O(nm)���Կ��ܾ��㱻��Ҳֻ�Ǻ�Bellman�㷨һ������w... 

// SPFA���㷨˼����Ƕ�һ������ж���ɳڣ�������һ��ѭ�����к�һ��������������в����ɳڣ����й��̴�����Ƚ���ͷ
// ��Ԫ�س��ӣ�Ȼ����Ϊδ���ʣ�����ͽ�������Dijkstra����ɳڹ��̣���ö�����бߣ�Ȼ���ж�����ߵľ��뵽���������
// �ľ����Ƿ���Ը��̣�������̣�������Ϊtrue��Ȼ����ӡ����Կ�����SPFA�������α�ǺͶ������⣬������Dijkstraû
// ��̫�������������Ҫ�������α�ǣ����ȣ������ڶ��α�ǣ�����SPFAֱ�Ӷ���ӵĵ���Ϊtrue�ˣ������ζ���������
// һ���ɳڹ����в��ᱻ�ظ�ʹ�ã�ע����һ���ɳڹ��̡�Ȼ���ǵڶ�����ǣ���������Ϊ�˱�֤һ��������ӣ������ǰ���
// ��ıߵľ����Ѿ��ɳ�����ˣ���ô���������������ӵ��Ǹ���Ͳ����ٴ���ӣ������ᱻ���Ϊfalse...�о���ȫ��Ϲ������Ȼ
// �����ϴ������w... 

// ����ͼ 
const int N = 1e5 + 10;
int head[N], e[N], ex[N], w[N], idx = 0;
int dist[N];
bool visited[N];
queue<int > que;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int spfa(int st, int n) {
	memset(dist, 0x3f, sizeof dist);
	// visited[st] = 1;
	dist[st] = 0;
	// ע��SPFA��ӵĲ���pair����Ϊ��������Dijkstra�������ݱ�Ȩ����... 
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// �ɳڲ�������Ϊ���ð���Ȩ��������ֱ����ԭ����ȡֵ���� 
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				// ��ֹ�ظ�����... 
				if (!visited[vt]) {
					visited[vt] = 1;
					que.push(vt); 
				}
			}
		}
	} 
	return dist[n];
}
int main() {
	memset(head, -1, sizeof head);
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	int res = spfa(1, n);
	// ������ڸ�Ȩ�ߣ��򲻴������· 
	if (res == 0x3f3f3f3f) printf("impossible");
	else printf("%d", res);
	puts("");
	return 0;
}
