#include <iostream>
using namespace std;

// 和01背包唯一不一样的地方就是j从物品代价开始 

// 01背包：从大到小；完全背包：从小到大； 

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
