#include <iostream>
using namespace std;

// 正解是完全背包，大爆搜大概只能枚举出前80个数 

// 背包也忘得差不多了（无能） 

int f[103];
int main() {
	// 数的大小就是背包大小，每个数就是重量
	int n;
	cin >> n;
	fill(f, f + 103, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f[j] += f[j - i];
		}
	}
	cout << f[n];
	return 0;
}
