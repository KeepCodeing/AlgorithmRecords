#include <iostream>
using namespace std;

// 其实完全背包和01背包求方案数在代码上和原来的背包问题差不多
// 只不过是把状态转移方程改为了f[j] += f[j -v[i]]这样 

const int N = 1010;
// 背包容积 
int money[4] = {10, 20, 50, 100};
int f[N];
int main() {
	int n;
	cin >> n;
	// 注意初始化 
	f[0] = 1;
	// 这两层循环套模板就行 
	for (int i = 0; i < 4; i++) {
		for (int j = money[i]; j <= n; j++) {
			// 唯一的不同就是这里，状态转移方程发生了改变
			f[j] += f[j - money[i]]; 
		}
	}
	cout << f[n];
	return 0;
} 
/*
输入样例1：

20
输出样例1：

2
输入样例2：

15
输出样例2：

0
*/
