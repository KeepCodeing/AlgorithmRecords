#include <iostream>
#include <cstdio>
using namespace std;
int getnum(int x) {
	int tot = 0;
	for (int i = 1; i <= x / i; i++) {
		if (!(x % i)) {
			tot += i;
			if (i != x / i) tot += x / i;
		}
	}
	return tot;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		if ((getnum(a) - a) == b && (getnum(b) - b) == a) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
