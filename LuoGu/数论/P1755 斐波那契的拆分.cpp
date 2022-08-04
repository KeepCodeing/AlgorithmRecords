#include <iostream>
#include <stack>
using namespace std;

// 这个题应该就是倒着遍历，有点像之前的质数拆分的题 
// 主要注意的地方是如何确定斐波那契数列的范围，以及如何保证每次减少的都是最大值 

long long int fib[100] = {1, 1};
stack<long long int > result;
int main() {
	long long int t, x;
	cin >> t;
	// 初始化斐波那契数列，因为其可能会爆int，所以范围要比较小 
	for (int i = 2; i <= 45; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while(t--) {
		cin >> x;
		cout << x << '=';
		// 从后往前选 
		for (int i = 45; i >= 1; i--) {
			// 题目要求尽量输出大的，所以一个数可能会被选多次，而且这里的while也很巧妙，
			// 它可以保证每次减少的都是最大的值 
			while(x >= fib[i]) result.push(fib[i]), x -= fib[i];
			if (x == 0) break; 
		}
		// 输出结果 
		while (!result.empty()) {
			// 最后一个元素后没有加号 
			if (result.size() == 1) {
				cout << result.top() << endl;
				result.pop();
				break;
			}
			cout << result.top() << '+';
			result.pop();
		}
		
	}
	return 0;
}
