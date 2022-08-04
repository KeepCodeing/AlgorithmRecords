#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// 本来想写二分的，nlogn的复杂度，然而其不知道怎么写>=的二分w，看了题解发现暴力n^2就行... 

const int N = 1e3 + 10;
int f[N], g[N];
int main() {
	int m, n, res = 0x3fffffff;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d", &f[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			res = min(res, abs(f[i] - g[j]));
		}
	}
	printf("%d", res);
	return 0;
}
