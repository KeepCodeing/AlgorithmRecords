#include <iostream>
using namespace std;

// 二维费用背包（01背包） 

// 两个问题：
// 1. time数组似乎和C++里的某个关键字冲突导致了CE，解决方法是尽量避免这样用
// 2. 虽然套了二维费用背包模型，但是发现没有收益这一项，然后看了题解（无能）
// 这样的情况也不是第一次了，还有到题就是把max改为了min，这个题就是把收益设置
// 为1，也就是说不能套模板或者说做题的时候做到模板里没有的东西，要自己根据题意
// 推理出来 

const int N = 210;
int money[N], tm[N]; 
int f[N][N];
int main() {
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) cin >> money[i] >> tm[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= money[i]; j--) {
			for (int k = t; k >= tm[i]; k--) {
				f[j][k] = max(f[j - money[i]][k - tm[i]] + 1, f[j][k]);
			}
		}
	}
	cout << f[m][t];
	return 0;
} 
