#include <iostream>
#include <cstdio>
using namespace std;

// 背包复习第二弹，这是个裸的01背包，模板 
// 谔谔，其实是完全背包，题目没说一个题可以无限做... 

const int N = 1e5;
int f[N];
int main() {
	int n, T, v, w;
	scanf("%d%d", &n, &T);
	while (T--) {
		scanf("%d%d", &v, &w);
		for (int i = w; i <= n; i++) f[i] = max(f[i], f[i - w] + v);
	}
	printf("%d", f[n]);
	return 0;
} 
