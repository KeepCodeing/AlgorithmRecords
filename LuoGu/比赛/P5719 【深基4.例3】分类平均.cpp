#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int aCnt = 0, bCnt = 0;
	double a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (i % k) a += i * 10000, aCnt++;
		else b += i * 10000, bCnt++;
	}
	
	printf("%.1lf %.1lf", b / bCnt / 10000, a / aCnt / 10000);
	return 0;
}
