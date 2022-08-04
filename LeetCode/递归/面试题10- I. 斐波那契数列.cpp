class Solution {
public:
	int fib(int n) {
		if (n == 0 || n == 1)
			return n;

		int a = 1, b = 0;
		for (int i = 1; i < n; i++) {
			// 这种方法无需额外空间就能计算出fib，似乎是矩阵解法 
			a = a + b;
			b = a - b;
			a %= 1000000007;
		}
		return a;
	}
};
