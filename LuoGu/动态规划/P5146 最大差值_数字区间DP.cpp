#include <iostream>
#include <cstdio>
using namespace std;

// 设F(i)表示第i个位置的数前所有数的最大差值，那么可以得到F(i) = max{F(i - 1), nums[i] - min[1, i - 1]} 
// 之前想的是直接记录[0, j - 1]的最小值，然后用当前值去减，但是这样能保证和最大吗？答案是不能，考虑这样一个
// 序列1 0 0 0 0，它的最大差值应该是1（如果这个序列是和法的话），但是用上面说的逻辑会得到0，原因就在于我们
// 能保证[1, j - 1]这里的数字最小，但是却无法保证j这个数字最大，所以最好是用一个数组记录之前所有数字减去这个
// 最小值的差值，然后转移到新的位置...这个题实际上没有多想，在本子上手玩了下发现之前的思路是错的就开写了w.. 
// 硬要说的话大概是动规的思想吧，既然保证了f[i - 1]处的答案是最优的，那么f[i]处的答案很容能算出来了... 

const int N = 1e6 + 10;
int nums[N];
int f[N];
int main() {
	int n, mnum;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	// 第一个元素的最大差值就是它本身（不是这样吧？第一个数应该没有最大差值...）最小值也是 
	f[1] = -0x3fffffff, mnum = nums[1];
	for (int i = 2; i <= n; i++) {
		mnum = min(mnum, nums[i - 1]);
		f[i] = max(f[i - 1], nums[i] - mnum);
	}
	// for (int i = 1; i <= n; i++) cout << f[i] << ' ';
	printf("%d", f[n]);
	return 0;
}
