#include <iostream>
#include <vector>
using namespace std;

// 01背包，价值/代价就是约数值，和普及的几个背包问题差不多，不同的是这个题的题面比较直白... 

// 有够好笑了ww，一直在考虑“选取若干个和不超过S的正整数”是不是要把所有选法都搞出来，然后写了个DFS生成选法ww，结果发现TLE
// 不可避，正解是S是物品个数，约数和是物品价值，i是物品重量，也就是说把从[1,S]的数看成是选数的重量，而不是把约数和看成是重量
// 以及代价... 

const int N = 1010;
int wei[N], f[N];
int getNum(int n) {
	int sn = 0;
	// 试除法求约数都快忘了w 
	for (int i = 2; i <= n / i; i++) {
		if (!(n % i)) {
			sn += i;		
			// 防止重复添加 
			if (n / i != i) sn += n / i; 
		}
	}
	// 注意任何数都有一个公共约数1，这里给出的试除法并不能求出1，所以得加上1，但是1自己不能加上，所以下面初始化的时候要
	// 把1的约数和改为0 
	return sn + 1;
}
int main() {
	int s;
	cin >> s;
	wei[1] = 0;
	for (int i = 2; i <= s; i++) {
		// 处理约数和
		wei[i] = getNum(i); 
	}
	// 套模板
	// 物品个数S个，背包容积为S，物品重量为i，物品价值为i的约数和，和不超过S即S >= i，把i看成重量... 
	for (int i = 1; i <= s; i++) {
		for (int j = s; j >= i; j--) {
			f[j] = max(f[j], f[j - i] + wei[i]);
		}
	} 
	cout << f[s];
	return 0;
} 
