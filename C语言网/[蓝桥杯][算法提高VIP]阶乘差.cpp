#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main() {
	LL a, b;
	int m, n, p;
	scanf("%d%d%d", &n, &m, &p);
	a = b = 1;
	for (int i = 2; i <= n; i++) a *= i;
	for (int i = 2; i <= m; i++) b *= i;
	printf("%lld", (a - b) % p);
	return 0;
}
