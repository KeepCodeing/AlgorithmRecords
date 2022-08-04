#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, res = 0, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &t), res += t;
	printf("%d %d", res, res / n);
	return 0;
}
