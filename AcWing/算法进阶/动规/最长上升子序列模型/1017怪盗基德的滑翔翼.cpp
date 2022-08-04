#include <iostream>
using namespace std;

// 根据题意来看这个题要求的是最长下降子序列（不是这样哦） 
// 状态集合：从a[j]到a[i]的最长下降子序列
// 属性表示：最大的最长下降子序列的长度
// 状态划分 

// 这个题依然是个最长上升子序列的题目，从题目给的方向来看，有左和右两种走法
// 向左走就是倒着求最长上升自学列，向右走就是正着求最长上升子序列。 

const int N = 110, INF = 1e9;
int nums[N], f[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> nums[i];
		int res = 0;
		// 向右走
		for (int i = 1; i <= n; i++) {
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			res = max(f[i], res);
		}
		// 向左走，倒着求最长上升子序列就行
		for (int i = n; i >= 1; i--) {
			f[i] = 1;
			for (int j = n; j > i; j--) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			res = max(f[i], res);
		}
		cout << res << endl; 
	}
	return 0;
}

/*
3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10

6
6
9
*/
