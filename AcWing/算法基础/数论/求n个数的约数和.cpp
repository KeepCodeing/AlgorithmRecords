#include <iostream>
#include <map>
using namespace std;

// 思路基本和和求约数个数差不多，同样是先算出质因子出现的次数
// 然后再算出底数的质因子数平方加1，

// 符号约定d：底数，a：指数个数，约数和：n 
// 约数之和n = (d^a + 1)*... 

const int mod = 1e9 + 7;
typedef long long LL;
map<int, int > m;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 2; i <= x / i; i++) {
			while (!(x % i)) {
				m[i]++;
				x /= i;
			}
		}
		if (x > 1) m[x]++;
	}
	LL res = 1;
	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++) {
		int p = it->first, a = it->second;
		LL t = 1;
		// 算出这个底数的质因子个数次方 
		while (a--) t = (t * p + 1) % mod;
		// 答案就是各项底数的质因子个数次方只积 
		res *= t % mod;
	}
	cout << res;
	return 0;
}

/*
输入样例
3
2
6
8

输出样例
252
*/ 
