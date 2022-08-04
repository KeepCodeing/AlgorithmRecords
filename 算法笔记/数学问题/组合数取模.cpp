#include <iostream>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e3 + 10;

// 当组合数的值溢出之后进行求模运算，根据递推式取模就行，这种算法适用于绝大多数情况
 
LL res[N][N];
int p;
LL C(int n, int m) {
	if (m == 0 || m == n) return 1;
	if (res[n][m] != 0) return res[n][m];
	return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % p; 
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> p;
	C(3, 4);
	return 0;
}
