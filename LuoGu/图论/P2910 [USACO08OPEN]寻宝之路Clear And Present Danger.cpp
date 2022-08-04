#include <iostream>
#include <vector>
using namespace std;

// ���ݷ�Χ100������ζ�����ǿ�����Floyd�󣬶�����Ŀû������ȷ����ʼ�� 

int graph[110][110];
// ����Ҫ�ߵ�����Ĵ�С��С��... 
int must[100010];
int n, m;

int main() {
	cin >> n >> m;
	// int x;
	for (int i = 1; i <= m; i++) cin >> must[i];
	int x; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			graph[i][j] = x;
		}
	}
	// Floyd������ѭ������������м�㣬Ҫ����ľ���min(j~k, j~i + i~k); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// �Լ����Լ��ľ�����0��Ҫ������ 
				if (i != j && i != k && j != k) {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	} 
	int ans = 0;
	for (int i = 2; i <= m; i++) {
		// ����Ҫ�ߵĵ㣬��仰����˼����ǰһ���㵽��һ����ľ����ۼ� 
		ans += graph[must[i - 1]][must[i]];
	}
	cout << ans;
	return 0;
}
