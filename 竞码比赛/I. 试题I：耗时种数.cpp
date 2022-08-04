#include <iostream>
#include <set>
using namespace std;

// �������⣬��������ǰ��δ������ 

const int N = 1500, INF = 0x3fffffff;
int graph[N][N];
set<int > res;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	int u, v, w;
	while (q--) {
		cin >> u >> v >> w;
		// ���ȣ�u��v���Ǵ�0��ʼ�ģ��������õĶ������Ǵ�1��ʼ�� 
		u++, v++;
		// ��Σ����������رߣ����Բ���ÿ�ζ����Ȩʱ�����Ը��£�
		// �����ж����µı�Ȩ�Ƿ��С 
		graph[u][v] = min(graph[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (graph[i][j] != INF) res.insert(graph[i][j]); 
			}
		}
	}
	cout << res.size();
	return 0;
}
