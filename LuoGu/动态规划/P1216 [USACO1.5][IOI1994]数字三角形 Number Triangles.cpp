#include <iostream>
#include <cstdio>
using namespace std;

// 其实昨天在vjudge也做了这个题，dp入门题，以前看还是蒙的，完完全全背
// 代码...
// 最后一步：反着走，走到起点的一定只有两个点，子问题就是使得这两个点的
// 和最小
// 因为最后一排元素不存在走过来的点，所以这些点的初始值就是他们自身，计算顺序
// 是从下到上 
// 状态转移方程：f[i][j] = max{f[i + 1][j], f[i + 1][j + 1]} + nums[i][j] 
// 这个题求的最大值，vjudge求的最小值... 

typedef long long LL;
const int N = 1010;
int nums[N][N];
LL f[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &nums[i][j]);
			if (i == n) f[i][j] = nums[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++){
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + nums[i][j];
		}
	}
	// 这里写成了&f[1][1]还找了半天错误.. 
	printf("%d", f[1][1]);
	return 0;
}
