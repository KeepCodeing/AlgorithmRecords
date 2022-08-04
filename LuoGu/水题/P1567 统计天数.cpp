#include <iostream>
#include <cstdio>
using namespace std;

// 最长连续上升子序列... 
// 忘得差不多了... 

const int N = 1e6 + 10;
int nums[N], f[N];
int main() {
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		if (nums[i] >= nums[i - 1] && i > 1) f[i] = f[i - 1] + 1, res = max(res, f[i]);
	}
	printf("%d", res);
	return 0;
}
