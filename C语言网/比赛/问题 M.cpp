#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n >= 50) {
		printf("%.8lf", 0.61803399);
		return 0;
	}
	if (n == 1) {
		printf("%.8lf", 1.0);
		return 0;
	}
	double a = 1, b = 1;
	double t;
	double res = 0;
	for (int i = 2; i <= n; i++) {
		t = a + b;
		a = b;
		b = t;
		res = a / b;
		//printf("%.8lf\n", res);
	}
	printf("%.8lf", res);
	return 0;
}
