#include <iostream>
#include <cstdio>
using namespace std;

// 背包fuxi第一弹，这个题就是个二维费用背包，模板 

const int N = 510;
int f[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int T;
	scanf("%d", &T);
	int sz, wei, val;
//	f[0][0] = 0; 计数背包才要初始化，普通背包不用初始化 
	while (T--) {
		// 直接算，这里没必要把重量之类的东西存起来 
		scanf("%d%d%d", &sz, &wei, &val);
		// 这里循环写池沼了，写成了>=1，然后才想起来限制条件... 
		for (int i = n; i >= sz; i--) {
			for (int j = m; j >= wei; j--) {
				f[i][j] = max(f[i][j], f[i - sz][j - wei] + val);
			}
		}
	}
	printf("%d", f[n][m]);
	return 0;
}
