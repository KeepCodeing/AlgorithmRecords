#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a + b + c) / 2.0;
	double ans = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1f", ans);
	return 0;
}
