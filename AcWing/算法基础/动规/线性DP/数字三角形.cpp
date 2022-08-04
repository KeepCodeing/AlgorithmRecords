#include <iostream>
using namespace std;
const int N = 510, INF = 0x3FFFFFFF;
int nums[N][N], f[N][N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> nums[i][j];
		}
	}
	// 初始化状态
	// 注意这里初始化的范围，设置为从0开始以及i+1是因为向左上取和向右上取可能会导致取到多出来的点 
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i + 1; j++) {
			f[i][j] = -INF;
		}
	} 
	// 从第二列开始遍历 
	// 最上面的点没有走法 
	f[1][1] = nums[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j] + nums[i][j], f[i - 1][j - 1] + nums[i][j]);
		} 
	}
	int res = -INF;
	for (int i = 1; i <= n; i++) res = max(f[n][i], res);
	cout << res;
	return 0;
}
