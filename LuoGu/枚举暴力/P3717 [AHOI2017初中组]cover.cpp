#include <iostream>
using namespace std;
int graph[105][105];

// ����ģ�⣬Ȼ��Ҫ�ж��³������������о���r��һ�ξ��붼Ҫ�㣬��Ȼ�ᱬ0�����ܣ� 

int main() {
	int n, m, r;
	cin >> n >> m >> r;
	int x, y;
	int nx1, nx2, ny1, ny2;
	while(m--) {
		cin >> x >> y;
		graph[x][y] = 1;
		// ģ���ĸ������̽�⣬�ͺ�DFSһ�� 
		nx1 = nx2 = x, ny1 = ny2 = y;
		for (int i = 1; i <= r; i++) {
			nx1 += 1;
			if (nx1 <= n) graph[nx1][y] = 1;
			else break;
		}
		for (int i = 1; i <= r; i++) {
			nx2 -= 1;
			if (nx2 >= 1) graph[nx2][y] = 1;
			else break;
		}
		for (int i = 1; i <= r; i++) {
			ny1 += 1;
			if (ny1 <= n) graph[x][ny1] = 1;
			else break;
		}
		for (int i = 1; i <= r; i++) {
			ny2 -= 1;
			if (ny2 >= 1) graph[x][ny2] = 1;
			else break;
		}
	}
	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << graph[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += graph[i][j];
		}
	}
	 cout << ans;
	return 0;
}
