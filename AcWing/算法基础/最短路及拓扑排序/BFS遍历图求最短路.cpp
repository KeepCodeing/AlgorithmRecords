#include <iostream>
#include <cstdio>
using namespace std;

// ��Ȩȫ��ȵ�ͼ������BFS�����·��������Ҫ������BFS������ͼ����Ϊ֮ǰ��û������Բ���w 

// ����ͼ 
const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
// ���������پ�������������ƣ���dist��ʾ����ͷ��ʷ񣬵�ǰ��չ��
// ��ľ���͵�����һ����ľ�����ϱ�Ȩ 
int dist[N];
int que[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int bfs(int st, int n) {
	fill(dist, dist + N, -1);
	int qtop = 0, qback = 0;
	que[qtop] = st;
	dist[st] = 0;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// ע����������·����Ĳ�֮ͬ�������·���ⲻ�ܸ���dist���ж�һ�����Ƿ񱻱���������Ϊһ����ı߿���
			// ������ɳڡ������ﵱǰ��ľ���ֻ�ܴ���һ������չ�����������ж��Ƿ���ʵ÷�ֹѭ�����棬�����������ͨ
			// �Թ�����Ҳ�����͵�.... 
			if (dist[vt] != -1) continue;
			dist[vt] = dist[ut] + 1;
			que[++qback] = vt;
		}
	}
	return dist[n];
}
int main() {
	int n, m, ut, vt;
	fill(head, head + N, -1);
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt);
	}
	printf("%d", bfs(1, n));
	return 0;
}
/*
4 5
1 2
2 3
3 4
1 3
1 4

1
*/
