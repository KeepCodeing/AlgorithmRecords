#include <iostream>
using namespace std;

// n�ķ�Χ��С������Floyd��ȫԴ���·����������Ҫ��ܶ�����· 
// ���ÿ�ζ�����һ�����ƻ�ը 

// floyd��Ϊ̫�����Ի��ῼ���� 

const int INF = 0x3FFFFFFF;
int n, m, t;
int graph[310][310];
int main() {
	cin >> n >> m >> t;
	// ��ʼ���ڽӾ����ڽӱ��ã���Ϊ������װȥ���˵ĵ� 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = INF;
			else graph[i][j] = 0;
		}
	}
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		// ��Ŀϸ��˵������ͼ
		graph[u][v] = w;
		// graph[v][u] = w;
	} 
	// Floyd
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// ���÷������½�����״̬ת��ʱ����Ϊ����i��Ϊ�м�㣬����ţ�������߸߶���
				//max(d[i][j],d[j][k])��������j->k������·���ϣ��������߸߶�Ӧ����С������
				// ���Ҫȡһ��MIN����graph[j][k] = min(max(graph[j][i], graph[i][k]), graph[j][k]);
				graph[j][k] = min(max(graph[j][i], graph[i][k]), graph[j][k]);
			}
		}
	}
	int x, y;
	while(t--) {
		cin >> x >> y;
		cout << (graph[x][y] != INF ? graph[x][y] : -1) << endl;
	}
	return 0;
}
