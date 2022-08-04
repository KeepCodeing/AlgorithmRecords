#include <iostream>
#include <cstdio>
using namespace std;

// 感觉是个DP题，参考机器人走迷宫那个题，只不过这里二维迷宫换成了一维的..
// 那么对于任意一个点F(i)而言，它只可能是F(i - 1)或F(i - 2)跳过来的，这里
// 它的走法就是F(i - 1) + F(i - 2)，但是又有障碍这个限制...如果参考机器人那个
// 题，有障碍的点走法设置为0就行了..看了下数据范围，也是很有意思，状态方程确实
// 就是裸的斐波那契数列，如果没有一个障碍的话，那么走法在long long之内确实是极限
// 这么多了...（变相想起来要开long long）... 

typedef long long LL;
const int N = 45;
int nums[N];
LL f[N];
int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	// 先建图
	while (m--) {
		scanf("%d", &t);
		nums[t] = -1;
	} 
	// 注意这里其之前写的f[0]也等于1，这是因为其想的是可能F(1)是陷阱，那么如果
	// 只写个F(1)的话可能会出现F(2)没走法的情况，然而题目给的是1不可能有陷阱..
	// 也就是不用考虑这种情况w..另外因为起点从1开始，所以其实到2的走法也只有
	// 一种，那就是跳1步.. 
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (nums[i] == -1) f[i] = 0;
		else f[i] = f[i - 1] + f[i - 2];
	}
	printf("%lld", f[n]);
	return 0;
}
