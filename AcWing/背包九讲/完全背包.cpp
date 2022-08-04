#include <iostream>
using namespace std;

// 在01背包的基础上做了扩展，某个物品可以无限选取，在代码上的区别只有第二层循环是从小到大枚举 

const int N = 1010;
int val[N], wei[N], f[N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = val[i]; j <= v; j++) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[v];
	return 0;
}
