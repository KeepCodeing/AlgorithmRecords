#include <iostream>
using namespace std;

// 状态集合：以a[i]为结尾的最长上升子序列的长度
// 状态属性：最大的最长子序列的长度
// 状态划分
// 对于每一位元素，都有从a[k]到a[i]的最长上升子序列长度，另外还有一种特殊情况就是没有a[k]，只有a[i]

// 对于情况一，因为每位元素都必包含a[i]，所以长度就是f(k) + 1，也就是说所有以a[i]结尾的最长上升
// 子序列的长度就是f(k) + 1。而这种情况存在的前提就是a[k] < a[i] 

// 对于第二种情况，该元素只包括自身，所以长度就为1 

// DP写法的时间复杂度在O(n^2)，而贪心写法的复杂度为O(nlogn) 

const int N = 1010;
int a[N], f[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		// 默认子序列的长度为1，也就是子序列不存在 
		f[i] = 1;
		// 求a[k]到a[i]的最长上升子序列的长度 
		for (int k = 1; k < i; k++) {
			// 序列存在的前提是a[k]<a[i]
			if (a[k] < a[i]) {
				// 求以a[i]结尾的最长子序列长度 
				f[i] = max(f[i], f[k] + 1);
			} 
		}
	}
	// 统计最大所有上升子序列的长度
	int res = -1;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	cout << res;
	return 0;
}

/*
输入样例：
7
3 1 2 1 8 5 6

输出样例：
4
*/ 
