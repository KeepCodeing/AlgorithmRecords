#include <iostream>
using namespace std;

// 发现数据范围很小，暴力枚举就完事了... 

// 超时了...，大概能过前300个数... 

class Solution {
public:
	bool checker(int i) {
		return i != 2 && i != 3 && i != 5;
	}
    int nthUglyNumber(int n) {
    	int cnt = 1, num;
    	bool flag;
    	for (num = 2; cnt < n; num++) {
    		int t = num;
    		flag = true;
			for (int i = 2; i <= t / i; i++) {
				// 这里又写成了if，实际上试除法求约数和求质因数的区别就在这里... 
				while (!(t % i)) {
					if (checker(i)) {
						flag = false;
						break;
					}
					t /= i;
				}
			} 
			if (t > 1 && checker(t)) flag = false; 
			if (flag) cnt++;
		}
		return num - 1;
    }
};
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.nthUglyNumber(n);  
	// 试除法求约数，复杂度O(logn) 
//	for (int i = 2; i <= n / i; i++) {
//		if (!(n % i)) {
//			cout << i << endl;
//			if (n / i != i) cout << n / i << endl;
//		}
//	}
	// if (n > 1) cout << n;
	// 观察数据后发现所谓的因子其实是质因子...，比如8，质因子有2*2*2，而因子有2*4，奇妙深刻...
	// 试除法求质因子
//	for (int i = 2; i <= n / i; i++) {
//		while (!(n % i)) {
//			cout << i << ' ';
//			n /= i;
//		}
//	} 
//	if (n > 1) cout << n << endl;
	return 0;
}
