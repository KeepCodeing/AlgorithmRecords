#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			// ������ 
			break;
		}
	}
	return 0;
}
