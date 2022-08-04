#include <iostream>
#include <cstdio>
using namespace std;
const int N = 60;
typedef long long LL;
LL res[N];
int main() {
	res[1] = 1, res[2] = 2, res[3] = 3, res[4] = 4;
	for (int i = 5; i < N; i++) res[i] = res[i - 1] + res[i - 3];
	int t;
	while (scanf("%d", &t), t) printf("%d\n", res[t]);
	return 0;
}
