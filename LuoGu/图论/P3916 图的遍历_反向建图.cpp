#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// �Լ���Ȼ����̫naivew���������ǰ����ȵĽ̳�ʱ�����ˣ�������ʱ��û����д���⣬��д�˸�����...
// �����Ƿ���ͼ��Ȼ��ӱ�Ŵ�ĵ㿪ʼDFS�����е�ǰ����ܵ��ĵ㣬Ҳ�����ܵ���ǰ��ĵ�...˵�������·�ﷴ��ͼ�ܶ���㵥�յ���⵹��ͦ�࣬
// ���������ȴ�벻����..��Ȼû��ģ�������Խ������... 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
int dist[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int ut, int pos) {
	// ע�⵱ut == posʱ�������������������ܵ�������������Լ������յݼ�˳�������������ֱ������д��
	// �����Ǹ���ֵ�Ϳ���ֱ��ȥ����... 
	dist[ut] = pos;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		// �ö����ű�ʾ���ʷ� 
		if (dist[vt] != -1) continue;
//		dist[vt] = pos;
		dfs(vt, pos);
	}
}
int main() {
	memset(head, -1, sizeof head);
	memset(dist, -1, sizeof dist);
	int n, m, ut, vt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		// ����߷���ͼ 
		add(vt, ut);
	}
	for (int i = n; i >= 1; i--) {
		if (dist[i] != -1) continue;
		dfs(i, i);
	}
	for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
	return 0;
}
