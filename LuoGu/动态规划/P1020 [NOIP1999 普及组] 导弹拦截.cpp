#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

// 这个题要求一个最长下降子序列和一个最长上升子序列。
// 首先最长不上升子序列数列反着来就成了上升子序列，因此这里只是换了个说法）（是对应题目的最多能拦截多少枚导弹，而最长上升子序列则是因为拦截系统只能从高往低拦截，
// 如果从高到底最多能拦截的已经算出来了，那么剩下来的就是只能增加设备拦截的了... 

const int N = 100000 + 10;
int nums[N], f1[N], f2[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	for (n = 1; cin >> nums[n]; n++);	
	n -= 1;
	// 注意求得是下降型，所以要么把数组反过来，要么把遍历反过来 
//	for (int i = n; i >= 1; i--) {
//		f1[i] = 1;
//		for (int j = i + 1; j <= n; j++) {
//			// 求最长不上升子序列 
//			if (nums[i] >= nums[j]) f1[i] = max(f1[i], f1[j] + 1);
//		}
//	}
	// 求最长上升子序列 
	for (int i = 1; i <= n; i++) {
		f2[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[i] > nums[j]) f2[i] = max(f2[i], f2[j] + 1);
		}
	}
	// 遍历反过来套LIS模板也行，但是注意下标从1开始... 
	reverse(nums + 1, nums + n + 1);
	
	for (int i = 1; i <= n; i++) {
		f1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (nums[i] >= nums[j]) f1[i] = max(f1[i], f1[j] + 1);
		}
	}
	
	int res1 = 0, res2 = 0;
	for (int i = 1; i <= n; i++) {
		res1 = max(res1, f1[i]);
		res2 = max(res2, f2[i]);
	}
	cout << res1 << endl << res2;
	return 0;
}
