#include <iostream>
using namespace std;
// 假设小白要上n级台阶，他每次可以上一步，两步，或者三步，问小白一共有多少种
// 方式上完台阶

// 分析：假设上到第n层台阶需要f(n)步，而要计算出f(n)只需要计算出f(n-1),f(n-2),f(n-3)
// 所以递归式如上
int f(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return f(n-1) + f(n - 2) + f(n - 3);
} 
int main() {
	cout << f(4) << endl;
	return 0;
}
