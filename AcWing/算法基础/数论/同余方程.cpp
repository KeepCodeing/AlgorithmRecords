#include <iostream>
using namespace std;

// 同余就是指a % m == b % m，同余方程是类似ax + ny = b的方程，这种方程可以用扩展欧几里得算法求解，不过要多加一步.. 

/*
蓝桥杯的代码似乎给的有问题，也可能是自己写错了，总之没有测试过，做题炸了... 
*/
// 下面给出题解的扩展欧几里得算法
typedef long long LL;
void exgcd(LL a, LL b, LL&x, LL& y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
} 
int main() {
	LL a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	printf("%lld", (x % b + b) % b);
	return 0;
}
//int exgcd(int a, int b, int& x, int& y) {
//	if (b == 0) {
//		x = 1, y = 0;
//		return a;
//	}
//	int r = exgcd(a % b, b, x, y);
//	int temp = y;
//	y = x + (a / b) * y;
//	x = temp;
//	return r;
//}
//int main() {
// 	int a, b, x, y;
// 	cin >> a >> b;
// 	exgcd(a, b, x, y);
// 	// 在扩展欧几里得算法的基础上的改进，这样就不用非得m是gcd(a, b)的倍数才能获得解了... 
//	x = (x + b) % b;
// 	cout << x <<endl;
// 	return 0;
// }
