#include <iostream>
#include <cstring>
using namespace std;

// N和M分别表示氧气和氮气的最大值 
const int N = 50, M = 150;

// 动规问题的初始化：
// 一般求最大值的问题默认初始化为0就行，但是求最小值的问题不行
// 因为0可能就是最小值。所以一般把解集全都初始化为INF，再把第一个
// 解集初始化为0 

int f[N][M];
int main() {
	int v, w;
	cin >> v >> w;
	int t;
	cin >> t;
	// 初始化解集 
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	
	for (int q = 1; q <= t; q++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = N - 1; i >= a; i--) {
			for (int j = M - 1; j >= b; j--) {
				f[i][j] = min(f[i][j], f[i - a][j - b] + c);
			}
		}
	}
	// 从所有解集中找到最小花费的方案 
	int res = 1e9;
	for (int i = v; i < N; i++) {
		for (int j = w; j < M; j++) {
			res = min(f[i][j], res);
		}
	}
	cout << res;
	return 0;
} 

/*
输入样例：
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119

输出样例：
249
*/
