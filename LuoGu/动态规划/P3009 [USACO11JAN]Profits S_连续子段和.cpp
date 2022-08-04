#include <iostream>
#include <cstdio>
using namespace std;

// 连续子段和，dp实在奇妙，之前可能是没有想搞的动力，现在想搞了又完全没有切入点... 

const int N = 100000 + 10;
int nums[N];
int f[N];
int main() {
	// 最小值不够小坠毁一次，忘了输出答案坠毁一次w... 
	int n, res = -0x3fffffff;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	f[0] = 0;
	// 公式法w，不过还是可以想到动规式子的，那就是当前元素的前一个位置的最大子段和+当前元素的值是否比当前位置（就是
	// 这个数）的子段和大... 
	for (int i = 1; i <= n; i++) f[i] = max(f[i - 1] + nums[i], nums[i]);
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	cout << res << endl;
	return 0;
}

