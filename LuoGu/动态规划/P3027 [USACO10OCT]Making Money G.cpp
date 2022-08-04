#include <iostream>
#include <cstdio>
using namespace std;

// 完全背包，在模板上进行了变化 

// 每件物品的代价就是花费，但是价值变成了卖了这个物品的收入-物品花费 
// 也就是说这个题目没有直接给出收益（废话，似乎没有题目背景直白到直接说的w），而且其中的“钱不一定花完”
// 也暗示了f[m]不一定是最优解，不过根据其给出的最大利润公式还是能的大最大利润的.... 

const int N = 100010, M = 110;
int f[N]; 
int val[M], wei[M];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &val[i], &temp);
		// 将物品价值转换 
		wei[i] = temp - val[i];
	}
	// 接下来是套模板
	for (int i = 1; i <= n; i++) {
		for (int j = val[i]; j <= m; j++) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	} 
	// 与普通完全背包不同之处：钱不一定能花完，也就是说f[m]不一定是最大收益
	// 最大收益从题目中可以看出来是利润 = 初始钱数 - 总花费 + 总收入
	int ans = -1;
	// 初始钱数是m，总花费就是i（表示从[1,m]花了多少钱），总收入就是f[i]（表示[1,i]最大的收益） 
	for (int i = 1; i <= m; i++)
		ans = max(ans, m - i + f[i]);
	printf("%d\n", ans);
	return 0;
}
