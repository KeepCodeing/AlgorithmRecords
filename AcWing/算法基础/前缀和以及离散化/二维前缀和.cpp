#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1e3 + 10;
int s[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q, x, x1, y1, x2, y2;
	cin >> n >> m >> q;
	// 注意地图从1开始... 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			// 预处理前缀和，i - 1 + i - (i - 1) = i;j + j - 1 - (j - 1) = j
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	}
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		// 先算出整个区域的和，再从对角线开始把里面那块去掉... 
		cout << s[x2][y2] + s[x1 - 1][y1 - 1] - s[x1 - 1][y2] - s[x2][y1 - 1] << endl;
	}
	return 0;
}

/*
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4

17
27
21
*/
