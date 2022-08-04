#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 数组数组第二弹（上一次的已经坠毁了w），感觉这个题就是求前缀和，然后枚举[i,n]区间的最小值
// 再从前缀和区间减去并求平均值（虚心）..
// 又坠毁了w，最大值最小值并不满足区间加减法，这么看树状数组虽然代码少不过
// 只能适用于单点修改，区间求和的题呢... 

typedef long long LL;
const int N = 100000 + 10;
LL s[N];
int root[N], scores[N];
int n, temp;
int lowbit(int x) {
	return x & (-x);
}
// 求区间最值树状数组，不知道为什么坠毁了... 
void update(int idx) {
	while (idx <= n) {
		root[idx] = scores[idx];
		for (int i = 1; i < lowbit(idx); i <<= 1) root[idx] = min(root[idx], scores[idx - i]);
		idx += lowbit(idx);
	}
}
int query(int x, int y) {
	int ans = 1e9;
	while (y >= x) {
		ans = min(scores[y], ans), y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y)) ans = min(root[y], ans);
	}
	return ans;
}
int main() {
	memset(root, 0x3f, sizeof root);
	scanf("%d", &n);
	s[0] = 0;
	for (int i = 1; i <= n; i++)  {
		scanf("%d", &scores[i]);
		s[i] = s[i - 1] + scores[i];
		update(i);
	}
	for (int i = 1; i <= n - 2; i++) cout << (1, i) << endl;
	return 0;
}
