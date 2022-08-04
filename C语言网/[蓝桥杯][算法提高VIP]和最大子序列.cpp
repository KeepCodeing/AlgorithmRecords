#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int nums[N], f[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	f[1] = nums[1];
	// 背公式的里技w，最大连续子序列和的定义就是前面的和加上现在这个数能不能比这个数大... 
	for (int i = 2; i <= n; i++) f[i] = max(f[i - 1] + nums[i], nums[i]);
	int res = -0x3fffffff;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	printf("%d", res);
	return 0;
}
