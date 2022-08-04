#include <iostream>
#define endl '\n'
using namespace std;
const int N = 60;
typedef long long LL;

// 用组合数的定义将原来的分式展开成“先乘后除”的形式，会在n = 62, m = 31时溢出 

// 算出组合数C(n, m)，复杂度O(m) 
LL cal(int n, int m) {
	LL ans = 1;
	for (int i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;
	}
	return ans;
}

// 这种方法可以直接算出整个组合数表，复杂度O(n^2) ，似乎如此？ 
LL res[N][N];
LL cal2(int n, int m) {
	if (m == 0 || m == n) return 1;
	if (res[n][m] != 0) return res[n][m];
	return res[n][m] = cal2(n - 1, m) + cal2(n - 1, m - 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	return 0;
}
