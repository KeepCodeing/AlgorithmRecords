#include <iostream>
using namespace std;

// exgcd算法可以用来求类似ax + by = m的方程，其中当且仅当m % gcd(a, b) == 0该方程才有解，也就是说m必须是a，b最大公约数的倍数，
// 特别的，当m == 1时，a与b都是质数才有解...很多时候我们要的并不是有没有解，而是要的x，y的值...所以就有了裴蜀定理，也就是上面的
// 结论.. 

// 板子.. 
int exgcd(int a, int b, int&x, int& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int r = exgcd(b, a % b, x, y);
	int temp = y;
	y = x - (a / b) * y;
	x = temp;
	return r;
}
int main() {
	
	return 0;
}
