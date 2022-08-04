#include <iostream>
using namespace std;
typedef long long LL;
const int N = 250, K = 10;
LL f[N][K];

// 果然是完全背包+二维费用背包求方案数，用dp求的话可以很快求解而且可以
// 用来解数据范围较大的题。

// 这个题和之前做的四方定理那个题很类似，同样是这种类型的背包问题，但是
// 这个题不存在可以选[1,4]之间任意个数的数，这个题规定了只能选k个数，那么
// 把k看成是二维费用，然后套模板就没问题了

// 对于四方定理那个题而言，还有个预处理的过程，最后才计算[1,4]的每种情况...

int main() {
	int n, m;
	cin >> n >> m;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			for (int j = i; j <= n; j++) {
				f[j][k] += f[j - i][k - 1];
			}	
		}
	}
	cout << f[n][m];
	return 0;
}
