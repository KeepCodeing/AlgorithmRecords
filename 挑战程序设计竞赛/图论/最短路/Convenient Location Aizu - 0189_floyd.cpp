#include <iostream>
#include <cstdio>
using namespace std;

// floydģ���⣬��Ϊ���ݺ�С��������ĿҪ����Ǵ��ĸ��㵽����������·֮����С������
// ����ֱ����floyd���ȫԴ���·��Ȼ��ö���ĸ�������·֮����С����... 

const int N = 15, INF = 0x3fffffff;
int graph[N][N];
// ��ʼ���ڽӾ��������û���ж��ٸ��㣬����ֻ��һ���԰�����ͼ��ʼ��.. 
void init_graph() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
}
int main() {
	int n;
	int ut, vt, wt;
	while (true) {
		// ����n�Ǳ������������ʮ��... 
		scanf("%d", &n);
		if (!n) break;
		init_graph();
		// �����ڽӾ���ͼ��ע����˫��� 
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &ut, &vt, &wt);
			// ��֪���治�����رߣ�Ϊ�˱��ջ����ж��º���.. 
			graph[ut][vt] = min(graph[ut][vt], wt);
			graph[vt][ut] = min(graph[vt][ut], wt);
		}
		// floyd���ӣ�i���м�㣬j�ǵ�ǰ�㣬k��j��һ�����ϵĵ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		} 
		int idx, mPath = INF, totPath;
		bool flag;
		for (int i = 0; i < N; i++) {
			totPath = 0, flag = false;
			for (int j = 0; j < N; j++) {
				// �����· 
				// û��ͨ·�����Լ����Լ�����������Ϊ�����е�·��������û�е㣬���Ե�����ж� 
				if (graph[i][j] == INF || i == j) continue; 
				// ��Ϊ����ֱ�Ӽ���������ͼ�����·�������������û����ô��㣬����������ж��µ�ǰ·���Ƿ���Ч 
				flag = true; 
				// ����i������ܵ������е�ı�Ȩ֮�� 
				totPath += graph[i][j]; 
			}
			// ���½������ĿҪ���¼���ȳ��ֵ����· 
			if (mPath > totPath && flag) idx = i, mPath = totPath;
		}
		printf("%d %d\n", idx, mPath);
	}
	return 0;
}
