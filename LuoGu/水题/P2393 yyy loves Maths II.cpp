#include <iostream>
#include <cstdio>
using namespace std;

// 主要是精度问题 

long double sum = .0, num; 
int main() {
	while (cin >> num) {
		// 全都转换为整数 
		sum += num*1000000;
	}
	// 还原小数 
	printf("%.5Lf", sum/1000000);
	return 0;
}
