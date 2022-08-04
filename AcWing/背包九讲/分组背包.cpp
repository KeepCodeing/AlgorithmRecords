#include <iostream>
using namespace std;

// 分组背包就是将不同的物品分成n组，每组都有若干个物品，我们要从每个组中选出一个元素
// 使其在背包容积内价值最大。

// 其实多重背包就可以看成是一个特殊的分组背包，只不过每一组内的元素都是相同的。

// 分组背包的思路和01背包几乎差不多，这里是对每组物品都求一次最优解，但是代码上分组背包和01背包是反
// 着来的，即01背包先枚举的是物品个数，而分组背包先枚举的是物品代价，同样，变量也得跟着反过来 

// 因为分组背包的特殊性，所以它不能像多重背包那样有各种优化，它只能通过对每组物品求最优解的方式
// 来获得最优解 

const int N = 110;
int f[N];
int val[N], wei[N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		// 输入这组物品的价值 
		for (int j = 1; j <= c; j++) cin >> val[j] >> wei[j];
		for (int j = v; j >= 1; j--) {
			for (int k = 1; k <= c; k++) {
				// 防止越界 
				if (j >= val[k]) f[j] = max(f[j], f[j - val[k]] + wei[k]);
			}
		}
	} 
	cout << f[v];
	return 0;
} 
