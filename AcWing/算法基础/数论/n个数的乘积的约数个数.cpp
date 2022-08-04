#include <iostream>
#include <map>
using namespace std;

// 给定n个正整数ai，请你输出这些数的乘积的约数个数，答案对10^9+7取模。

// 约数个数定理：对于一个自然数N，可以将其分解成若干个质数的乘积（也就是质因子）
// 而这个自然数N的约数个数就等于每个质因子的个数加一的乘积.
//所以我们可以用一个桶来计数，最后把每个数的质因数个数按照公式求出来就行 

// 6的质因数：2， 3，约数个数：(1 + 1)*(1 + 1) = 4，约数为
// 1, 2, 3, 6 

const int mod = 1e9 + 7;
// 用来计数的桶 
map<int, int > bucket;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		// 分解质因数
		for (int i = 2; i <= x / i; i++) {
			while (!(x % i)) {
				// 统计质因子的个数 
				bucket[i]++;
				x /= i;
			}
		}	
		// 特判最后可能除不掉的质因子
		if (x > 1) bucket[n]++; 
	}
	int ans = 1;
	for (map<int, int >::iterator it = bucket.begin(); it != bucket.end(); it++) {
		ans *= (it->second + 1) % mod;
	}
	cout << ans;
	return 0;
}
/*
输入样例
3
2
6
8

输出样例
12
*/
