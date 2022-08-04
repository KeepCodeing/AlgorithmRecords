#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
int getdeep(int x) {
	int deep = 0;
	// 求当前深度，也就是算当前深度在2的几次方里.. 
	while (x) deep++, x >>= 1;
	return deep;
}
typedef long long LL;
LL res[N];
int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		res[getdeep(i)] += t;
	}	
	// 不知道为什么INT_MIN编译不过.. 
	int ans = 0, mx = -0x3fffffff;
	for (int i = 1; i < N; i++) {
		if (res[i] > mx) mx = res[i], ans = i;
	}
	printf("%d", ans);
	return 0;
}
