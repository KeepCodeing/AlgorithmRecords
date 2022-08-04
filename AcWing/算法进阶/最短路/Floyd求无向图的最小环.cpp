#include <iostream>
#define endl '\n'
using namespace std;

// ��ν��С������i�����پ���һ���㲢�ص��������·���ľ�����̣���������ͼֻ�ÿ���iֱ��
// �����ĵ�k��j�ľ��룬��Ϊ�жԳ�������ֻ��ö��i ~ k, i + 1 ~ k�ıߣ��˴�����ö�ٵ�k��  

// ע������INF�ĸ�ֵ���������ٻ���������������Բ�������ͨ��0x3f 
const int N = 1e2 + 10, INF = 99999999;
int graph[N][N], dist[N][N];
int main() {
	int n, m, ut, vt, wt, ans = INF;
	while (cin >> n >> m) {
		// ��ʼ�� 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) graph[i][j] = 1;
				else graph[i][j] = INF;
			}
		}
		while (m--) {
			cin >> ut >> vt >> wt;
			// ȥ�ر� 
			graph[ut][vt] = graph[vt][ut] = dist[ut][vt] = dist[vt][ut] = min(graph[ut][vt], wt);
		}
		
		for (int k = 1; k <= n; k++) {
			// ö��i ~ k, i + 1 ~ k�ıߣ���С���ĳ��Ⱦ���i��j�ľ������ͼ��ͨ��k�ľ���... 
			for (int i = 1; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					ans = min(ans, dist[i][j] + graph[i][k] + graph[k][j]);
				}
			}
			// ������̱ߵľ��� 
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					// ��ֱ�Ӵ�i��j�̻���ͨ��k���� 
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		if (ans == INF) cout << "It's impossible." << endl;
		else cout << ans << endl;	
	}
	return 0;
}

/*
Sample Input
3 3
1 2 1
2 3 1
1 3 1
3 3
1 2 1
1 2 3
2 3 1
 
Sample Output
3
It's impossible.
*/ 
