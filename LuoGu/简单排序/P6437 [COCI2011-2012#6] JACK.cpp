#include <cstdio>
#include <algorithm>
using namespace std;

// 水题饼干，排序然后从大往下选... 坠毁w，这个题并不是贪心 
// 用二维费用背包写了下，发现并不能很好的解决问题，这个题要求必须选三个
// 数，而二维费用背包是可以选1~k个，也就是不一定选三个... 
// 另外可能要用到离散化，因为数的范围很大...（指用背包）
// 写暴力肯定可以过的... 

const int N = 1e3 + 10;
int nums[N];
int f[N][10];
int main() {
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 3; k++) {
			for (int j = m; j >= nums[i]; j--) {
				// 245 216 36
				// 315 185
				f[j][k] = max(f[j][k], f[j - nums[i]][k - 1] + nums[i]);
			}
		}
		
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	//printf("%d", f[m][3]);
	return 0;
}
