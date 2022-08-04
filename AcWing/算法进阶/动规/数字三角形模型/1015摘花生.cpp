#include <iostream>
using namespace std;

// 状态集合：f[i][j]表示在(i, j)这个位置能获取的最大收益
// 状态属性：max，因为题目要求的是最大收益
// 状态划分：一共有两种状态
// 1. 从上面走过来，对应的状态就是f[i - 1][j] 
// 2. 从左边走过来，对应的状态就是f[i][j - 1]
// 最后的解集就是max{1., 2.}  

const int N = 110;
int graph[N][N], f[N][N]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);  
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> graph[i][j];
			}
		}
		// 状态转移方程
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				// 因为不管怎么走花生都会摘取，所以可以把这个写在max外面
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + graph[i][j];
			}
		}
		cout << f[r][c] << endl;
	}
	return 0;
}
