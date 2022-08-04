#include <iostream>
#include <cstdio>
using namespace std;

// 浮点数二分题目，主要要注意的是精度问题 

int main() {
	double n;
	cin >> n;
	// 这样可以算出-10000≤n≤10000 之间的三次方根 
	double l = -100, r = 100;
	// 解决精度损失的方法：永远都计算比要求精度更高的两位 
	while (r - l > 1e-8) {
		double mid = (l + r) / 2; 
		if (mid * mid *mid >= n) r = mid;
		else l = mid;
	}
	printf("%.6lf", l);
	return 0;
}
