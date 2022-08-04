#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 1000 + 10, M = 25;
LL f[N];
int nums[M];
int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= nums[i]; j--) {
			f[j] += f[j - nums[i]];
		}
	}
	printf("%lld", f[t]);
	return 0;
}
