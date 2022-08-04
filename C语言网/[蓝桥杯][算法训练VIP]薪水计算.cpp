#include <iostream>
#include <cstdio>
using namespace std;

// 麻烦的题.. 

int main() {
	int n;
	double m;
	scanf("%d%lf", &n, &m);
	double res = 0;
	// 小于等于40直接乘 
	if (n <= 40) res += n * m;
	// 大于40小于等于50的部分先把40的部分算出来，再把超过40的部分算出来 
	else if (n > 40 && n <= 50) res += (40 * m) + (n - 40) * 1.5 * m;
	// 同上，只不过这里超过40的部分小于等于50的部分是固定的，也就是10.. 
	else res += (40 * m) + 10 * 1.5 * m + (n - 50) * m * 2;
	printf("%.2lf", res);
	return 0;
}
