#include <iostream>
#include <algorithm>
using namespace std;

// 看似是个动规题，但是应该可以用贪心做（坠毁ww，但还是过了几个点，其实数据量不大，可以爆搜，但是没必要） 

// 啊这...就是个换了个样子的01背包罢了，看起来类似有xx上限，要求得最大值的类型的题目都可能是01背包，
// 但是要找对背包，还有物品，这个题money就是背包，因为这个决定了最大价值怎么来的，而物品和其重要性
// 的乘积就是物品 
 
struct elements {
	int value, level;
	int tot;
	bool operator<(const elements& e) {
		return level > e.level;
	}
	elements(int v = 0, int l = 0, int t = 0) {
		value = v, l = level, tot = t;
	}
};


// 这里用了一维数组优化的写法 
int f[50000];
int main() {
	int money, n;
	cin >> money >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].value >> e[i].level;
		// 将物品价值与优先级转换为其乘积 
		e[i].tot = e[i].value * e[i].level;
	}
	// 按着模板写应该就行了 
	for (int i = 1; i <= n; i++) {
		for (int j = money; j >= 0; j--) {
			// 一维数组优化写法：只记录体积，其它似乎没有太大改变 
			// 背包体积：money，背包代价：该物品的价值，背包价值：其优先级和价格的乘积 
			if (j >= e[i].value) {
				f[j] = max(f[j], f[j - e[i].value] + e[i].tot);
			} 
		}
	}
	cout << f[money];
	delete[] e;
	return 0;
}

//int main() {
//	int money, n;
//	long result = 0;
//	cin >> money >> n;
//	elements *e = new elements[n];
//	for (int i = 0; i < n; i++) {
//		cin >> e[i].value >> e[i].level;
//	}
//	sort(e, e + n);
//	for (int i = 0; i < n; i++) {
//		// 先考虑优先级，但是前提是钱够用
//		int tV = e[i].value, tL = e[i].level; 
//		if (money >= tV) {
//			result += tV * tL;
//			money -= tV;
//		} 
//	}
//	cout << result;
//	delete[] e;
//	return 0;
//}
