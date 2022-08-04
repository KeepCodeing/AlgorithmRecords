#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int T, x, y, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &x, &y, &n);
		for (int i = n; i >= 0; i--) {
			if (i % x == y) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
