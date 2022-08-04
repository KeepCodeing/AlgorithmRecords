#include <iostream>
using namespace std;

// 01背包求方案数 

const int N = 110;
int f[N];
int main() {
	int n, m;
	cin >> n >> m;
	f[0] = 1;
	// 01背包求方案数：物品容积就是数字个数，背包容积就是要凑的数 
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		for (int j = m; j >= v; j--) f[j] += f[j - v];
	}
	cout << f[m] << endl;
	return 0;
}
/*
输入样例：
4 4
1 1 2 2
输出样例：

3
*/
