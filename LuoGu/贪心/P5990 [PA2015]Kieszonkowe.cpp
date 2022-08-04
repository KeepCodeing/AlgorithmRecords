#include <iostream>
#include <cstdio>
using namespace std;

// 思路就是把所有数加起来，判断下是不是偶数，是偶数当前和就是最大的，
// 否则减去一个最小奇数当前和就变成了偶数，也就是答案。 

/*
奇数+奇数=偶数

奇数+偶数=奇数

偶数+偶数=偶数
*/
typedef long long LL;
int main() {
	int n, mNum = 0x3fffffff, t;
	LL res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		res += t;
		if (t % 2) mNum = min(mNum, t);
	}
	if(n == 1 && res % 2) {
		printf("NIESTETY");
		return 0;
	}
	if (res % 2) res -= mNum;
	printf("%d", res);
	return 0;
}
