#include <iostream>
#include <vector>
using namespace std;

// 二进制优化版的多重背包大概可以过N = 1000, V = 2000的题目，如果数据更大就得用单调队列优化了 

// 分析下多重背包的特点：某个物品有数量限制。假设一个物品有k个，那么我们可以把它拆分成k份，这样
// 多重背包问题就可以转换为01背包问题了。但是如果一个个拆，时间复杂度其实并没有多大优化，所以这里
// 得用到二进制优化

// 二进制优化的思路：给出一个数，问这个数有多少种组成方法
// 假设这个数是7，而2^3=8，也就是说这个数一共有8种组合方式，但是二进制优化的终点不是有多少种
// 组合方式，而是最少能用多少个数把1~7的数表示出来
// 而多少个数就由2的次数p决定。在这个例子中p = 3，那么就可以有三个数，2^0，2^1,2^2，这三个数（1,2,4）就
// 能表示出1~7之间的所有数也就能将原本复杂度为O(k)的拆分操作优化到O(logk)
// 1 = 1, 2 = 2, 3 = 1 + 2, 4 = 2 + 2, 5 = 1 + 4, 6 = 2 + 4, 7 = 1 + 2 + 4

// 如何转换为01背包问题：将这个物品拆分完了再存起来，然后套01背包模型即可 

// 注意这里的N要设置大一点，因为拆分后的物品可能会变得很多 

const int N = 2010;
struct Good {
	int val, wei;
	Good (int val, int wei) : val(val), wei(wei) {};
};
vector<Good > vec;
int f[N];
int main() {
	int n, v;
	cin >> n >> v;
	int vi, wi, s;
	for (int i = 1; i <= n; i++) {
		cin >> vi >> wi >> s;
		// 将原来要拆分k次的操作优化到logk次 
		for (int k = 1; k <= s; k <<= 1) {
			// 将这些物品拆分成k倍个 
			vec.push_back(Good(vi * k, wi * k)); 
			s -= k;
		}
		// 上面的循环不一定就能把这个物品分完（s是2的倍数时可以），所以还得把剩下的物品
		// 补上 
		if (s > 0) vec.push_back(Good(vi * s, wi * s)); 
	} 
	// 接下来只需要套01背包模板就行，因为这个多重背包问题已经被拆分为一个01背包问题了
	// 注意这里物品的数量已经不再是输入时的了，而是拆分后的 
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = v; j >= vec[i].val; j--) {
			f[j] = max(f[j], f[j - vec[i].val] + vec[i].wei);
		}
	} 
	cout << f[v];
	return 0;
} 
