#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
����
��������Ҳ���������ġ�����һ����n���ڵ���޸������ҵ�һ���㣬ʹ�ð�������Ըõ�Ϊ�����и���ʱ����������Ľ�
������С�����仰˵��ɾ�������������ͨ�飨һ���������Ľ������С��

����
1.�������е㵽ĳ����ľ�����У������ĵľ��������С�ģ�ʵ��Ӧ���о����õ������ʣ���
2.��������ͨ��һ�����������µ�����������ԭ�����������ĵ������ϡ�
3.һ������ӻ���ɾ��һ���ڵ㣬�����������ֻ�ƶ�һ���ߵ�λ�á�
4.һ����������������ģ������ڡ�
*/

const int N = 50000 + 10, M = N * 2, INF = 0x3fffffff;
int head[N], e[M], ex[M], idx = 0;
bool vis[N];
int sz[N];
// ���ĵı�ţ�������������� 
int ans = 0, maxn = INF;
int n, ut, vt;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int ut, int nx) {
	sz[ut] = 1;
	// ��������Ľڵ��� 
	int mx = 0;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vt == nx) continue;
		dfs(vt, ut);
		sz[ut] += sz[vt];
		mx = max(mx, sz[vt]);
	}
	mx = max(mx, n - sz[ut]);
//	if (mx < maxn) {
//		maxn = mx;
//		ans = ut;
//	}
	// ������֤�ֵ�����С 
	if (mx < maxn || (mx == maxn && ut < ans)) {
		maxn = mx;
		ans = ut;
	}
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	dfs(1, 0);
	cout << ans;
	return 0;
}
