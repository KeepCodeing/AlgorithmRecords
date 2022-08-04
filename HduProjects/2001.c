#include <stdio.h>
#include <math.h>
int main() {
	int x1, x2, y1, y2;
	double pow_a, pow_b;
	while (1) {
		if (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == EOF) break;
		pow_a = pow(x1 - x2, 2);
		pow_b = pow(y1 - y2, 2);
		printf("%.2f\n",sqrt(pow_a + pow_b));
	}
	return 0;
}
