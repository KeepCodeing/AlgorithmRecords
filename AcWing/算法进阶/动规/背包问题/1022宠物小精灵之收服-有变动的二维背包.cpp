#include <iostream>
using namespace std;
const int N = 2010;
int f[N][N];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int v, d;
		cin >> v >> d;
		for (int j = n; j >= v; j--) {
			for (int t = m; t >= d; t--) {
				// �����̣���Ȼд����v - j��д���� 
				f[j][t] = max(f[j][t], f[j - v][t - d] + 1);
			}
		}
	}
	cout << f[n][m] << ' ';
	int p = m;
	// ������С�������� ���֮�󻨷ѵ���������һ���ģ���ô��һ��
	// ��һ�����������Ѿ�����С���������� 
	while (p > 0 && f[n][p - 1] == f[n][m]) p--;
	cout << m - p;
	return 0;
}
/*
10 100 5
7 10
2 40
2 50
1 20
4 20

3 30
*/
