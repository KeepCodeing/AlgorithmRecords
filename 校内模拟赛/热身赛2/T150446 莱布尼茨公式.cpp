#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;

int main() {
	//ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	double res = 0;
	bool flag = true;
	for (int i = 1; i <= 4039; i += 2) {
		if (flag) res += 1.0 / i;
		else res -= 1.0 / i;
		flag = !flag;
	}
	printf("%.6lf", res * 4);
	return 0;
}
